#include "Llamada.h"

Llamada::~Llamada()
{
}
Llamada::Llamada(const string& numOrg, const string& numDes, int tiempo)
{
    this->numOrg = numOrg;
    this->numDes = numDes;
    this->tiempo = tiempo;
}
Llamada& Llamada::operator=(const Llamada& com)
{
    this->numDes = com.numDes;
    this->numOrg = com.numOrg;
    this->tiempo = com.tiempo;
    return *this;
}
Llamada Llamada::operator+(const Llamada& com)
{
    if(this->numOrg != com.numOrg)
    {
        throw SUMA_EXCEPTION;
    }
    Llamada sum(this->numOrg, "", this->tiempo + com.tiempo);
    return sum;
}

Llamada operator+(int tiempo, const Llamada& com)
{
    Llamada sum(com.numOrg, com.numDes, com.tiempo + tiempo);
    return sum;
}
ostream& operator<<(ostream& sal, const Llamada& com)
{
    return sal << "( " << com.numOrg << ", "
               << com.numDes << ", " << com.tiempo << ")";
}
