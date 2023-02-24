#ifndef TCOLA_H_INCLUDED
#define TCOLA_H_INCLUDED


#include "estructuras.h"
#define COLA_OK 1
#define COLA_ERROR 0
#define COLA_VACIA 0
#define COLA_SINMEM 0

typedef tNodo* tCola;

void crearCola(tCola *c);
int insertarEnCola(tCola *c, const void *d, unsigned cantBytes);
int sacarDeCola(tCola *c, void *d, unsigned cantBytes);
void vaciarCola(tCola *c);


#endif // TCOLA_H_INCLUDED
