#include "tPila.h"

void crearPila(tPila *p)
{
    *p = NULL;
}
int pilaVacia(const tPila *p)
{
    return *p == NULL;
}

int insertarEnPila(tPila *p, const void *d, unsigned cantBytes)
{
    tNodoPila *nue = (tNodoPila*)malloc(sizeof(tNodoPila));
    if(nue == NULL)
        return PI_SINMEM;
    nue->info = malloc(cantBytes);
    if(nue->info == NULL)
    {
        free(nue);
        return PI_SINMEM;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return PI_OK;
}
int eliminarDePila(tPila *p)
{
    tNodoPila *aux;
    if(*p == NULL)
    {
        return PI_VACIA;
    }
    aux = *p;
    *p = aux->sig;
    free(aux->info);
    free(aux);
    return PI_OK;
}
int verTope(const tPila *p, void *d, unsigned cantBytes)
{
    if(*p == NULL)
    {
        return PI_VACIA;
    }
    memcpy(d, (*p)->info, minimo((*p)->tamInfo, cantBytes));
    return PI_OK;
}
void vaciarPila(tPila *p)
{
    tNodoPila *aux;
    while(*p)
    {
        aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}
void mostrarPila(tPila *p)
{
    tNodoPila *aux = *p;
    while(aux)
    {
        char* car = (char*)aux->info;
        printf("%c ", *car);
        aux = aux->sig;
    }
}
