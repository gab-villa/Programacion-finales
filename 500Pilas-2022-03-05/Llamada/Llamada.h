#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

#include <iostream>
#include <string>
#define SUMA_EXCEPTION -1
using namespace std;

class Llamada
{
    private:
        string numOrg;
        string numDes;
        int tiempo;
    public:
        ~Llamada();
        Llamada(const string&, const string&, int);
        Llamada& operator=(const Llamada& com);
        Llamada operator+(const Llamada& com);
        friend Llamada operator+(int tiempo, const Llamada& com);
        friend ostream& operator<<(ostream& sal, const Llamada& com);
};

#endif // LLAMADA_H_INCLUDED
