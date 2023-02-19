#include "matrizDispersa.h"


int crearMatrizRala(tMatrizRala *mr, unsigned tamFila)
{
    unsigned i = 0;
    mr->fLis = (tLista*)malloc(sizeof(tLista) * tamFila);
    if(mr->fLis == NULL)
    {
        return 0;
    }
    for(i = 0;i < tamFila;++i)
    {
        crearLista(&mr->fLis[i]);
    }
    mr->tamFila = tamFila;
    return 1;
}
void vaciarMatrizRala(tMatrizRala *mr)
{
    int i;
    for(i = 0;i < mr->tamFila;++i)
    {
        vaciarLista(&mr->fLis[i]);
    }
    mr->tamFila = 0;
}
int cargarMatrizRala(const char *nomArch, tMatrizRala *mr)
{
    int tamFila, tamCol;
    tFila fila;
    FILE *archMatriz;
    char reg[TAM_REG];
    if(abrirArchivo(&archMatriz, nomArch, "rt" ) == ERROR)
    {
        return ERROR;
    }
    if(fgets(reg, TAM_REG, archMatriz))
    {
        parsearTam(reg, &tamFila, &tamCol);
        while(fgets(reg, TAM_REG, archMatriz))
        {
            parsearReg(reg, &fila);
           ponerEnOrdenAcum(&mr->fLis[fila.fila], &fila.c, sizeof(tCol),
                         compCol, NULL);
        }
    }

    fclose(archMatriz);
    return 1;
}

tFila maxDP_mat_rala(tMatrizRala *mr)
{
    tCol aux;
    tFila max = {-1, {-1,-1}};
    /*
    max.c.col = 0;
    max.c.val = 0;
    max.fila = -1;*/
    int i;
    for(i = 0;i < mr->tamFila;++i)
    {
        aux.col = i;
        aux.val = 0;
        if(buscarPorClaveEnListaOrd(&mr->fLis[i], &aux, sizeof(tCol),
                                    compCol, actMax))
        {
            if(max.c.val < aux.val)
            {
                max.c.val = aux.val;
                max.c.col = aux.col;
                max.fila = i;
            }
        }
    }
    return max;
}
int actMax(void **vMax, unsigned *vSize, const void *vinfo, unsigned tamInfo)
{
    tCol **cla = (tCol**)vMax;
    tCol *info = (tCol*)vinfo;

    //nuevo maximo
    (*cla)->val = info->val;
    return 1;
}
void imprimirMatRala(const tMatrizRala *mr)
{
    int i;
    int ini = 0;
    for(i = 0;i < mr->tamFila;++i)
    {
        if(!listaVacia(&mr->fLis[i]))
        {
            recorrerListaConCeros(&mr->fLis[i], mr->tamFila,
                              ponerCeros, ponerRestante);

        }
        else
        {
            ponerRestante(&ini, mr->tamFila);
            ini = 0;
        }
        printf("\n");
    }
}
void imprimirMatRala2(const tMatrizRala *mr)
{
    //tCol col;
    int i;
    for(i = 0;i < mr->tamFila;++i)
    {

        printf("FILA %d: ",i);
        recorrerLista(&mr->fLis[i], mostrarElemMatriz);
        /*
        while(sacarPrimeroLista(&mr->fLis[i], &col, sizeof(tCol)))
        {
            mostrarElemMatriz(&col, i);
        }*/

    }
}
void ponerRestante(int *ini, int fin)
{
    while(*ini < fin)
    {
        printf("0 ");
        ++(*ini);
    }
}
void ponerCeros(const void *vElem, int *ini, int fin)
{
    tCol *col = (tCol*)vElem;
    while(*ini < fin && *ini < col->col)
    {
        printf("0 ");
        *ini += 1;
    }
    if(*ini == col->col)
    {
        mostrarValorMatriz(vElem);
        *ini += 1;
    }
}
void mostrarValorMatriz(const void *vElem)
{
    tCol *col = (tCol*)vElem;
    printf("%d ", col->val);
}
void mostrarElemMatriz(const void *vElem)
{
    tCol *col = (tCol*)vElem;
    printf("%-2d%-2d - ", col->col, col->val);
}
int compCol(const void *v1, const void *v2)
{
    tCol *c1 = (tCol*)v1;
    tCol *c2 = (tCol*)v2;

    if(c1->col < c2->col)
    {
        return -1;
    }
    else if(c1->col == c2->col)
    {
        return 0;
    }
    return 1;
}

