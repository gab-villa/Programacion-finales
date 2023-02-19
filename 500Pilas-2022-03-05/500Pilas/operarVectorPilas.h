#ifndef OPERARVECTORPILAS_H_INCLUDED
#define OPERARVECTORPILAS_H_INCLUDED

#include "vectorPilas.h"
#include <stdio.h>
#include <stdlib.h>
#define TAM_REG 100
#define ARCH_ERROR 0
#define ARCH_OK 1
#define FIN_ANORMAL -1
typedef struct
{
    int i;
    int j;
}tPar;

int abrirArchivo(FILE **arch, const char *nomArch, const char *ap);
int crearVectorPilasConArch(const char *nomArchDatos, tVecPila *vp);
int parsearNumPilas(char *reg);
void parsearPares(char *reg, tPar *par);
void exportarPilas(const char *nomArchExp, tVecPila *vp);
void cambiarNombrePilaPos(char *nomArchPila, int pos);
void actArchPila(FILE *archPila, int num, int pos);
void exportarPilasEnVariosArchivos(tVecPila *vp);
#endif // OPERARVECTORPILAS_H_INCLUDED
