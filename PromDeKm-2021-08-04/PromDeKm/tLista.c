#include "tLista.h"

void crearLista(tLista *ls)
{
    *ls = NULL;
}
//int insertarAlFinal(tLista *ls, const void *d, unsigned cantBytes);
int sacarPrimero(tLista *ls, void *d, unsigned cantBytes)
{
    tNodo* aux = *ls;
    if(aux == NULL)
    {
        return LS_VACIA;
    }
    memcpy(d, aux->info, minimo(cantBytes, aux->tamInfo));
    *ls = aux->sig;
    free(aux->info);
    free(aux);
    return LS_OK;
}
void vaciarLista(tLista *ls)
{
    tNodo* aux;
    while(*ls)
    {
        aux = *ls;
        *ls = aux->sig;
        free(aux->info);
        free(aux);
    }
}

int ponerEnOrden(tLista *ls, const void *d, unsigned cantBytes,
                 int (*comp)(const void *, const void *),
                 void (*acum)(void *, const void *))
{
    while(*ls && comp(d, (*ls)->info) > 0)
    {
        ls = &(*ls)->sig;
    }
    if(*ls && comp(d, (*ls)->info) == 0)
    {
        if(acum)
        {
            acum((*ls)->info, d);
        }
        return LS_CLADUP;
    }

    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(nue == NULL)
    {
        return LS_SINMEM;
    }
    nue->info = malloc(cantBytes);
    if(nue->info == NULL)
    {
        free(nue);
        return LS_SINMEM;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;

    nue->sig = *ls;
    *ls = nue;

    return LS_OK;
}
void sacarPromDeListaOrd(tLista *ls, int (*comp)(const void *, const void *),
                        void (*acum)(void *, const void *),
                        void (*sacarProm)(void *, unsigned))
{
    tLista *sig = ls;
    tNodo *aux;
    unsigned cantDup = 1;
    /*
    if(*ls == NULL)
    {
        return LS_VACIA;
    }*/
    while(*ls)
    {
        sig = &(*ls)->sig;
        while(*sig && comp((*ls)->info, (*sig)->info) == 0)
        {
            ++cantDup;
            acum((*ls)->info, (*sig)->info);

            aux = *sig;
            *sig = aux->sig;
            free(aux->info);
            free(aux);
        }
        if(cantDup > 1)
        {
            sacarProm((*ls)->info, cantDup);
        }
        cantDup = 1;

        ls = &(*sig);
        //(*ls)->sig = sig;

    }
}
void mostrarLista2(const tLista *ls, void ((*mostrar)(const void *)))
{
    tNodo *aux = *ls;
    while(aux)
    {
        mostrar(aux->info);
        aux = aux->sig;
    }
}
void mostrarLista(const tLista *ls, void (*mostrar)(const void *))
{
    while(*ls)
    {
        mostrar((*ls)->info);
        ls = &(*ls)->sig;
    }
}
