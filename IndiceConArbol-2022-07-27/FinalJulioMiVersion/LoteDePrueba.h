#ifndef LOTEDEPRUEBA_H_INCLUDED
#define LOTEDEPRUEBA_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Estructuras.h"
#include "tArbol.h"
#define ERROR_AR 0
#define TODO_OK_AR 1

//funciones grandes
int abrirArchivo(FILE **arch, const char *nomArch, const char *ap);
void crearLoteDePrueba(const char *nomArchPrueba);
void cargarArbolConPrueba(tArbol *p, const char *nomArchPrueba);
void vaciarArbolEnIndice(tArbol *p, const char *nomArchIndice);
void crearArbolDeIndiceBalanceado(const char *nomArchIndice, tArbol *indice);
void cargarIndiceEnArbolRec(tArbol *p, FILE *archIndice, int li, int ld);
void mostrarArchivoIndice(const char *nomArchIndice);
void mostrarHijos(const tArbol *p, void (*mostrar)(const void *));
void mostrarIndiceConForma(const void *v, unsigned n);
//funciones pequeñas
void crearIndice(tIndice *ind, const tProducto *prod, unsigned indiceReg);
int compIndice(const void *v1, const void *v2);
void mostrarIndice(const void *v);
#endif // LOTEDEPRUEBA_H_INCLUDED
