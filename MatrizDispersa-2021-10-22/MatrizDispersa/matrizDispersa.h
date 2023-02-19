#ifndef MATRIZDISPERSA_H_INCLUDED
#define MATRIZDISPERSA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "tLista.h"
#include "funcionesArchivos.h"

int crearMatrizRala(tMatrizRala *mr, unsigned tamFila);
int cargarMatrizRala(const char *nomArch, tMatrizRala *mr);
void mostrarElemMatriz(const void *vElem);

void mostrarValorMatriz(const void *vElem);

void imprimirMatRala2(const tMatrizRala *mr);
void imprimirMatRala(const tMatrizRala *mr);
int compCol(const void *v1, const void *v2);
void vaciarMatrizRala(tMatrizRala *mr);
void ponerCeros(const void *vElem, int *ini, int fin);
void ponerRestante(int *ini, int fin);
int actMax(void **vMax, unsigned *vSize, const void *vinfo, unsigned tamInfo);
tFila maxDP_mat_rala(tMatrizRala *mr);

#endif // MATRIZDISPERSA_H_INCLUDED
