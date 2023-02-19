#include "VectorEnteros.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
VectorEnteros::~VectorEnteros()
{
    //delete [] this->vec;
    //printf("libero vectores..\n");
    free(this->vec);
}
VectorEnteros::VectorEnteros()
{
    //this->vec = (int*)malloc(sizeof(int));
    this->vec = NULL;
    this->tamVec = 0;
}
VectorEnteros::VectorEnteros(const int *vec, unsigned tamVec)
{
    //this->vec = new int[tamVec];
    this->vec = (int*)malloc(sizeof(int)*tamVec);
    if(this->vec == NULL)
    {
        printf("wtf");
        throw -2;
    }
    memcpy(this->vec, vec, sizeof(int) * tamVec);
    this->tamVec = tamVec;
}
//SI SE COMENTA ESTE CONSTRUCTOR, NO AFECTA
VectorEnteros::VectorEnteros(const VectorEnteros& vec)
{
    this->vec = (int*)malloc(sizeof(int)* vec.tamVec);
    if(this->vec == NULL)
    {
        printf("wtf");
        throw -2;
    }
    memcpy(this->vec, vec.vec, sizeof(int) * vec.tamVec);
    this->tamVec = vec.tamVec;
}

//PARA EVITAR ERRORES DE COPIA
//SI SE COMENTA, PUEDE AFECTAR, PUEDEN
//APARECER POSIBLES VALORES INDESEADOS
VectorEnteros& VectorEnteros::operator=(const VectorEnteros& vec)
{
    //LIBERO SI TENIA ALGO ANTERIORMENTE, YA QUE
    //LO QUE TENGA QUE COPIAR PUEDE SER TOTALMENTE DISTINTO
    if(this->vec != NULL)
    {
        free(this->vec);
    }
    this->vec = (int*)malloc(sizeof(int)* vec.tamVec);
    if(this->vec == NULL)
    {
        printf("wtf");
        throw -2;
    }
    //HAY QUE COPIAR ANTES DE QUE EL OBJETO (VEC) SE DESTRUYA
    //YA QUE ES VAR LOCAL DE LA FUNCION OPERATOR+
    memcpy(this->vec, vec.vec, sizeof(int) * vec.tamVec);
    this->tamVec = vec.tamVec;
    return *this;
}
VectorEnteros& VectorEnteros::agregar(const int *vec, unsigned tamVec)
{
    unsigned tamTotal = this->tamVec + tamVec;
    //int *sum = new int[tamTotal]; SE PUEDE CON
    // NEW PERO NO TIENE REALLOC
    int *sum = (int*)realloc(this->vec, sizeof(int) * tamTotal);
    if(sum == NULL)
    {
        //libero lo q tenia antes
        free(this->vec);
        throw -3;
    }

    memcpy(sum+(int)this->tamVec, vec, sizeof(int) * tamVec);

    this->vec = sum;
    this->tamVec = tamTotal;
    return *this;
}
VectorEnteros VectorEnteros::operator+(const VectorEnteros& vec)
{
    VectorEnteros sum(this->vec, this->tamVec);
    sum.agregar(vec.vec, vec.tamVec);
    return sum;
}
VectorEnteros VectorEnteros::operator+(int num)
{
    VectorEnteros sum(this->vec, this->tamVec);
    sum.agregar(&num, 1);
    return sum;
}
ostream& operator<<(ostream& sal, const VectorEnteros &vec)
{
    unsigned i;
    sal << '[';

    for(i = 0;i < vec.tamVec-1;++i)
    {

        sal << vec.vec[i] << ", ";
        //printf("%d, ",(int)vec.vec[i]);
    }
    sal << vec.vec[i] << ']';
    return sal;
}
