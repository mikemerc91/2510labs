#include "../std_lib_facilities.h"

struct Test
{
  Test(const string& s) { cout << this << "->Test: " << s << endl; }
  ~Test() { cout << this << "->~Test" << endl; }
};

int main(int ac, char* av[])
{
    auto sp1 = make_shared<Test>("hello");
    auto sp2 = sp1;
    cout << "sp1 address: " << sp1.get() << endl
         << "sp2 address: " << sp2.get() << endl;

    sp1.reset();

    cout << "sp1 address: " << sp1.get() << endl
         << "sp2 address: " << sp2.get() << endl;

    auto up1 = make_unique<Test>("good morning");

    cout << "up1 address: " << up1.get() << endl;

    // throws an error, address of unique ptr can only be managed by one unique ptr
    //auto up2 = up1;
    // move transfers ownership of resources from up1 to up2
    auto up2 = move(up1);
    cout << "Move up1 to up2:\n"
         << "up1 address: " << up1.get() << endl
         << "up2 address: " << up2.get() << endl;
    // up1 now has nothing in it, address has been moved to up2
}