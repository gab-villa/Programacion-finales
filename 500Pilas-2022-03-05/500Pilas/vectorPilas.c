#include "vectorPilas.h"
#include <stdio.h>
int crearVectorPilas(tVecPila *vp, int tam)
{
    int i = 0;

    if(tam < MIN_PER || tam > MAX_PER)
    {
        return ERROR_N;
    }
    // no es necesario
    /*
    vp = (tVecPila*)malloc(sizeof(tVecPila));
    if(vp == NULL)
    {
        return SIN_MEM;
    }*/
    vp->p = (tPila*)malloc(sizeof(tPila) * tam);
    if(vp->p == NULL)
    {
        free(vp);
        return SIN_MEM;
    }
    vp->n = tam;
    //printf("%d",vp->n);
    while(i < tam)
    {
        crearPila(&vp->p[i]);
        //++(vp->p);
        ++i;
    }
    return OK;
}
tPila* buscarPila(tVecPila *vp, int pos)
{
    if(pos < 1 || pos > vp->n)
    {
        return NULL;
    }
    return &vp->p[pos-1];
}
int ponerEnVecPila(tVecPila *vp, int pos, int num)
{
    if(pos < MIN_PER || pos > vp->n)
    {
        return ERROR_N;
    }
    if(!ponerEnPila(&vp->p[pos-1], &num, sizeof(int)))
    {
        return SIN_MEM;
    }

    /*
    tPila* pilaBus = buscarPila(vp, pos);
    if(pilaBus == NULL)
    {
        return NO_ENCONTRADO;
    }
    if(!ponerEnPila(pilaBus, &num, sizeof(int)))
    {
        return SIN_MEM;
    }*/
    return OK;
}
void eliminarDeVecPila(tVecPila *vp, int pos)
{
    int aux;
    if(pos < MIN_PER || pos > vp->n)
    {
        return;
    }
    sacarDePila(&vp->p[pos-1], &aux, sizeof(int));
}
int pilaDeVecVacia(const tVecPila *vp, int pos)
{
    if(pos < MIN_PER || pos > vp->n)
    {
        return ERROR_N;
    }
    return pilaVacia(&vp->p[pos-1]);
}
int sacarDeVecPila(tVecPila *vp, int *num, int pos)
{
    if(pos < MIN_PER || pos > vp->n)
    {
        return ERROR_N;
    }
    if(!sacarDePila(&vp->p[pos-1], num, sizeof(int)))
    {
        return PILA_VACIA;
    }
    /*
    int num;
    tPila *pilaBus = buscarPila(vp, pos);
    if(pilaBus == NULL)
    {
        return NO_ENCONTRADO;
    }
    if(!sacarDePila(pilaBus, &num, sizeof(int)))
    {
        return PILA_VACIA;
    }*/
    return OK;
}
int vaciarPilaDeVec(tVecPila *vp, int pos)
{
    if(pos < MIN_PER || pos > vp->n)
    {
        return ERROR_N;
    }
    vaciarPila(&vp->p[pos-1]);
    return OK;
}
void vaciarVecPila(tVecPila *vp)
{

    int i = 0;
    while(i < vp->n)
    {
        vaciarPila(&vp->p[i]);
        ++i;
    }
}
