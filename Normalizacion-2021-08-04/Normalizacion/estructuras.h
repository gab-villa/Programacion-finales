#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#define minimo(X, Y) (X < Y) ? X : Y

typedef struct sNodo
{
    unsigned tamInfo;
    void *info;
    struct sNodo *sig;
}tNodo;

#endif // ESTRUCTURAS_H_INCLUDED
