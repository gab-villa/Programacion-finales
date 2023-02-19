#ifndef VECTORENTEROS_H_INCLUDED
#define VECTORENTEROS_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class VectorEnteros {
    private:
        int *vec;
        unsigned tamVec;
    public:
        ~VectorEnteros();
        VectorEnteros();

        VectorEnteros(const int *vec, unsigned tamVec);
        VectorEnteros(const VectorEnteros& vec);
        VectorEnteros& operator=(const VectorEnteros &vec);


        VectorEnteros operator+(const VectorEnteros& vec);
        VectorEnteros operator+(int num);
        friend ostream& operator<<(ostream& sal, const VectorEnteros &vec);
        VectorEnteros& agregar(const int *vec, unsigned tamVec);

};

#endif // VECTORENTEROS_H_INCLUDED
