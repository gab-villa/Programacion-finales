#include "tCola.h"

void crearCola(tCola *c)
{
    *c = NULL;
}
int insertarEnCola(tCola *c, const void *d, unsigned cantBytes)
{
    tNodo *nue;
    if((nue = (tNodo*)malloc(sizeof(tNodo))) == NULL ||
        (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return COLA_SINMEM;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;

    if(*c == NULL)
    {
        nue->sig = nue;
    }
    else
    {
        nue->sig = (*c)->sig;
        (*c)->sig = nue;
    }
    *c = nue;
    return COLA_OK;
}
int sacarDeCola(tCola *c, void *d, unsigned cantBytes)
{
    tNodo *aux;
    if(*c == NULL)
    {
        return COLA_VACIA;
    }
    aux = (*c)->sig;
    memcpy(d, aux->info, minimo(cantBytes, (*c)->tamInfo));

    if(aux == *c)
    {
        *c = NULL;
    }
    else
    {
        (*c)->sig = aux->sig;
    }
    free(aux->info);
    free(aux);
    return COLA_OK;
}
void vaciarCola(tCola *c)
{
    tNodo *aux;
    if(*c == NULL)
    {
        return;
    }
    aux = (*c)->sig;
    while(aux != *c)
    {
        (*c)->sig = aux->sig;
        free(aux->info);
        free(aux);
    }
    free(aux->info);
    free(aux);
    *c = NULL;
}
