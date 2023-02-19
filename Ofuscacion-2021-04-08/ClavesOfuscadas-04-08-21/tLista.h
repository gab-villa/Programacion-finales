#ifndef TLISTA_H_INCLUDED
#define TLISTA_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#define minimo(X,Y) (X < Y) ? X : Y

#define LS_OK 1
#define LS_ERR = 0
#define LS_SINMEM -1
#define LS_VACIA -2

typedef struct sNodo
{
    unsigned tamInfo;
    void *info;
    struct sNodo *sig;
}tNodo;

typedef tNodo* tLista;

void crearLista(tLista* ls);

int listaVacia(const tLista *ls);
int insertarAlFinal(tLista *ls, const void *d, unsigned cantBytes);
int verUltimo(tLista *ls, void *d, unsigned cantBytes);
int sacarPrimero(tLista *ls, void *d, unsigned cantBytes);
void vaciarLista(tLista *ls);


#endif // TLISTA_H_INCLUDED
