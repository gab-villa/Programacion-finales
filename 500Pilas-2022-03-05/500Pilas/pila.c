#include "pila.h"

void crearPila(tPila *p)
{
    *p = NULL;
}
int pilaVacia(const tPila *p)
{
    return *p == NULL;
}
int ponerEnPila(tPila *p, const void *d, unsigned cantBytes)
{
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(nue == NULL)
    {
        return SIN_MEM;
    }
    nue->info = malloc(cantBytes);
    if(nue->info == NULL)
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;

    nue->sig = *p;
    *p = nue;
    return TODO_OK;
}
int sacarDePila(tPila *p, void *d, unsigned cantBytes)
{
    tNodo *aux = *p;
    if(aux == NULL)
    {
        return PILA_VACIA;
    }
    memcpy(d, aux->info, minimo(cantBytes, aux->tamInfo));

    *p = aux->sig;
    free(aux->info);
    free(aux);
    return TODO_OK;
}
void vaciarPila(tPila *p)
{
    tNodo *aux;
    while(*p)
    {
        aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}
