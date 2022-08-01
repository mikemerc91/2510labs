// lab 4 exercise 4
#include "../std_lib_facilities.h"

struct MonthTemp 
{
    string month, year;
    vector<int> temps;

    friend istream &operator>>(istream &input, MonthTemp &mt) 
    {
        string line;
        getline(input, line);
        istringstream iss(line);

        string month, year;
        vector<int> temps;
        iss >> month >> year;
        for (int t; iss >> t;) {
            temps.push_back(t);
        }
        mt = MonthTemp{month, year, temps};
        return input;
    }
};

int main()
{   
    vector<MonthTemp> monthTemps;
    string tempDataFile{"monthTemp.txt"};
    ifstream ist{tempDataFile};
    MonthTemp mt;
    while (ist >> mt) {
        monthTemps.push_back(mt);
    }
    for (MonthTemp mt : monthTemps) {
        double sum=0;
        cout << "Month: " << mt.month << "\nYear: " << mt.year << endl;
        cout << "Temps recorded: " << mt.temps.size() << endl;
        cout << "Average temp: ";
        for (double i : mt.temps) {
            sum += i;
        }
        cout << sum/mt.temps.size() << endl;
    }
}