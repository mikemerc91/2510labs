// lab 1 exercise 6
#include "../std_lib_facilities.h"

int main()
{
    double x = 0;
    double y = 0;
    double smallest, largest;
    cout << "Enter two integers (| to exit): ";
    while (cin >> x >> y) {
        if (x == y) {
            cout << "The numbers are equal\n";
            cout << "Enter two integers (| to exit): ";
            continue;
        }
        if (x < y) {
            smallest = x;
            largest = y;
        }
        else {
            smallest = y;
            largest = x;
        }
        cout << "Smallest: " << smallest << "\nLargest: " << largest << "\n";
        if ((largest - smallest) < (1.0/100))
            cout << "The numbers are almost equal.\n"; 
        cout << "Enter two integers (| to exit): \n";
    }
    return 0;
}
    

