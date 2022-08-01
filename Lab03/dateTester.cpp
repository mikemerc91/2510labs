// lab 3 exercise 3
#include "../std_lib_facilities.h"
#include "chrono.h"
using namespace Chrono;

int main()
{
    try {
    Date today{2018,Month::JUL,31};
    Date tomorrow = today;
    tomorrow.addDay();
    cout << "Today: " << today.toString() << "\nTomorrow: " << tomorrow.toString() << endl;
    cout << "Today Year, Month, Day: " << today.year()<<", "<< static_cast<int>(today.month())
    <<", " << today.day()<< endl;
    Date notLeap{2021,Month::FEB,29};
    //Date leap{2020,Month::FEB,29};
    }
    catch (InvalidDate& e)
    {
        cerr << e.message() << endl;
    } 
    
    return 0;
}