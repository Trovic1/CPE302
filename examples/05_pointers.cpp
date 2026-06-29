// 05 - Pointers: a variable that stores the memory address of another variable
// &x  -> address of x      *p -> value stored at the address p holds (dereference)

#include <iostream>
using namespace std;

int main() {
    int  var = 5;
    int *ip;          // ip is a pointer to an int: datatype *name

    ip = &var;        // store the address of var in ip

    cout << "Variable value:            " << var << endl;   // 5
    cout << "Address held by pointer:   " << ip  << endl;   // e.g. 0x7ffd...
    cout << "Value via the pointer:     " << *ip << endl;   // 5

    *ip = 6;          // change var THROUGH the pointer

    cout << "\nAfter *ip = 6:" << endl;
    cout << "Variable value:            " << var << endl;   // 6 (var changed!)
    cout << "Value via the pointer:     " << *ip << endl;   // 6

    return 0;
}
