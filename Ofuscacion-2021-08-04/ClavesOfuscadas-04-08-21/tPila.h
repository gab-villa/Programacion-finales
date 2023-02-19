#ifndef TPILA_H_INCLUDED
#define TPILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define minimo(X,Y) (X < Y) ? X : Y



#define PI_OK 1
#define PI_ERR = 0
#define PI_SINMEM -1
#define PI_VACIA -2

typedef struct sNodoPila
{
    unsigned tamInfo;
    void *info;
    struct sNodoPila *sig;
}tNodoPila;

typedef tNodoPila* tPila;

void crearPila(tPila *p);

int pilaVacia(const tPila *p);
int insertarEnPila(tPila *p, const void *d, unsigned cantBytes);
int eliminarDePila(tPila *p);
int verTope(const tPila *p, void *d, unsigned cantBytes);
void vaciarPila(tPila *p);

void mostrarPila(tPila *p);

#endif // TPILA_H_INCLUDED
