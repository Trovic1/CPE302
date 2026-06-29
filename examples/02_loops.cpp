// 02 - Loops: for, while, do...while

#include <iostream>
using namespace std;

int main() {
    // --- for loop: repeat a known number of times ---
    for (int i = 0; i < 5; i++) {
        cout << "I am a cracked programmer" << endl;
    }

    cout << "---" << endl;

    // for loop: multiplication table of 5
    for (int i = 1; i <= 12; i++) {
        cout << "5 x " << i << " = " << 5 * i << endl;
    }

    cout << "---" << endl;

    // --- while loop: condition checked BEFORE the body (may run 0 times) ---
    char mychar = 'x';
    while (mychar == 'x') {
        cout << "Enter a character (x to keep looping): ";
        cin >> mychar;
    }

    // --- do...while loop: body runs AT LEAST once ---
    char input;
    do {
        cout << "I am a programmer" << endl;
        cout << "Enter 'X' to stop: ";
        cin >> input;
    } while (input != 'X' && input != 'x');

    return 0;
}
