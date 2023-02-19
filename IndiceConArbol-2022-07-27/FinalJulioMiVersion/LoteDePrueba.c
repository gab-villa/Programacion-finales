#include "LoteDePrueba.h"

int abrirArchivo(FILE **arch, const char *nomArch, const char *ap)
{
    *arch = fopen(nomArch, ap);
    if(*arch == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo %s en modo %s.",
                nomArch, ap);
        return ERROR_AR;
    }
    return TODO_OK_AR;
}
void crearLoteDePrueba(const char *nomArchPrueba)
{
    FILE *archPrueba;
    if(abrirArchivo(&archPrueba, nomArchPrueba, "wb") == ERROR_AR)
    {
        return;
    }
    tProducto prod[] = {
        {"AAAAA", 'A', 200},
        {"AAAAM", 'M', 400},
        {"AAAAC", 'C', 300},
        {"AAAAB", 'B', 100},
        {"AAAAF", 'F', 400},
        {"AAAAG", 'G', 900},
        {"AAAAH", 'H', 400},
        {"AAAAO", 'A', 200},
        {"AAAAP", 'P', 400},

        {"AAAAQ", 'C', 300},
        {"AAAAR", 'V', 100},
        {"AAAAT", 'F', 400},
        {"AAAAV", 'Z', 900},
        {"AAAAW", 'H', 400},
        {"AAAAZ", 'H', 400}

    };
    fwrite(prod, sizeof(prod), 1, archPrueba);
    fclose(archPrueba);
}
void cargarArbolConPrueba(tArbol *p, const char *nomArchPrueba)
{
    tIndice ind;
    tProducto prod;
    FILE *archPrueba;
    if(abrirArchivo(&archPrueba, nomArchPrueba, "rb") == ERROR_AR)
    {
        return;
    }
    fread(&prod, sizeof(tProducto), 1, archPrueba);
    while(!feof(archPrueba))
    {
        // como el arch esta desordenado, solo le pongo 0 al indice
        // luego se lo cambiara en el nuevo arbol de indice
        crearIndice(&ind, &prod, 0);
        //mostrarIndice(&ind);
        insertarEnArbol(p, &ind, sizeof(tIndice), compIndice);
        fread(&prod, sizeof(tProducto), 1, archPrueba);
    }
    fclose(archPrueba);
}
void vaciarArbolEnIndice(tArbol *p, const char *nomArchIndice)
{
    unsigned i = 0;
    tIndice ind;
    FILE *archIndice;
    if(abrirArchivo(&archIndice, nomArchIndice, "wb") == ERROR_AR)
    {
        return;
    }
    while(sacarEnOrden(p, &ind, sizeof(tIndice)) != ARBOL_VACIO)
    {
        ind.indiceReg = i;
        fwrite(&ind, sizeof(tIndice), 1, archIndice);
        ++i;
    }
    fclose(archIndice);
}
void mostrarArchivoIndice(const char *nomArchIndice)
{
    tIndice ind;
    FILE *archIndice;
    if(abrirArchivo(&archIndice, nomArchIndice, "rb") == ERROR_AR)
    {
        return;
    }
    mostrarIndice(NULL);
    fread(&ind, sizeof(tIndice), 1, archIndice);
    while(!feof(archIndice))
    {
        mostrarIndice(&ind);
        fread(&ind, sizeof(tIndice), 1, archIndice);
    }
    fclose(archIndice);
}

void crearArbolDeIndiceBalanceado(const char *nomArchIndice, tArbol *indice)
{
    int fin;
    tIndice ind;
    FILE *archIndice;
    if(abrirArchivo(&archIndice, nomArchIndice, "rb") == ERROR_AR)
    {
        return;
    }
    fseek(archIndice, 0L, SEEK_END);
    fseek(archIndice, -1L*sizeof(tIndice), SEEK_CUR);
    fread(&ind, sizeof(tIndice), 1, archIndice);
    fin = ind.indiceReg;

    cargarIndiceEnArbolRec(indice, archIndice, 0, fin);

    fclose(archIndice);
}
void cargarIndiceEnArbolRec(tArbol *indice, FILE *archIndice, int li, int ld)
{
    if(li > ld)
    {
        return;
    }
    int med = (li + ld) / 2;
    tIndice ind;
    fseek(archIndice, med * sizeof(tIndice), SEEK_SET);
    fread(&ind, sizeof(tIndice), 1, archIndice);

    //insertarEnArbol2(&(*indice), &ind, sizeof(tIndice), compIndice);
    insertarEnArbol(indice, &ind, sizeof(tIndice), compIndice);

    cargarIndiceEnArbolRec(&(*indice)->izq, archIndice, li, med-1);
    cargarIndiceEnArbolRec(&(*indice)->der, archIndice, med+1, ld);
}
void mostrarIndiceConForma(const void *v, unsigned n)
{
    const tIndice *ind = (const tIndice*)v;
    if(ind == NULL)
    {
        printf("IND TIPO COD\n");
    }
    else
    {
        printf("%*s",n*5,"");
        printf("%-3u%-3c%-5s\n", ind->indiceReg,
               ind->clave.tipo, ind->clave.cod);
    }
}
void mostrarIndice(const void *v)
{
    const tIndice *ind = (const tIndice*)v;

    if(ind == NULL)
    {
        printf("IND TIPO COD\n");
    }
    else
    {
        printf("%-3u%-3c%-5s\n", ind->indiceReg,
               ind->clave.tipo, ind->clave.cod);
    }
}
void crearIndice(tIndice *ind, const tProducto *prod, unsigned indiceReg)
{
    ind->clave.tipo = prod->tipo;
    strcpy(ind->clave.cod, prod->cod);
    ind->indiceReg = indiceReg;
}
int compIndice(const void *v1, const void *v2)
{
    const tIndice *i1 = (const tIndice*)v1;
    const tIndice *i2 = (const tIndice*)v2;
    if(i1->clave.tipo == i2->clave.tipo)
    {
        return strcmp(i1->clave.cod, i2->clave.cod);
    }
    else if(i1->clave.tipo < i2->clave.tipo)
    {
        return -1;
    }
    return 1;
}
