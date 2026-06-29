// 01 - switch...case vs if...else
// switch: best for DISTINCT, fixed values (e.g. the 7 weekdays).
// if...else: needed for RANGES and combined conditions (e.g. grading).

#include <iostream>
#include <string>
using namespace std;

int main() {
    // --- switch...case: map a number 1-7 to a weekday (distinct values) ---
    int num;
    cout << "Enter a number between 1 and 7: ";
    cin >> num;

    switch (num) {
        case 1: cout << "Monday"    << endl; break;
        case 2: cout << "Tuesday"   << endl; break;
        case 3: cout << "Wednesday" << endl; break;
        case 4: cout << "Thursday"  << endl; break;
        case 5: cout << "Friday"    << endl; break;
        case 6: cout << "Saturday"  << endl; break;
        case 7: cout << "Sunday"    << endl; break;
        default: cout << "Invalid input! Please enter a number between 1 and 7." << endl;
    }

    // --- if...else: grading needs RANGES, which switch cannot do ---
    double marks;
    cout << "Enter your marks (0-100): ";
    cin >> marks;

    string grade;
    if (marks >= 70)      grade = "A";
    else if (marks >= 60) grade = "B";
    else if (marks >= 50) grade = "C";
    else if (marks >= 40) grade = "D";
    else                  grade = "F";

    cout << "Grade: " << grade << endl;
    return 0;
}
