#include "Medicion.h"

Medicion::~Medicion()
{

}
Medicion::Medicion(float val, string medida)
{
    this->val = val;
    this->medida = medida;
}
Medicion operator+(float val, const Medicion& med)
{
    Medicion sum(med.val + val, med.medida);
    return sum;
}
Medicion Medicion::operator-(const Medicion& med)
{
    if(med.medida != this->medida)
    {
        throw 1;
    }
    Medicion dif(this->val - med.val, this->medida);
    return dif;
}
ostream& operator<<(ostream& sal, const Medicion& med)
{
    return sal << med.val << " " << med.medida;
}
