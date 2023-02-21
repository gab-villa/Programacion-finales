#ifndef TLISTA_H_INCLUDED
#define TLISTA_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#define LS_CLADUP 2
#define LS_OK 1
#define LS_VACIA 0
#define LS_SINMEM -1
#define LS_ERROR -2

#define minimo(X, Y) (X < Y) ? X : Y

typedef struct sNodo
{
    unsigned tamInfo;
    void *info;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tLista;

void crearLista(tLista *ls);
int insertarAlFinal(tLista *ls, const void *d, unsigned cantBytes);
int sacarPrimero(tLista *ls, void *d, unsigned cantBytes);
void vaciarLista(tLista *ls);

int ponerEnOrden(tLista *ls, const void *d, unsigned cantBytes,
                 int (*comp)(const void *, const void *),
                 void (*acum)(void *, const void *));
void mostrarLista2(const tLista *ls, void ((*mostrar)(const void *)));
void mostrarLista(const tLista *ls, void (*mostrar)(const void *));
void sacarPromDeListaOrd(tLista *ls, int (*comp)(const void *, const void *),
                        void (*acum)(void *, const void *),
                        void (*sacarProm)(void *, unsigned));

#endif // TLISTA_H_INCLUDED
