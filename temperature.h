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

Temp convert(const Temp& from, Scale scale);
#endif