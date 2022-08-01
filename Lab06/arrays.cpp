// lab 6 exercise 1.1-1.10
#include "../std_lib_facilities.h"

ostream& print_array10(ostream& os, int* a)
{
    for (int i=0; i<10; ++i) {
        os << a[i] << " ";
    }
    os << endl;
    return os;
}

ostream& print_array(ostream& os, int* a, int n)
{
    for (int i=0; i<n; ++i) {
        os << a[i] << " ";
    }
    os << endl;
    return os;
}

ostream& print_vector(ostream& os, vector<int*> a)
{
    for (int i=0; i<a.size(); ++i) {
        os << *a[i] << " ";
    }
    os << endl;
    return os;
}

int main()
{
    int* numbers = new int[10]{1,2,3,4,5,6,7,8,9,10};
    for (int i=0; i<10; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    delete[] numbers;

    int* numbers2 = new int[10]{100,101,102,103,104,105,106,107,108,109};
    int* numbers3 = new int[11]{100,101,102,103,104,105,106,107,108,109,110};
    int* numbers4 = new int[20]{100,101,102,103,104,105,106,107,108,109,
                                110,111,112,113,114,115,116,117,118,119};
    
    print_array10(cout, numbers2);
    print_array10(cout, numbers3);
    print_array(cout, numbers3, 11);
    print_array(cout, numbers4, 20);
    
    delete[] numbers2;
    delete[] numbers3;
    delete[] numbers4;

    vector<int*> numbers5;
    for (int i=100; i<110; ++i) { numbers5.push_back(new int(i));}
    vector<int*> numbers6;
    for (int i=100; i<111; ++i) { numbers6.push_back(new int(i));}
    vector<int*> numbers7;
    for (int i=100; i<120; ++i) { numbers7.push_back(new int(i));}

    print_vector(cout, numbers5);
    print_vector(cout, numbers6);
    print_vector(cout, numbers7);

    for (int i=0; i<numbers5.size(); ++i) { delete numbers5[i]; }
    for (int i=0; i<numbers6.size(); ++i) { delete numbers6[i]; }
    for (int i=0; i<numbers7.size(); ++i) { delete numbers7[i]; }                            
}