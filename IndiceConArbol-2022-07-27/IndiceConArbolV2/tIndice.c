#include "tIndice.h"

void copiarProdEnInd(void *vInd, const void *vProd)
{
    tIndice *ind = (tIndice*)vInd;
    const tProd *prod = (const tProd*)vProd;
    strcpy(ind->cla.cod, prod->cod);
    ind->cla.tipo = prod->tipo;
    ind->numInd = 0; //no se sabe asi que se deja en 0
}
void copiarInd(void *ds, const void *info)
{
    FILE *archInd = (FILE*)ds;
    //const tIndice *ind = (const tIndice*)info;
    fwrite(info, sizeof(tIndice), 1, archInd);
}
void leerInd(const void *ds, void *info, int numInd)
{
    FILE *archInd = (FILE*)ds;
    tIndice *ind = (tIndice*)info;
    fseek(archInd, sizeof(tIndice) * numInd, SEEK_SET);
    fread(ind, sizeof(tIndice), 1, archInd);
    ind->numInd = numInd;
}
void mostrarInd(const void *vInd, int nivel)
{
    const tIndice *ind = (const tIndice*)vInd;
    printf("%*c",nivel * 5, '\0');
    printf("%-7s%-5s\n", "COD", "TIPO");
    printf("%*c",nivel * 5, '\0');
    printf("%-7s%-5c\n", ind->cla.cod, ind->cla.tipo);
}
void mostrarInd2(const void *vInd)
{
    const tIndice *ind = (const tIndice*)vInd;
    if(ind == NULL)
    {
        printf("%-7s%-5s\n", "COD", "TIPO");
    }
    else
    {
        printf("%-7s%-5c\n", ind->cla.cod, ind->cla.tipo);
    }
}
int compIndPorCod(const void *v1, const void *v2)
{
    const tIndice *ind1 = (const tIndice*)v1;
    const tIndice *ind2 = (const tIndice*)v2;

    int cmpCod = strcmp(ind1->cla.cod, ind2->cla.cod);
    if(cmpCod == 0)
    {
        return ind1->cla.tipo - ind2->cla.tipo;
    }
    return cmpCod;
}
