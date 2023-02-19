#ifndef FUNCIONESARCHIVOS_H_INCLUDED
#define FUNCIONESARCHIVOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLista.h"
#include "estructuras.h"
#define TODO_OK 1
#define ERROR 0

int abrirArchivo(FILE** arch, const char* nomArch, const char* modoAp);
int verificarMatrizRala(const char *archMatriz);

void parsearReg(char *reg, tFila *f);
void parsearTam(char *reg, int *tamFila, int *tamCol);
int verificarCord(const tFila *f, int tamFila, int tamCol);
int sacarFilaDeArchivo(const char *nomArch);

#endif // FUNCIONESARCHIVOS_H_INCLUDED
