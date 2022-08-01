// lab07 exercise 1
#include "../std_lib_facilities.h"

template<typename T>
struct S
{
private:
    T val;
public:
    S(const T& arg) { val = arg; }

    T& get();
    const T& get() const;

    S<T>& operator=(const T&); 

    friend istream& operator>>(istream& input, S<T>& s) 
    { 
        input >> s.val; 
        return input; 
    }
    
};

template<typename T>
T& S<T>::get() { return val; }

template<typename T>
const T& S<T>::get() const { return val; }

template<typename T>
S<T>& S<T>::operator=(const T& arg) { val = arg; return *this; }

// this does not work
template<typename T>
void read_val(T& v) 
{ 
    cout << "Enter a value: ";
    cin >> v;
}

int main()
{
    S<int> sint{1};
    S<char> schar{'c'};
    S<double> sdouble{1.1};
    S<string> sstring{"string"};
    S<vector<int>> svector{{1,2,3,4,5}};

    // This doesn't work when val is private
    // cout << "sint value: " << sint.val << endl
    //      << "schar value: " << schar.val << endl
    //      << "sdouble value: " << sdouble.val << endl
    //      << "sstring value: " << sstring.val << endl
    //      << "svector value: ";
    //      for (auto i : svector.val) {cout << i << " ";}
    //      cout << endl;

    cout << "sint value: " << sint.get() << endl
         << "schar value: " << schar.get() << endl
         << "sdouble value: " << sdouble.get() << endl
         << "sstring value: " << sstring.get() << endl
         << "svector value: ";
        for (auto i : svector.get()) {cout << i << " ";}
        cout << endl;

        sstring = "new string";
        cout << sstring.get() << endl;

        const string constr = sstring.get();
        cout << constr << endl;

        read_val(sint);
        read_val(schar);
        read_val(sdouble);
        read_val(sstring);

        cout << "sint value: " << sint.get() << endl
             << "schar value: " << schar.get() << endl
             << "sdouble value: " << sdouble.get() << endl
             << "sstring value: " << sstring.get() << endl;
}