#ifndef TLISTA_H_INCLUDED
#define TLISTA_H_INCLUDED

#include<stdlib.h>
#include<string.h>
#define SIN_MEM -1
#define CLA_DUP 1
#define FOUND 1
#define NOT_FOUND 0
#define ERROR_ACT 0
#define OK 2

typedef struct sNodo
{
    void            *info;
    unsigned        tamInfo;
    struct sNodo    *sig;
} tNodo;

typedef tNodo *tLista;

void crearLista(tLista *p);
int listaVacia(const tLista *p);
int listaLlena(const tLista *p, unsigned cantBytes);
void vaciarLista(tLista *p);
int ponerAlComienzo(tLista *p, const void *d, unsigned cantBytes);
int sacarPrimeroLista(tLista *p, void *d, unsigned cantBytes);
int verPrimeroLista(const tLista *p, void *d, unsigned cantBytes);
int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes);
int sacarUltimoLista(tLista *p, void *d, unsigned cantBytes);
int verUltimoLista(const tLista *p, void *d, unsigned cantBytes);

int ponerEnOrdenAcum(tLista *p, const void *d, unsigned cantBytes,
                     int (*comparar)(const void *, const void *),
                     int (*acumular)(void **, unsigned *, const void *, unsigned));
int ponerEnOrden(tLista *p, const void *d, unsigned cantBytes,
                     int (*comparar)(const void *, const void *));
void recorrerLista(tLista *p, void mostrar(const void *info));
void recorrerListaConCeros(tLista *p, int fin,
                        void (*ponerCeros)(const void *, int*, int),
                        void (*ponerRestante)(int *, int));

int buscarPorClaveEnListaOrd(const tLista *ls, void *cla, unsigned tam,
                    int (*comp)(const void *, const void *),
                    int (*act)(void **, unsigned *, const void *, unsigned));
#endif // TLISTA_H_INCLUDED
