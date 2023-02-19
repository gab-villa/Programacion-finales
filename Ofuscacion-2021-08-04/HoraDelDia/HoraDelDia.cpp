#include "HoraDelDia.h"

HoraDelDia::~HoraDelDia()
{

}
HoraDelDia::HoraDelDia()
{
    this->hora = 0;
    this->minu = 0;
    this->seg = 0;
}
HoraDelDia::HoraDelDia(int hora, int minu, int seg)
{
    this->hora = hora;
    this->minu = minu;
    this->seg = seg;
}
HoraDelDia& HoraDelDia::operator=(const HoraDelDia& h)
{
    hora = h.hora;
    minu = h.minu;
    seg = h.seg;
    return *this;
}
bool HoraDelDia::operator<(const HoraDelDia& h)
{
    if(this->hora == h.hora)
    {
        if(this->minu == h.minu)
        {
            if(this->seg < h.seg)
            {
                return true;
            }
        }
        else if(this->minu < h.minu)
        {
            return true;
        }
    }
    else if(this->hora < h.hora)
    {
        return true;
    }
    return false;
}
bool HoraDelDia::operator>=(const HoraDelDia& h)
{
    return !(*this < h);
}
HoraDelDia HoraDelDia::operator+(const HoraDelDia& h)
{
    HoraDelDia suma(this->hora + h.hora,
                    this->minu + h.minu,
                    this->seg + h.seg);
    return suma;
}
HoraDelDia HoraDelDia::operator++(int seg)
{
    HoraDelDia temp = *this;
    ++this->seg;
    return temp;
}
HoraDelDia HoraDelDia::operator+=(int seg)
{
    HoraDelDia suma(this->hora, this->minu, this->seg + seg);
    return suma;
}
ostream& operator<<(ostream& sal, const HoraDelDia& h)
{
    return sal << h.hora << " " << h.minu << " " << h.seg << endl;
}
istream& operator>>(istream& ent, HoraDelDia& h)
{
    return ent >> h.hora >> h.minu >> h.seg;
}
HoraDelDia operator+(int seg, const HoraDelDia& h)
{
    HoraDelDia suma(h.hora, h.minu, h.seg + seg);
    return suma;
}
/*
HoraDelDia HoraDelDia::getHoraMaxima()
{
    HoraDelDia horaMaxima(23, 59, 59);
    return horaMaxima;
}*/

