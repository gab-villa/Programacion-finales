#ifndef HORADELDIA_H_INCLUDED
#define HORADELDIA_H_INCLUDED
#include <iostream>

using namespace std;

class HoraDelDia
{
    private:
        int hora, minu, seg;

    public:
        ~HoraDelDia();
        HoraDelDia();
        HoraDelDia(int hora, int minu, int seg);


        bool operator>=(const HoraDelDia &h);
        bool operator<(const HoraDelDia &h);
        HoraDelDia& operator=(const HoraDelDia& h);
        HoraDelDia operator+(const HoraDelDia& h);
        HoraDelDia operator++(int seg); // inc seg
        HoraDelDia operator+=(int seg);




        friend ostream& operator<<(ostream& sal, const HoraDelDia& h);
        friend istream& operator>>(istream& ent, HoraDelDia& h);
        friend HoraDelDia operator+(int seg, const HoraDelDia& h);

        //HoraDelDia getHoraMaxima();
};

#endif // HORADELDIA_H_INCLUDED
