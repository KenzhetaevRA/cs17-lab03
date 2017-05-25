#include <iostream>
#include <vector>
#include "temperature.h"
using namespace std;
int
main() {
    size_t temp_count;
    cerr << "Enter number temp: ";
    cin >> temp_count;


    cerr << "Enter temp: ";
    vector<Temp> temp(temp_count);
    for (size_t i = 0; i < temp_count; i++) {
        cin >> temp[i];
    }

    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    double min = convert(temp[0],Kelvin).value;
    double max = convert(temp[0],Kelvin).value;
    for (Temp number0 : temp) {
        double number = convert(number0,Kelvin).value;
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;

        }
    }

    vector<size_t> counts(column_count);
    for (Temp number0 : temp) {
        double number = convert(number0,Kelvin).value;
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

