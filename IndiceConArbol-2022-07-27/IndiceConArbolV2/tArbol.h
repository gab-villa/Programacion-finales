#ifndef TARBOL_H_INCLUDED
#define TARBOL_H_INCLUDED

#include <string.h>
#include <stdlib.h>

#define ARBOLITO_OK 1
#define ARBOLITO_ERROR 0
#define ARBOLITO_VACIO 0
#define ARBOLITO_SINMEM 0
#define ARBOLITO_CLADUP 2

typedef struct sNodoArbol
{
    unsigned tamInfo;
    void *info;
    struct sNodoArbol *izq;
    struct sNodoArbol *der;
}tNodoArbol;

typedef tNodoArbol* tArbol;

void crearArbol(tArbol *ar);
void vaciarArbol(tArbol *ar);
void mostrarArbolHorizontal(const tArbol* ar,
                            void (*mostrar)(const void *, int));
void mostrarArbolHorizontalProc(const tArbol *ar,
                                void (*mostrar)(const void *, int),
                                int n);

int insertarEnArbol(tArbol *ar, const void *d, unsigned cantBytes,
                    int (*comp)(const void *, const void *));

void copiarArbolEnDataSetEnOrden(tArbol *ar, void *ds,
                                void (*copiar)(void *, const void *));
int insertarArchOrdenadoEnArbolBal(tArbol *ar, const void *ds,
                                  unsigned tamReg,
                                  void (*leer)(const void *, void *, int),
                                  int li, int ld);
void copiarArbolEnDataSetPreOrden(tArbol *ar, void *ds,
                                  void (*copiar)(void *, const void *));


#endif // TARBOL_H_INCLUDED
