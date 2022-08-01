// lab2 exercise 3.5
#include "../std_lib_facilities.h"

double convert(double val, string unit);

double val = 0;
string unit = "";

int main()
{
    cout << "Enter a temperature and a unit (c or f): ";
    cin >> val >> unit;

    double result = convert(val, unit);

    if (unit == "c") {
        cout << val << "C is " << result << "F\n"; 
    }
    else if (unit == "f") {
        cout << val << "F is " << result << "C\n";
    }
    return 0;
}

// test by estimate
// 1 C: 9 / (5*1) + 32 ~~ 1.9 + 32 ~~ 33.9 ACTUAL 33.8
// 1 F: (5/9) * (1 - 32) ~~ 0.6 * -31 ~~ -17 ACTUAL -17.22

double convert(double val, string unit) 
{
    if (unit == "c") {
        val = 9.0 / 5 * val + 32;
    }
    else if (unit == "f") {
        val = (5.0 / 9) * (val - 32);
    }
    return val;
}