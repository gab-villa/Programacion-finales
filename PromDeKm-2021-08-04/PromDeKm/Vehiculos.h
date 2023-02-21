#ifndef VEHICULOS_H_INCLUDED
#define VEHICULOS_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tVehiculo.h"
#include "tLista.h"

#define ARCH_OK 1
#define ARCH_ERR 0

int abrirArchivo(FILE** arch, const char *nomArch, const char* ap);
void crearLoteDePrueba(const char *nomArch);
void calcularPromedio(const char *nomArch);
void calcularPromedioProc(FILE *archAutos);

int compAnt(const void *v1, const void *v2);
int compDom(const void *v1, const void *v2);
void acumPromKmRec(void *vProm, const void *v);
void sacarPromKmRec(void *v, unsigned cant);
void mostrarVehiculo(const void *v);

#endif // VEHICULOS_H_INCLUDED
