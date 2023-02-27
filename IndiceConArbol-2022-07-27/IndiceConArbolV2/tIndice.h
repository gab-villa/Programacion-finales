#ifndef TINDICE_H_INCLUDED
#define TINDICE_H_INCLUDED

#include "tProducto.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char cod[TAM_COD];
    char tipo;
}tClave;

typedef struct
{
    tClave cla;
    unsigned numInd;
}tIndice;

void copiarProdEnInd(void *ind, const void *prod);
void copiarInd(void *, const void *);
void leerInd(const void *, void *, int);
void mostrarInd(const void *, int);
void mostrarInd2(const void *);
int compIndPorCod(const void *v1, const void *v2);

#endif // TINDICE_H_INCLUDED
