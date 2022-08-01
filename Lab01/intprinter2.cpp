// lab 1 exercise 6.6+
#include "../std_lib_facilities.h"

constexpr double inch_to_cm = 2.54;
double x, smallest = 0, largest = 0, sum = 0, counter = 0;
string unit = "";
vector<double> values;

int main() 
{
    double x_value = 0;
    cout << "Enter a number and a unit (cm, m, in, ft) or | to exit: ";
    while (cin >> x >> unit) {
        if (unit == "|") {break;}
        if (unit == "cm") {
            x_value = x;
        }
        else if (unit == "m") {
            x_value = 100*x;
        }
        else if (unit == "in") {
            x_value = x*inch_to_cm;
        }
        else if (unit == "ft") {
            x_value = x*inch_to_cm*12;
        }
        else {
            cout << "Illegal unit. Try again.\n";
            continue;
        }
        if (counter == 0) {
            smallest = x_value/100;
            largest = x_value/100;
        }
        else {
            if (x_value < smallest) {
                smallest = x_value/100; }
            if (x_value > largest) {
                largest = x_value/100; }
        }
        sum += x_value/100;
            ++counter;
            values.push_back(x_value/100);
    }
    sort(values);
    cout << "Smallest: " << smallest << "m\n" << "Largest: " << largest << "m\n"
    << "Sum: " << sum << "m\n" << "Number of values: " << counter << "\n";
    cout << "Values: ";
    for (int i; i < values.size(); i++) {
        cout << values[i] << "m ";
    }
    cout << "\n";
}