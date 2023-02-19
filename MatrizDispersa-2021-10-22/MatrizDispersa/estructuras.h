#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#include "tLista.h"
#define TAM_REG 100
#define VACIO '\0'

typedef struct
{
    int col, val;
}tCol;

typedef struct
{
    int fila;
    tCol c;
}tFila;

typedef struct
{
    tLista *fLis;
    unsigned tamFila;
}tMatrizRala;

#endif // ESTRUCTURAS_H_INCLUDED
