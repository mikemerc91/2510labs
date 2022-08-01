#include "../std_lib_facilities.h"

struct X {    // simple test class
    int val;

    void out(const string& s, int nv) {
        cerr << this << "->" << s << ": " << val << " (" << nv << ")\n";
    }

    X() { out("X()",0); val=0; }                      // default constructor
    X(int v) { val=v; out( "X(int)",v); }
    X(const X& x){ val=x.val; out("X(X&) ",x.val); }  // copy constructor
    X& operator=(const X& a) {                        // copy assignment
        out("X&::operator=()",a.val); val=a.val; return *this;
    }
    X(X&& x){ val=x.val; out("X(X&&) ",x.val); }  // move constructor
    X& operator=(X&& a) {                         // move assignment
        out("X&&::operator=()",a.val); val=a.val; return *this;
    }
    ~X() { out("~X()",0); }                           // destructor
};

X glob(2);    // a global variable

X copy(X a) { return a; }

X copy2(X a) { X aa = a; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) { X a(i); return new X(a); }

struct XX { X a; X b; };

int main()
{
  cout << "Line 1\n";
  X loc {4};            // local variable
  cout << "Line 2\n";
  X loc2 {loc};         // copy construction
  cout << "Line 3\n";
  loc = X{5};           // move assignment
  cout << "Line 4\n";
  loc2 = copy(loc);     // call by value and return
  cout << "Line 5\n";
  loc2 = copy2(loc);    // copy or move?
  cout << "Line 6\n";
  X loc3 {6};
  cout << "Line 7\n";
  X& r = ref_to(loc);   // call by reference and return
  cout << "Line 8\n";
  delete make(7);
  cout << "Line 9\n";
  delete make(8);
  cout << "Line 10\n";
  vector<X> v(4);       // default values
  cout << "Line 11\n";
  XX loc4;
  cout << "Line 12\n";
  X* p = new X{9};      // an X on the free store
  cout << "Line 13\n";
  delete p;
  cout << "Line 14\n";
  X* pp = new X[5];     // an array of Xs on the free store
  cout << "Line 15\n";
  delete[] pp;
  cout << "Line 16\n";
}