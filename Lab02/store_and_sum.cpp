// lab2 exercise 3.6-3.7
#include "../std_lib_facilities.h"

vector<double> numbers, differences;
double n, sum=0;
string val;
bool done = false;

int main()
{
    cout << "Please enter the number of values you want to sum: \n";
    cin >> n;
    cout << "Please enter some integers (enter | to stop): \n";

    while (!done) {
        cin >> val;
        if (val == "|") {
            if (n > numbers.size()) {
                cout << "Please enter more numbers: \n";
                continue;
            } else {
                done = true;
                break;
            }
        }
        numbers.push_back(stod(val));
    }
    cout << "The sum of the first " << n << " numbers ( ";
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
        cout << numbers[i] << " ";
        if (i != n-1) {
            double diff = numbers[i] - numbers[i + 1];
            differences.push_back(diff);
        }
    }
    cout << ") is " << sum << ".\n";

    cout << "Differences: ";
    for (int i = 0; i < n-1; i++) {
        cout << differences[i] << " ";
    }
    cout << "\n";
    return 0;
}
    