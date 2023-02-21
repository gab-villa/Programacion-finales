#ifndef TVEHICULO_H_INCLUDED
#define TVEHICULO_H_INCLUDED

#define TAM_COD 7

typedef struct
{
    char cod[TAM_COD];
    unsigned ant;
    float kmRec;
}tVehiculo;


#endif // TVEHICULO_H_INCLUDED
