// lab 1 exercise 5
// read and write a first name
#include "../std_lib_facilities.h"
int main()
{
    cout << "Enter the name of the person you want to write to:\n";
    string first_name; // first name is variable of type string
    cin >> first_name;
    cout << "Dear " << first_name << ",\n";
    cout << "    How are you? I like Chinese food. I like pizza pie.\n";
    string friend_name;
    cout << "Enter a friend's name: ";
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " recently?\n";

    char fav_sport = 's';

    cout << "Enter an 'h' if " << friend_name << "'s favorite sport is hockey.\n";
    cout << "Enter a 'b' if " << friend_name << "'s favorite sport is basketball.\n";
    cin >> fav_sport;

    if (fav_sport == 'h') {
        cout << "Wrong, " << friend_name << ", I think you'll find it's soccer.\n";
    }
    if (fav_sport == 'b') {
        cout << friend_name << ", we are no longer friends. That's even worse than hockey.\n";
    }

    int age;
    cout << "Enter recipient's age: ";
    cin >> age;
    cout << "I hear you just had a birthday and you are " << age << " years old.\n";

    if (age <= 0 || age >= 110) {
        simple_error("you're kidding!");
    }

    if (age < 12) {
        cout << "Next year you will be " << age+1 << ".\n";
    }
    if (age == 17) {
        cout << "Next year you will be able to vote.\n";
    }
    if (age >= 70) {
        cout << "I hope you're enjoying retirement.\n";
    }

    cout << "Yours sincerely, \n\nAbraham Lincoln\n";



}