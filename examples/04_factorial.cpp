// 04 - Factorial: n! = n * (n-1) * ... * 2 * 1, and 0! = 1
// Shows both the loop (iterative) and recursive approaches.

#include <iostream>
using namespace std;

// Recursive version: a function that calls itself
unsigned long long factorialRecursive(int n) {
    if (n <= 1) return 1;                  // base case stops the recursion
    return n * factorialRecursive(n - 1);  // recursive case
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 0;
    }

    // Iterative version using a for loop
    unsigned long long factorial = 1;      // big type: factorials grow fast
    for (int i = 1; i <= n; i++) {
        factorial *= i;                    // factorial = factorial * i
    }

    cout << n << "! = " << factorial << "  (loop)" << endl;
    cout << n << "! = " << factorialRecursive(n) << "  (recursion)" << endl;
    return 0;
}
