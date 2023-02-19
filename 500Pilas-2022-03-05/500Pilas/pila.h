#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#define minimo(X, Y) (X < Y) ? X : Y
#define SIN_MEM 0
#define PILA_VACIA 0
#define TODO_OK 1
typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;

typedef tNodo* tPila;

void crearPila(tPila *p);
int pilaVacia(const tPila *p);
int ponerEnPila(tPila *p, const void *d, unsigned cantBytes);
int sacarDePila(tPila *p, void *d, unsigned cantBytes);
void vaciarPila(tPila *p);
#endif // PILA_H_INCLUDED
