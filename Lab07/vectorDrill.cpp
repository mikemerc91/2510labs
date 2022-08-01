// lab 7 exercise 3.1-3.4
#include "../std_lib_facilities.h"

vector<int> gv{1,2,4,8,16,32,64,128,256,512};

void f(vector<int>);

int main()
{
    f(gv);
    vector<int> vv{1,2,6,24,120,720,5040,40320,362880,3628800};
    f(vv);
}

void f(vector<int> v)
{
    vector<int> lv(gv.size());
    copy(gv.begin(),gv.end(),lv.begin());
    cout << "Elements of lv: ";
    for (auto i: lv) { cout << i << " ";}
    cout << endl;

    vector<int> lv2{v};
    cout << "Elements of lv2: ";
    for (auto i: lv2) { cout << i << " ";}
    cout << endl;
}