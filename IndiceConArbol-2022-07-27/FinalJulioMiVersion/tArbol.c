#include "tArbol.h"

void crearArbol(tArbol *p)
{
    *p = NULL;
}
int insertarEnArbol(tArbol *p, const void *d, unsigned cantBytes,
                    int (*comp)(const void *, const void *))
{
    if(*p)
    {
        int c = comp(d, (*p)->info);
        if(c < 0)
        {
            return insertarEnArbol(&(*p)->izq, d, cantBytes, comp);
        }
        else if(c > 0)
        {
            return insertarEnArbol(&(*p)->der, d, cantBytes, comp);
        }
        else
        {
            return CLA_DUP_AR;
        }
    }
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(nue == NULL)
        return SIN_MEM_AR;
    nue->info = malloc(cantBytes);
    if(nue->info == NULL)
    {
        free(nue);
        return SIN_MEM_AR;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->izq = NULL;
    nue->der = NULL;
    *p = nue;
    return TODO_OK_AR;
}
/*
int insertarEnArbol2(tArbol *p, const void *d, unsigned cantBytes,
                    int (*comp)(const void *, const void *))
{
    if(*p)
    {
        int c = comp(d, (*p)->info);
        if(c < 0)
        {
            return insertarEnArbol(&(*p)->izq, d, cantBytes, comp);
        }
        else if(c > 0)
        {
            return insertarEnArbol(&(*p)->der, d, cantBytes, comp);
        }
        else
        {
            return CLA_DUP_AR;
        }
    }
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(nue == NULL)
        return SIN_MEM_AR;
    nue->info = malloc(cantBytes);
    if(nue->info == NULL)
    {
        free(nue);
        return SIN_MEM_AR;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->izq = NULL;
    nue->der = NULL;
    *p = nue;
    return TODO_OK_AR;
}*/
int sacarEnOrden(tArbol *p, void *d, unsigned cantBytes)
{
    if(*p == NULL)
        return ARBOL_VACIO;
    // ya se sabe que la izq es nulo
    if(sacarEnOrden(&(*p)->izq, d, cantBytes) == ARBOL_VACIO)
    {
        tNodo *aux = *p;
        memcpy(d, aux->info, minimo(cantBytes, aux->tamInfo));
        *p = aux->der;
        free(aux->info);
        free(aux);
    }
    return TODO_OK_AR;
}
void mostrarArbolEnOrden(const tArbol *p, void (*mostrar)(const void *))
{
    if(*p == NULL)
    {
        return;
    }
    //printf("   ");
    mostrarArbolEnOrden(&(*p)->izq, mostrar);
    mostrar((*p)->info);
    mostrarArbolEnOrden(&(*p)->der, mostrar);
}
void mostrarHijos(const tArbol *p, void (*mostrar)(const void *))
{
    if(*p == NULL)
    {
        return;
    }
    mostrarHijos(&(*p)->izq, mostrar);
    mostrarHijos(&(*p)->der, mostrar);
    if((*p)->izq == NULL && (*p)->der == NULL)
    {
        mostrar((*p)->info);
    }
}
/*
void mostrarArbolGraficoAux(const tArbol *p, int i,void (*mostrar)(const void *, unsigned))
{

    if(*p == NULL)
    {
        return;
    }
    mostrarArbolGraficoAux(&(*p)->izq, i+1, mostrar);
    int aux = i;
    while(aux > 0)
    {
        printf("\t");
        --aux;
    }
    mostrar((*p)->info);
    mostrarArbolGraficoAux(&(*p)->der, i+1,  mostrar);
}
void mostrarArbolGrafico(const tArbol *p, void (*mostrar)(const void *))
{

    if(*p == NULL)
    {
        return;
    }
    mostrarArbolGraficoAux(p, 0, mostrar);
    //mostrarArbolGraficoProc(p, 0, mostrar);
}*/
void mostrarArbolGrafico2(const tArbol *p,
                          void (*mostrar)(const void *, unsigned))
{
    mostrarArbolGraficoProc(p, 0, mostrar);
}
void mostrarArbolGraficoProc(const tArbol *p, unsigned n,
                             void (*mostrar)(const void *, unsigned))
{
    if(*p == NULL)
    {
        return;
    }
    mostrarArbolGraficoProc(&(*p)->izq, n+1, mostrar);
    mostrar((*p)->info, n);
    mostrarArbolGraficoProc(&(*p)->der, n+1, mostrar);
}
int alturaArbol(const tArbol *p)
{
    if(*p == NULL)
    {
        return 0;
    }
    int li, ld;
    li = alturaArbol(&(*p)->izq);
    ld = alturaArbol(&(*p)->der);
    return li > ld ? li + 1: ld + 1;
}
void vaciarArbol(tArbol *p)
{
    if(*p == NULL)
    {
        return;
    }
    vaciarArbol(&(*p)->izq);
    vaciarArbol(&(*p)->der);
    free((*p)->info);
    free(*p);
    *p = NULL;
}
