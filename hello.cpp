/* ============================================================================
   CPE 302 - C++ NOTES (all topics in one runnable file)

   This single file keeps every note and code example. Because a program can
   only have ONE main(), each topic lives in its own function, and main() shows
   a menu so you can run any topic you like.

   RUN IT:
       g++ hello.cpp -o hello && ./hello
   (or just:  ./run.sh)
   ========================================================================== */

#include <iostream>
#include <string>   // include this for using the string class
using namespace std;

/* ----------------------------------------------------------------------------
   TOPIC 1: switch...case vs if...else
   The distinguishing factor between switch-case and if...else:
   - with if...else you can combine different ranges and multiple conditions.
   - in switch-case you CAN'T check ranges and CAN'T have multiple conditions.
   - switch-case finds application where you have DISTINCT conditions.

   Program: take a number between 1 and 7 and print the corresponding weekday.
   This is suitable for switch-case (7 conditions with distinct output).
---------------------------------------------------------------------------- */
void weekdayDemo() {
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
        default:
            cout << "Invalid input! Please enter a number between 1 and 7." << endl;
    }
}

/* ----------------------------------------------------------------------------
   TOPIC 2: FOR LOOP
   - write a program to print "I am a cracked programmer" 5 times
   - write a program to print the multiplication table of 5
---------------------------------------------------------------------------- */
void forLoopDemo() {
    for (int i = 0; i < 5; i++) {
        cout << "I am a cracked programmer" << endl;
    }
    for (int i = 1; i <= 12; i++) {
        cout << "5 x " << i << " = " << 5 * i << endl;
    }
}

/* ----------------------------------------------------------------------------
   TOPIC 3: DO...WHILE LOOP
   Write a program to print "I am a programmer" until the user enters X.
   (do...while runs the body at least once.)
---------------------------------------------------------------------------- */
void doWhileDemo() {
    char input;
    do {
        cout << "I am a programmer" << endl;
        cout << "Enter 'X' to stop: ";
        cin >> input;
    } while (input != 'X' && input != 'x');
}

/* ----------------------------------------------------------------------------
   TOPIC 4: WHILE LOOP
   (while checks the condition BEFORE the body, so it may run zero times.)
---------------------------------------------------------------------------- */
void whileDemo() {
    char mychar;
    cout << "Enter a character: " << endl;
    cin >> mychar;
    while (mychar == 'x') {
        cout << "I am a cracked programmer. Enter a character again: ";
        cin >> mychar;
    }
}

/* ----------------------------------------------------------------------------
   TOPIC 5: POINTERS
   A pointer allows you to refer to the same space from a different location
   in memory.   Declaration form:   datatype *pointername
---------------------------------------------------------------------------- */
void pointerDemo() {
    int    *ip;
    double *dp;   // examples of other pointer types
    float  *fp;
    char   *cp;
    (void)dp; (void)fp; (void)cp;   // declared to show syntax; silence "unused" warnings

    int var = 5;
    ip = &var;
    cout << "Variable value: "             << var << endl;
    cout << "address in pointer: "         << ip  << endl;
    cout << "pointer pointing to value: "  << *ip << endl;

    *ip = 6;   // change var THROUGH the pointer
    cout << endl;
    cout << "Variable value: "             << var << endl;
    cout << "address in pointer: "         << ip  << endl;
    cout << "pointer pointing to value: "  << *ip << endl;
}

/* ----------------------------------------------------------------------------
   TOPIC 6: INTRODUCTION TO CLASSES AND OBJECTS
   Objects and classes are very important parts of C++; the original name of C++
   was "C with classes". Using objects in C++ is what is referred to as OOP,
   which is a way of grouping related data and the functions that work on it.
   This helps us think about, structure, and write programs more efficiently.
---------------------------------------------------------------------------- */

// --- A class with private data + a constructor + a method ---
class Cars {
private:
    // member variables (data members)
    string company_name;
    string model_name;
    string fuel_type;
    float  mileage;
    double price;
public:
    // member functions (methods)
    void setData(string c_name, string m_name, string f_type, float m, double p) {
        company_name = c_name;
        model_name   = m_name;
        fuel_type    = f_type;
        mileage      = m;
        price        = p;
    }
    void displayData() {   // uses the data members of the object
        cout << "The car properties are as follows:" << endl << endl;
        cout << "Car Company Name: " << company_name << endl;
        cout << "Model Name: "       << model_name   << endl;
        cout << "Car Fuel Type: "    << fuel_type    << endl;
        cout << "Mileage: "          << mileage      << endl;
        cout << "Car Price: "        << price        << endl;
    }
};

