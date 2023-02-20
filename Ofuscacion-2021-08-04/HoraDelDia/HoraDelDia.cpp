#include "HoraDelDia.h"

HoraDelDia::~HoraDelDia()
{

}

HoraDelDia::HoraDelDia()
{
    horaEnSeg = 0;
}
HoraDelDia::HoraDelDia(unsigned horaEnSeg)
{
    if(horaEnSeg > DIA_EN_SEG)
    {
        this->horaEnSeg = horaEnSeg % DIA_EN_SEG;
    }
    else
    {
        this->horaEnSeg = horaEnSeg;
    }
}
HoraDelDia::HoraDelDia(unsigned hora, unsigned minu, unsigned seg)
{
    horaEnSeg = seg + minu*MINU_EN_SEG + hora*HORA_EN_SEG;
    if(horaEnSeg > DIA_EN_SEG)
    {
        horaEnSeg = horaEnSeg % DIA_EN_SEG;
    }
}
HoraDelDia& HoraDelDia::operator=(const HoraDelDia& hDia)
{
    horaEnSeg = hDia.horaEnSeg;
    return *this;
}

bool HoraDelDia::operator<(const HoraDelDia& hDia)
{
    return this->horaEnSeg < hDia.horaEnSeg;
}
bool HoraDelDia::operator>=(const HoraDelDia& hDia)
{
    return this->horaEnSeg >= hDia.horaEnSeg;
}
HoraDelDia HoraDelDia::operator+(const HoraDelDia& hDia)
{
    HoraDelDia suma(this->horaEnSeg + hDia.horaEnSeg);
    return suma;
}
HoraDelDia HoraDelDia::operator++(int n)
{
    HoraDelDia temp = *this;
    ++this->horaEnSeg;
    return temp;
}
HoraDelDia& HoraDelDia::operator+=(unsigned seg)
{
    //HoraDelDia suma(this->horaEnSeg + seg);
    this->horaEnSeg += seg;
    return *this;
}
ostream& operator<<(ostream& sal, const HoraDelDia& hDia)
{
    unsigned h, m, s;
    hDia.getHoraMinuSeg(&h, &m, &s);
    return sal << h << " " << m << " " << s << endl;
}
istream& operator>>(istream& ent, HoraDelDia& hDia)
{
    unsigned h, m, s;
    ent >> h >> m >> s;
    hDia.horaEnSeg = s + m*MINU_EN_SEG + h*HORA_EN_SEG;
    if(hDia.horaEnSeg > DIA_EN_SEG)
    {
        hDia.horaEnSeg = hDia.horaEnSeg % DIA_EN_SEG;
    }
    return ent;
}
HoraDelDia operator+(unsigned seg, const HoraDelDia& hDia)
{
    HoraDelDia suma(seg + hDia.horaEnSeg);
    return suma;
}
void HoraDelDia::getHoraMinuSeg(unsigned *h, unsigned *m, unsigned *s) const
{
    *h = *m = *s = 0;
    unsigned horaEnSeg = this->horaEnSeg;

    *h = horaEnSeg / HORA_EN_SEG;
    horaEnSeg = horaEnSeg % HORA_EN_SEG;

    *m = horaEnSeg / MINU_EN_SEG;
    horaEnSeg = horaEnSeg % MINU_EN_SEG;

    *s = horaEnSeg;
}
/*
HoraDelDia HoraDelDia::getHoraMaxima()
{
    HoraDelDia horaMaxima(23, 59, 59);
    return horaMaxima;
}*/

