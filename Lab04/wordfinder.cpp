// lab 4 exercise 3
#include "../std_lib_facilities.h"

int main()
{
    string myFile{"wordfinder.txt"}, searchWord{"chinese"}, line, word;
    ifstream ist{myFile};
    int i=1;
    while (getline(ist, line)) {
        istringstream iss{line};
        while (iss >> word) {
            if (word==searchWord) {
                cout << "Line " << i << ": " << line << endl;
            }
        }
        ++i;
    } 


}