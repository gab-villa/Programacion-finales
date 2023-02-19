#ifndef TARBOL_H_INCLUDED
#define TARBOL_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define minimo(X,Y) ((X < Y) ? X : Y)

#define TODO_OK_AR 1
#define SIN_MEM_AR 0
#define ARBOL_VACIO 0
#define ERROR_AR 0
#define CLA_DUP_AR 2
typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *izq;
    struct sNodo *der;
}tNodo;

typedef tNodo* tArbol;

void crearArbol(tArbol *p);
int insertarEnArbol(tArbol *p, const void *d, unsigned cantBytes,
                    int (*comp)(const void *, const void *));
int insertarEnArbol2(tArbol *p, const void *d, unsigned cantBytes,
                    int (*comp)(const void *, const void *));
int sacarEnOrden(tArbol *p, void *d, unsigned cantBytes);
void mostrarArbolGrafico(const tArbol *p,
                         void (*mostrar)(const void *, unsigned));
void mostrarArbolGraficoProc(const tArbol *p, unsigned n,
                             void (*mostrar)(const void *, unsigned));

void mostrarArbolEnOrden(const tArbol *p, void (*mostrar)(const void *));



int alturaArbol(const tArbol *p);
void vaciarArbol(tArbol *p);

#endif // TARBOL_H_INCLUDED
