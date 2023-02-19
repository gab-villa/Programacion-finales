#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#define TAM_COD 6
typedef struct
{
    char cod[TAM_COD];
    char tipo;
    int cant;
}tProducto;

typedef struct
{
    char cod[TAM_COD];
    char tipo;
}tClave;

typedef struct
{
    tClave clave;
    unsigned indiceReg;
}tIndice;

#endif // ESTRUCTURAS_H_INCLUDED
