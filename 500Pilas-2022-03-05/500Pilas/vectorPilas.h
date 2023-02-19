#ifndef VECTORPILAS_H_INCLUDED
#define VECTORPILAS_H_INCLUDED


#include "pila.h"
#define ERROR_N 0
#define NO_ENCONTRADO 0
#define OK 1
#define MIN_PER 1
#define MAX_PER 500
typedef struct
{
    tPila *p;
    unsigned n;
}tVecPila;

int crearVectorPilas(tVecPila *vp, int n);
tPila* buscarPila(tVecPila *vp, int pos);
int ponerEnVecPila(tVecPila *vp, int pos, int num);
int sacarDeVecPila(tVecPila *vp, int *num, int pos);
int pilaDeVecVacia(const tVecPila *vp, int pos);
void eliminarDeVecPila(tVecPila *vp, int pos);
int vaciarPilaDeVec(tVecPila *vp, int pos);
void vaciarVecPila(tVecPila *vp);

#endif // VECTORPILAS_H_INCLUDED
