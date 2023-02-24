#ifndef NORMALIZAR_H_INCLUDED
#define NORMALIZAR_H_INCLUDED

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tCola.h"

#define ARCH_OK 1
#define ARCH_ERROR 0
//int esMayus(char car);
//int esMinus(char car);

int abrirArchivo(FILE **arch, const char *nomArch, const char *ap);
int esCarValido(int car);

void normalizarArchivo(const char *nomArch, tCola *txt);
void normalizarArchivoProc(FILE* arch, tCola *txt);

void vaciarColaTxtEnArchivo(const char *nomArch, tCola* txt);

#endif // NORMALIZAR_H_INCLUDED
