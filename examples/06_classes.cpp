// 06 - Classes and Objects (OOP)
// A class groups data (members) with the functions (methods) that work on it.
// An object is one instance created from a class.

#include <iostream>
#include <string>
using namespace std;

// Class with private data + a constructor + a method
class Student {
private:
    string name;
    string student_class;
    int    rownumber;
    double marks;

public:
    // Constructor: runs when an object is created, initializes the members
    Student(const string& name, const string& student_class, int rownumber, double marks)
        : name(name), student_class(student_class), rownumber(rownumber), marks(marks) {}

    string getName() { return name; }

    // Method uses the object's own data
    string calculateGrade() {
        if (marks >= 70)      return "A";
        else if (marks >= 60) return "B";
        else if (marks >= 50) return "C";
        else if (marks >= 40) return "D";
        else                  return "F";
    }
};

// Simpler class with public data
class BankAccount {
public:
    string name;
    int    balance;
};

int main() {
    // Using the Student class
    Student s("Trovic", "CPE302", 12, 84.5);
    cout << s.getName() << "'s grade: " << s.calculateGrade() << endl;

    // Using the BankAccount class
    BankAccount account;
    account.name = "John";
    account.balance = 1000;
    cout << account.name << " has $" << account.balance << endl;

    return 0;
}
