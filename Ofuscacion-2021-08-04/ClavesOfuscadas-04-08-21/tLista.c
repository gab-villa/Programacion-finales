#include "tLista.h"

void crearLista(tLista* ls)
{
    *ls = NULL;
}
int listaVacia(const tLista *ls)
{
    return *ls == NULL;
}
int insertarAlFinal(tLista *ls, const void *d, unsigned cantBytes)
{
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    if(nue == NULL)
    {
        return LS_SINMEM;
    }
    nue->info = malloc(cantBytes);
    if(nue->info == NULL)
    {
        free(nue);
        return  LS_SINMEM;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;
    while(*ls)
    {
        ls = &(*ls)->sig;
    }
    *ls = nue;
    return LS_OK;
}
int verUltimo(tLista *ls, void *d, unsigned cantBytes)
{
    if(*ls == NULL)
    {
        return LS_VACIA;
    }
    memcpy(d, (*ls)->info, minimo((*ls)->tamInfo, cantBytes));
    return LS_OK;
}
int sacarPrimero(tLista *ls, void *d, unsigned cantBytes)
{
    tNodo* aux = *ls;
    if(*ls == NULL)
    {
        return LS_VACIA;
    }
    memcpy(d, aux->info, minimo(aux->tamInfo, cantBytes));
    *ls = aux->sig;
    free(aux->info);
    free(aux);
    return LS_OK;
}
void eliminarOcurrenciasPares(tLista *ls,
                              int (*comp)(const void *, const void *))
{
    tLista *ant = ls;
    tNodo *aux = *ls, *aux2;

    if(comp((*ls)->info, (*ls)->sig->info) == 0)
    {
        aux = *ls;
        aux2 = aux->sig;
        *ls = aux2->sig;

        free(aux->info);
        free(aux);
        free(aux2->info);
        free(aux2);
    }
    ls = &(*ls)->sig;

    while(*ls == NULL || (*ls)->sig == NULL)
    {
        if(comp((*ls)->info, (*ls)->sig->info) == 0)
        {
            aux = *ls;
            aux2 = aux->sig;
            //ant->sig = aux2->sig;
            *ls = aux2->sig;
            ls = ant;

            free(aux->info);
            free(aux);
            free(aux2->info);
            free(aux2);
        }
        else
        {
            ant = ls;
        }
        ls = &(*ls)->sig;

    }
}

void vaciarLista(tLista *ls)
{
    tNodo* aux = *ls;
    while(*ls)
    {
        aux = *ls;
        *ls = aux->sig;
        free(aux->info);
        free(aux);
    }
}
