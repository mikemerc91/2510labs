// lab7 exercise 2.1-2.4
#include "../std_lib_facilities.h"

int ga[10] = {1,2,4,8,16,32,64,128,256,512};

void f(int [], int);

int main()
{
    f(ga,10);
    int aa[10]{1,2,6,24,120,720,5040,40320,362880,3628800};
    f(aa,10);
}

void f(int array[], int n)
{
    int la[10];
    copy(ga,ga+10,la);
    cout << "Elements of la: ";
    for (int i=0;i<10;++i) { cout << la[i] << " ";}
    cout << endl;

    int* p = new int[n];
    copy(array,array+n,p);
    cout << "Elements of p: ";
    for (int i=0;i<n;++i) { cout << p[i] << " ";}
    cout << endl;
    delete[] p;
}