#ifndef MEDICION_H_INCLUDED
#define MEDICION_H_INCLUDED

#include <exception>
#include <string>
#include <iostream>

using namespace std;

class Medicion
{
    private:
        float val;
        string medida;
    public:
        ~Medicion();
        Medicion(float, string);
        friend Medicion operator+(float val, const Medicion& med);
        Medicion operator-(const Medicion& med);
        friend ostream& operator<<(ostream& sal, const Medicion& med);
};

#endif // MEDICION_H_INCLUDED
