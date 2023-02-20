#ifndef HORADELDIA_H_INCLUDED
#define HORADELDIA_H_INCLUDED
#include <iostream>

#define MINU_EN_SEG 60
#define HORA_EN_SEG 3600
#define DIA_EN_SEG 86400
using namespace std;

class HoraDelDia
{
    /* Ventajas de tener la hora total en segundos:
        Se facilita las cuentas a la hora de sumar o
        restar diferentes objetos hora
       Desventajas:
        Aumenta la complejidad a la hora de hacer operaciones
        mas simples como mostrar objetos hora
    */
    private:
        unsigned horaEnSeg;

    public:
        ~HoraDelDia();
        HoraDelDia();
        HoraDelDia(unsigned hora, unsigned minu, unsigned seg);
        HoraDelDia(unsigned horaEnSeg);

        bool operator>=(const HoraDelDia &h);
        bool operator<(const HoraDelDia &h);
        HoraDelDia& operator=(const HoraDelDia& h);
        HoraDelDia operator+(const HoraDelDia& h);
        HoraDelDia operator++(int n); // inc seg
        HoraDelDia& operator+=(unsigned seg);

        void getHoraMinuSeg(unsigned* h, unsigned* m, unsigned* s) const;

        friend ostream& operator<<(ostream& sal, const HoraDelDia& h);
        friend istream& operator>>(istream& ent, HoraDelDia& h);
        friend HoraDelDia operator+(unsigned seg, const HoraDelDia& h);

        //HoraDelDia getHoraMaxima();
};

#endif // HORADELDIA_H_INCLUDED
