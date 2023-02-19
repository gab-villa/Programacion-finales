#ifndef LOTEDEPRUEBA_H_INCLUDED
#define LOTEDEPRUEBA_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "tLista.h"
#include "tPila.h"
#define ARCH_OK 1
#define ARCH_ERR 0

#define ES_CLA 2
#define NO_ES_CLA -1
#define MAX_LEN 57 //el \n y \0


int abrirArchivo(FILE** arch, const char *nomArch, const char* ap);
int esMayus(char car);
int esMinus(char car);
int esLetra(char car);

int esClave(const char *reg, tPila *cla);
int compCar(char a, char b);
void invertir(char *cad);
void vaciarPilaEnCadena(char *cad, tPila *ls);
void procesarArchivo(const char *nomArch);

#endif // LOTEDEPRUEBA_H_INCLUDED