/* WRITING A PROGRAM TO WORK A BANK ACCOUNT
   There are many pieces of information needed to work a bank account. Each piece
   has a data type and a name: e.g. the account number is an int and the holder's
   name is a string. A class groups all of these together. */
class BankAccount {
public:
    string name;
    int    balance;
};

// --- A Student class: constructor + grade calculation (uses RANGES -> if/else) ---
class Student {
private:
    string name;
    string student_class;
    int    rownumber;
    double marks;
public:
    // constructor to initialize the data members of the class
    Student(const string& name, const string& student_class, int rownumber, double marks)
        : name(name), student_class(student_class), rownumber(rownumber), marks(marks) {}

    string getName() { return name; }

    string calculateGrade() {
        if (marks >= 70)      return "A";
        else if (marks >= 60) return "B";
        else if (marks >= 50) return "C";
        else if (marks >= 40) return "D";
        else                  return "F";
    }
};

void classesDemo() {
    // Cars
    Cars Car1;
    Car1.setData("Toyota", "Altis", "Petrol", 15.5, 150000);
    Car1.displayData();
    cout << endl;

    // BankAccount
    BankAccount Account1;
    Account1.name = "Trovic";
    Account1.balance = 1000;
    cout << Account1.name << " has $" << Account1.balance << endl;

    BankAccount account2;
    account2.name = "John";
    account2.balance = 500;
    cout << account2.name << " has $" << account2.balance << endl;
    cout << endl;

    // Student
    Student s("Trovic", "CPE302", 12, 84.5);
    cout << s.getName() << "'s grade: " << s.calculateGrade() << endl;
}

/* ----------------------------------------------------------------------------
   TOPIC 7: ARRAYS
   An array stores many values of the SAME type under one name. Each value is
   reached by an index that starts at 0 (so the last index is size - 1).
---------------------------------------------------------------------------- */
void arraysDemo() {
    int scores[5] = {90, 85, 70, 60, 100};   // indices 0..4
    int size = 5;

    cout << "First score: " << scores[0] << endl;   // 90
    cout << "Last score:  " << scores[4] << endl;    // 100

    cout << "All scores: ";
    for (int i = 0; i < size; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    // sum and average
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += scores[i];
    }
    double average = (double)total / size;
    cout << "Total = " << total << ", Average = " << average << endl;

    // find the largest value
    int max = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] > max) max = scores[i];
    }
    cout << "Highest score = " << max << endl;
}

/* ----------------------------------------------------------------------------
   TOPIC 8: FACTORIAL
   n! = n * (n-1) * ... * 2 * 1, and by definition 0! = 1.
   Shown both with a loop (iterative) and with recursion.
---------------------------------------------------------------------------- */
unsigned long long factorialRecursive(int n) {
    if (n <= 1) return 1;                       // base case stops the recursion
    return n * factorialRecursive(n - 1);       // recursive case
}

void factorialDemo() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return;
    }

    unsigned long long factorial = 1;           // big type: factorials grow fast
    for (int i = 1; i <= n; i++) {
        factorial *= i;                         // factorial = factorial * i
    }
    cout << n << "! = " << factorial << "  (loop)" << endl;
    cout << n << "! = " << factorialRecursive(n) << "  (recursion)" << endl;
}

/* ----------------------------------------------------------------------------
   MAIN: a simple menu so every topic above can be run from one program.
---------------------------------------------------------------------------- */
int main() {
    cout << "==== CPE 302 C++ Notes ====" << endl;
    cout << "1. switch...case (weekday)" << endl;
    cout << "2. for loop" << endl;
    cout << "3. do...while loop" << endl;
    cout << "4. while loop" << endl;
    cout << "5. pointers" << endl;
    cout << "6. classes and objects" << endl;
    cout << "7. arrays" << endl;
    cout << "8. factorial" << endl;
    cout << "Choose a topic (1-8): ";

    int choice;
    cin >> choice;
    cout << "---" << endl;

    switch (choice) {
        case 1: weekdayDemo();  break;
        case 2: forLoopDemo();  break;
        case 3: doWhileDemo();  break;
        case 4: whileDemo();    break;
        case 5: pointerDemo();  break;
        case 6: classesDemo();  break;
        case 7: arraysDemo();   break;
        case 8: factorialDemo(); break;
        default: cout << "Invalid choice." << endl;
    }
    return 0;
}
