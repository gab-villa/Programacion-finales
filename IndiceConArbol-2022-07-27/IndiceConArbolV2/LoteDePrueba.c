#include "LoteDePrueba.h"

int abrirArchivo(FILE **arch, const char *nomArch, const char *ap)
{
    *arch = fopen(nomArch, ap);
    if(*arch == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo %s en modo %s",
                nomArch, ap);
        return ARCH_ERROR;
    }
    return ARCH_OK;
}
void crearLoteDePrueba(const char *nomArch)
{
    FILE *archPrueba;
    if(abrirArchivo(&archPrueba, nomArch, "wb") == ARCH_ERROR)
    {
        return;
    }
    tProd productos[] = {
        {"AAAAA", 'A', 100},
        {"AAAAA", 'B', 100},
        {"AAAAC", 'B', 100},
        {"AAAAD", 'B', 100},
        {"AAAAE", 'A', 100},
        {"AAAAF", 'B', 100},
        {"AAAAG", 'A', 100},
        {"AAAAG", 'C', 100},
        {"AAAAI", 'A', 100},
        {"AAAAI", 'C', 100},
        {"AAAAK", 'A', 100}
    };
    fwrite(productos, sizeof(productos), 1, archPrueba);
    fclose(archPrueba);
}
void insertarArchivoDesordenadoEnArbol(const char *nomArch, tArbol *ar)
{
    tIndice ind;
    tProd prod;
    FILE *archDesord;
    if(abrirArchivo(&archDesord, nomArch, "rb") == ARCH_ERROR)
    {
        return;
    }
    fread(&prod, sizeof(tProd), 1, archDesord);
    while(!feof(archDesord))
    {
        copiarProdEnInd(&ind, &prod);
        insertarEnArbol(ar, &ind, sizeof(tIndice), compIndPorCod);
        fread(&prod, sizeof(tProd), 1, archDesord);

    }
    fclose(archDesord);
}
void vaciarArbolEnArchIndiceEnOrd(const char *nomArchInd, tArbol *ar)
{
    FILE *archInd;
    if(abrirArchivo(&archInd, nomArchInd, "wb") == ARCH_ERROR)
    {
        return;
    }
    copiarArbolEnDataSetEnOrden(ar, archInd, copiarInd);
    vaciarArbol(ar);
    fclose(archInd);
}
void insertarArchIndEnArbol(const char *nomArchInd, tArbol *ar)
{
    long fin;
    FILE *archInd;
    if(abrirArchivo(&archInd, nomArchInd, "rb") == ARCH_ERROR)
    {
        return;
    }
    fseek(archInd, 0L, SEEK_END);
    fin = ftell(archInd);
    fin /= sizeof(tIndice);
    fin--;
    rewind(archInd);

    insertarArchOrdenadoEnArbolBal(ar, archInd, sizeof(tIndice), leerInd,
                                   0, fin);
    fclose(archInd);
}
void copiarArbolEnArchIndicePreOrd(const char *nomArchInd, tArbol *ar)
{
    FILE *archInd;
    if(abrirArchivo(&archInd, nomArchInd, "wb") == ARCH_ERROR)
    {
        return;
    }
    copiarArbolEnDataSetPreOrden(ar, archInd, copiarInd);
    //vaciarArbol(ar);
    fclose(archInd);
}
int regenerarArbolConIndice(const char *nomArchInd, tArbol *ar)
{
    tIndice ind;
    FILE *archInd;


    if(abrirArchivo(&archInd, nomArchInd, "rb") == ARCH_ERROR)
    {
        printf("\n\n");
        printf("NO SE PUDO REGENERAR EL ARBOL...\n");
        printf("GENERANDO NUEVO ARBOL A PARTIR DEL LOTE DE PRUEBA...\n");
        printf("\n\n");
        return ARCH_ERROR;
    }
    printf("\n\n");
    printf("INDICE ENCONTRADO, REGENERANDO ARBOL...\n");
    fread(&ind, sizeof(tIndice), 1, archInd);
    while(!feof(archInd))
    {
        insertarEnArbol(ar, &ind, sizeof(tIndice), compIndPorCod);
        fread(&ind, sizeof(tIndice), 1, archInd);
    }
    printf("EXITO!\n");
    printf("\n\n");
    return ARCH_OK;
}
void mostrarArchInd(const char *nomArchInd)
{
    tIndice ind;
    FILE *archInd;
    if(abrirArchivo(&archInd, nomArchInd, "rb") == ARCH_ERROR)
    {
        return;
    }
    mostrarInd2(NULL);
    fread(&ind, sizeof(tIndice), 1, archInd);
    while(!feof(archInd))
    {
        mostrarInd2(&ind);
        fread(&ind, sizeof(tIndice), 1, archInd);
    }
    fclose(archInd);
}
