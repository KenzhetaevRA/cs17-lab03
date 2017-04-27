#ifndef TEMP
#define TEMP

#include <iostream>
enum Scale{
    Kelvin = 'K',
    Celsus = 'C',
    Farenheit = 'F'
};
struct Temp{
    double value;
    Scale scale;
};
std::istream & operator>> (std::istream & in, Temp & t);

bool  operator< (const Temp& lhs, const Temp& rhs);

Temp convert(const Temp& from, Scale scale);
#endif