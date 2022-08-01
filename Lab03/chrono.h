// lab 3 exercise 3
#ifndef __DATE_H
#define __DATE_H

#include "../std_lib_facilities.h"

namespace Chrono
{
    enum class Month {
        JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
    };

    class InvalidDate
    {
        string reason;

    public:
        InvalidDate(string input) 
        {
            reason = input;
        }
    
        InvalidDate() { reason = "Unspecified"; }

        string message() 
        {
            return "InvalidDate Exception: " + reason;
        }  
    };

    class Date
    {
        int y, d;
        Month m;

    public:
        Date(int yy, Month mm, int dd)
        {
            if (!isValid(yy,mm,dd)) { throw InvalidDate("Invalid date provided."); }
            y = yy;
            m = mm;
            d = dd;
        }

        Date()
        {
            y = 1970;
            m = Month::JAN;
            d = 1;
        }

        int year() const {return y; }
        Month month() const {return m; }
        int day() const {return d; }

        void addDay() { d++; }

        string toString() // TIP: use to_string(a) to convert integer a to a string
        { 

            int month = static_cast<int>(m);
            string yearString = to_string(y);
            string monthString = (month<10) ? "0"+to_string(month) : to_string(month);
            string dayString = (d<10) ? "0"+to_string(d) : to_string(d);
            return yearString + "-" + monthString + "-" + dayString;
        }

        bool isValid(int yy, Month mm, int dd) 
        {
            if (yy < 1) {return false;}
            if (dd < 1) {return false;}
            switch (mm) {
            case Month::APR: case Month::JUN: case Month::SEP: case Month::NOV:
                if (dd > 30) {return false;}
            case Month::FEB:
                if (leapYear(yy)) {
                    if (dd > 29) {return false;}    
                }
                else if (dd > 28) {return false;}
            default:
                if (dd > 31) {return false;}
            }
            return true;
        }

        bool leapYear(int y)
        {
            if (y % 4 != 0) {return false;}
            else if (y % 100 != 0) {return true;}
            else if (y % 400 != 0) {return false;}
            else {return true;}
        }
    };
}
#endif