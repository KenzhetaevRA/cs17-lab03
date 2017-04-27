//
// Created by u211-14 on 27.04.2017.
//
#include "temperature.h"
using  namespace std;
istream & operator>> (istream & in, Temp & t) {
    in >> t.value;
    char symbol;
    if (!in) {
        in.setstate(ios_base::failbit);
        return in;
    }
    in >> symbol;
    switch (symbol) {
    case 'K':
        t.scale = Kelvin;
        break;
    case 'C':
        t.scale = Celsus;
        break;
    case 'F':
        t.scale = Farenheit;
        break;

    default:
        in.setstate(ios_base::failbit);
    }
    if(convert(t,Kelvin).value<0) {in.setstate(ios_base::failbit);}
    return in;
}

bool  operator< (const Temp& lhs, const Temp& rhs)
{
    Temp OutL;
    OutL=convert(lhs,rhs.scale);
    return OutL.value<rhs.value;
}

Temp convert(const Temp& from, Scale scale){
    double kel;
    Temp to;
    switch(from.scale) {
    case Kelvin:
        kel = from.value;
        break;
    case Celsus:
        kel = from.value + 273;
        break;
    case Farenheit:
        kel = (from.value - 273) * 1.8 + 32;
        break;
    }
    switch(scale)
    {
    case Kelvin: to.value = kel;
        break;
    case Celsus: to.value = kel-273;
        break;
    case Farenheit: to.value = 5*(kel - 32)/9+273 ;
        break;

    }
    to.scale=scale;
    return (to);
}