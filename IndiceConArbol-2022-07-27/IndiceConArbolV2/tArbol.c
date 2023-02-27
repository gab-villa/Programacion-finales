#include "tArbol.h"

void crearArbol(tArbol *ar)
{
    *ar = NULL;
}
void vaciarArbol(tArbol *ar)
{
    if(*ar == NULL)
    {
        return;
    }
    vaciarArbol(&(*ar)->izq);
    vaciarArbol(&(*ar)->der);

    free((*ar)->info);
    free(*ar);
    *ar = NULL;
}
void mostrarArbolHorizontal(const tArbol* ar,
                            void (*mostrar)(const void *, int))
{
    mostrarArbolHorizontalProc(ar, mostrar, 0);
}
void mostrarArbolHorizontalProc(const tArbol* ar,
                            void (*mostrar)(const void *, int), int n)
{
    if(*ar == NULL)
    {
        return;
    }
    mostrarArbolHorizontalProc(&(*ar)->der, mostrar, n+1);
    mostrar((*ar)->info, n);
    mostrarArbolHorizontalProc(&(*ar)->izq, mostrar, n+1);
}
int insertarEnArbol(tArbol *ar, const void *d, unsigned cantBytes,
                    int (*comp)(const void *, const void *))
{
    if(*ar)
    {
        if(comp(d, (*ar)->info) < 0)
        {
            return insertarEnArbol(&(*ar)->izq, d, cantBytes, comp);
        }
        else if(comp(d, (*ar)->info) > 0)
        {
            return insertarEnArbol(&(*ar)->der, d, cantBytes, comp);
        }
        else
        {
            return ARBOLITO_CLADUP;
        }
    }
    tNodoArbol* nue;
    if((nue = (tNodoArbol*)malloc(sizeof(tNodoArbol))) == NULL ||
        (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return ARBOLITO_SINMEM;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->izq = nue->der = NULL;
    *ar = nue;
    return ARBOLITO_OK;
}
void copiarArbolEnDataSetEnOrden(tArbol *ar, void *ds,
                                void (*copiar)(void *, const void *))
{
    if(*ar == NULL)
    {
        return;
    }
    copiarArbolEnDataSetEnOrden(&(*ar)->izq, ds, copiar);
    copiar(ds, (*ar)->info);
    copiarArbolEnDataSetEnOrden(&(*ar)->der, ds, copiar);
}
int insertarArchOrdenadoEnArbolBal(tArbol *ar, const void *ds,
                                  unsigned tamReg,
                                  void (*leer)(const void *, void *, int),
                                  int li, int ld)
{
    tNodoArbol *nue;
    int ret, med = (li + ld) / 2;
    if(li > ld)
    {
        return ARBOLITO_OK;
    }

    if((nue = (tNodoArbol*)malloc(sizeof(tNodoArbol))) == NULL ||
       (nue->info = malloc(tamReg)) == NULL)
    {
        free(nue);
        return ARBOLITO_SINMEM;
    }
    nue->tamInfo = tamReg;
    nue->izq = nue->der = NULL;
    leer(ds, nue->info, med);
    *ar = nue;
    ret = insertarArchOrdenadoEnArbolBal(&(*ar)->izq, ds, tamReg, leer,
                                         li, med-1);
    if(ret != ARBOLITO_OK)
    {
        return ret;
    }
    return insertarArchOrdenadoEnArbolBal(&(*ar)->der, ds, tamReg, leer,
                                          med+1, ld);
}
void copiarArbolEnDataSetPreOrden(tArbol *ar, void *ds,
                                  void (*copiar)(void *, const void *))
{
    if(*ar == NULL)
    {
        return;
    }
    copiar(ds, (*ar)->info);
    copiarArbolEnDataSetPreOrden(&(*ar)->izq, ds, copiar);
    copiarArbolEnDataSetPreOrden(&(*ar)->der, ds, copiar);
}

