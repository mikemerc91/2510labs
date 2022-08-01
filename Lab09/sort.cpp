// lab 9 exercise 2
#include "../std_lib_facilities.h"

vector<int> v1{1,11,111,12,112,13,113,14,15,151,2,22,222,21,221,223,224,262,272,3};
vector<int> v2{4,41,441,42,433,45,444,446,447,449,5,54,553,56,557,58,559,59,57,6};
vector<int> v3{7,77,777,71,72,73,771,717,79,8,81,883,885,84,87,88,9,91,999,97};

int main()
{
    //sort v1 from smallest to largest
    cout << "v1:" << endl;
    for (auto i : v1) { cout << i << " "; }
    cout << endl;
    std::sort(v1.begin(), v1.end(), [](int x, int y){ return x < y; }); 
    for (auto i : v1) { cout << i << " "; }
    cout << endl;

    //sort v2 by number of digits, longest to shortest, in a number but not by value
    cout << "v2:" << endl;
    for (auto i : v2) { cout << i << " "; }
    cout << endl;
    std::sort(v2.begin(), v2.end(), [](int x, int y)
        { return (to_string(x).size() > to_string(y).size()); }); 
    for (auto i : v2) { cout << i << " "; }
    cout << endl;

    // //sort v3 like v2 but from smallest to largest as well
    cout << "v3:" << endl;
    for (auto i : v3) { cout << i << " "; }
    cout << endl;
    std::sort(v3.begin(), v3.end(), [](int x, int y)
        { 
            if (to_string(x).size() == to_string(y).size()) { return x < y; }
            else return (to_string(x).size() > to_string(y).size());
        });
    for (auto i : v3) { cout << i << " "; }
    cout << endl; 
}