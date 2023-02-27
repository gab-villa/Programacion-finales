#ifndef TPRODUCTO_H_INCLUDED
#define TPRODUCTO_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TAM_COD 6

typedef struct
{
    char cod[6];
    char tipo;
    int cant;
}tProd;

int compPorTipo(const void *, const void *);
void copiarProd(void *, const void *);

#endif // TPRODUCTO_H_INCLUDED
