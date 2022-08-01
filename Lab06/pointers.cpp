// lab 6 exercise 2.1-2.13
#include "../std_lib_facilities.h"

ostream& print_array(ostream& os, int* a, int n)
{
    for (int i=0; i<n; ++i) {
        os << a[i] << " ";
    }
    os << endl;
    return os;
}

int main()
{
    int* p1 = new int(7);
    cout << "Value of p1: " << p1 << " What it points to: " << *p1 << endl;

    int* p2 = new int[7] {1,2,4,8,16,32,64};
    cout << "Value of p2: " << p2 << " What it points to: " << *p2 << endl; // only prints first value like this

    int* p3{p2};
    p2 = p1;
    p2 = p3;

    cout << "Value of p1: " << p1 << " What it points to: " << *p1 << endl;
    cout << "Value of p2: " << p2 << " What it points to: " << *p2 << endl;
    cout << "Value of p3: " << p3 << " What it points to: " << *p3 << endl;

    delete p1; delete[] p2;

    int* p11 = new int[10] {1,2,4,8,16,32,64,128,256,512};
    int* p22 = new int[10];
    copy(p11,p11+10,p22);

    cout << "Value of p11: " << p11 << " What it points to: ";
    for (int i=0; i<10; ++i) {
        cout << p11[i] << " ";
    }
    cout << endl;
    cout << "Value of p22: " << p22 << " What it points to: ";
    for (int i=0; i<10; ++i) {
        cout << p22[i] << " ";
    }
    cout << endl;

    vector<int>* v11 = new vector<int> {1,2,4,8,16,32,64,128,256,512};
    vector<int>* v22 = new vector<int>;
    for (auto x : *v11) { v22->push_back(x); }

    cout << "Value of v11: " << v11 << " What it points to: ";
    for (int i=0; i<10; ++i) {
        cout << (*v11)[i] << " ";
    }
    cout << endl;
    cout << "Value of v22: " << v22 << " What it points to: ";
    for (int i=0; i<10; ++i) {
        cout << (*v22)[i] << " ";
    }
    cout << endl;
}