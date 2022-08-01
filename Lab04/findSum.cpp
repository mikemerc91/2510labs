// lab 4 exercise 2
#include "../std_lib_facilities.h"

int main()
{
    int temp=0,sum=0;
    string word;
    ifstream ist;
    ist.open("bears.txt");
    if (!ist) error("Can't open input file.");
    while (ist >> word) {
        try {
            temp = stoi(word);
        }
        catch (...) {
            continue;
        }
        sum += temp;
    }
    cout << "Sum: " << sum << endl;
}