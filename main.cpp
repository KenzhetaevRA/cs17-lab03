#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
using namespace std;
enum Scale{
    Kelvin = 'K',
    Celsus = 'C',
    Farenheit = 'F'
};
struct Temp{
    double value;
    Scale scale;
};
istream & operator>> (istream & in, Temp & t)
{
    in>>t.value;
    char symbol;
    in>> symbol;
    switch(symbol)
    {
    case 'K': t.scale=Kelvin;
                break;
    case 'C': t.scale=Celsus;
        break;
    case 'F': t.scale=Farenheit;
        break;
    }
    return in;
}
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
int
main() {
    test_input();
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    vector<double> numbers(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> numbers[i];
    }

    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    double min = numbers[0];
    double max = numbers[0];
    for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }

    vector<size_t> counts(column_count);
    for (double number : numbers) {
        size_t column = (size_t)((number - min) / (max - min) * column_count);
        if (column == column_count) {
            column--;
        }
        counts[column]++;
    }

    const size_t screen_width = 80;
    const size_t axis_width = 4;
    const size_t chart_width = screen_width - axis_width;

    // Можно было бы считать в предыдущем цикле, но так более наглядно.
    size_t max_count = 0;
    for (size_t count : counts) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > chart_width;

    for (size_t count : counts) {
        if (count < 100) {
            cout << ' ';
        }
        if (count < 10) {
            cout << ' ';
        }
        cout << count << "|";

        size_t height = count;
        if (scaling_needed) {
            // Point: код должен быть в первую очередь понятным.
            const double scaling_factor = (double)chart_width / max_count;
            height = (size_t)(count * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}