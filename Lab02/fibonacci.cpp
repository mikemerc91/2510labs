// lab2 exercise 3.8
#include "../std_lib_facilities.h"

int n, counter = 0, val = 1;
vector<int> fibs;

int main() 
{
    cout << "Enter the length of the Fibonacci sequence: ";
    cin >> n;
    for (int i=0; i<n; i++) {
        if (i < 2) {
            fibs.push_back(val);
        }
        else {
            val += fibs[i-2];
            fibs.push_back(val);
        }
        cout << fibs[i] << " ";
    }
    cout << "\n";
    return 0;
}
