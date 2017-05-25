#include <sstream>
#include <cassert>
#include "temperature.h"
using namespace std;
void test_input()
{
    stringstream in1("0K");
    Temp t;
    in1>>t;
    assert(t.value==0);
    assert(t.scale== Kelvin);

    stringstream in2("-10C");
    in2>>t;
    assert(t.value==-10);
    assert(t.scale== Celsus);

    stringstream in3("5F");
    in3>>t;
    assert(t.value==5);
    assert(t.scale== Farenheit);

    stringstream in4("-5K");
    in4>>t;
    assert(!in4);

    stringstream in5("Kek");
    in5>>t;
    assert(!in5);

    stringstream in6("-5000C");
    in6>>t;
    assert(!in6);

    stringstream in7("-5000F");
    in7>>t;
    assert(!in7);
}
int main() {
    test_input();
    return 0;
}