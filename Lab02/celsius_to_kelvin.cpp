// lab 2 exercise 3.1 - 3.4
#include "../std_lib_facilities.h"
#include <stdexcept>

double ctok(double c);
double ktoc(double k);

double val = 0;
string unit = "";

int main()
{
    cout << "Enter a temperature and unit (c or k): ";
    cin >> val >> unit; // retrieve temperature to input variables
    try 
    {
        if (unit == "c") {
            double k = ctok(val);
            cout << val << "C is " << k << "K\n";
        }
        else if (unit == "k") {
            double c = ktoc(val);
            cout << val << "K is " << c << "C\n";
        }
    }
    catch (invalid_argument& e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}

double ctok(double c) // converts Celsius to Kelvin
{
    if (c < -273.15) {
        throw invalid_argument("Temperature below absolute zero.");
    }
    double k = c + 273.15;
    return k;
}

double ktoc(double k) // converts Kelvin to Celsius
{
    if (k < 0) {
        throw invalid_argument("Temperature below absolute zero.");
    }
    double c = k - 273.15;
    return c;
}