#ifndef LOTEDEPRUEBA_H_INCLUDED
#define LOTEDEPRUEBA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "tArbol.h"
#include "tIndice.h"
#include "tProducto.h"

#define ARCH_OK 1
#define ARCH_ERROR 0

int abrirArchivo(FILE **arch, const char *nomArch, const char *ap);
void crearLoteDePrueba(const char *nomArch);
void insertarArchivoDesordenadoEnArbol(const char *nomArch, tArbol *ar);
void vaciarArbolEnArchIndiceEnOrd(const char *nomArchInd,
                                               tArbol *ar);
void insertarArchIndEnArbol(const char *nomArchInd, tArbol *ar);
void copiarArbolEnArchIndicePreOrd(const char *nomArchInd, tArbol *ar);
int regenerarArbolConIndice(const char *, tArbol *ar);

void mostrarArchInd(const char *nomArchInd);
#endif // LOTEDEPRUEBA_H_INCLUDED
