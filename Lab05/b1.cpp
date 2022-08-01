// lab 5 exercise 1
#include "../std_lib_facilities.h"

class B1
{
public:
B1() {};
virtual void pvf() const = 0; // B1 is now an abstract class, cannot be instantiated
virtual void vf() const { cout << "B1::vf()\n"; }
void f() const { cout << "B1::f()\n"; }
};

class B2
{
public:
    B2() {};
    virtual void pvf() const = 0;
};

class D1 : public B1 // D1 needs to override pvf() in B1 to be instantiated
{
public:
    D1() : B1() {}
    void vf() const override { cout << "D1::vf()\n"; }
    void f() const { cout << "D1::f()\n"; }
};

class D2 : public D1
{
public:
    D2() : D1() {}
    void pvf() const override { cout << "D2::pvf()\n"; }
};

class D21 : public D2
{
public:
    D21() {}
    D21(string word) : d21String{word} {}
    void pvf() const override { cout << d21String; }
private:
    string d21String;
};

class D22 : public D2
{
public:
    D22() {}
    D22(int number) : d21Int{number} {} 
    void f(const B2& b2) { b2.pvf(); }
private:
    int d21Int;
};

int main()
{
    // cout << "B1" << endl;
    // B1 b1;  
    // b1.pvf();
    // b1.vf();
    // b1.f();
    // cout << endl; // calls both functions from B1

    // cout << "D1" << endl;
    // D1 d1; // D1 is abstract until pvf() is overridden
    // d1.pvf();
    // d1.vf();
    // d1.f();
    // cout << endl; // calls overridden vf() from D1 and D1 member function f()

    // cout << "b1_ref" << endl;
    // const B1& b1_ref = other;
    // b1_ref.pvf();
    // b1_ref.vf();
    // b1_ref.f();
    // cout << endl; // b1_ref is not a D1 object, calls overridden D1 vf()
    // other has no overridden f(), calls f() from B1 class

    cout << "D2" << endl;
    D2 d2;
    d2.pvf();
    d2.vf();
    d2.f();
    cout << endl;

    cout << "D21" << endl;
    D21 d21;
    d21.f();
    cout << endl << "D22" << endl;
    D22 d22;
    B2 b2; // b2 is abstract class, cannot be initialized
    d22.f(b2); // cannot be called
    

}