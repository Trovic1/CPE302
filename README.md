# CPE 302 — C++ Programming Notes

A study guide for the class. Each topic has a short explanation and a small, **runnable** example.
The complete, compilable versions of every example live in the [`examples/`](examples/) folder.

## Getting started (for beginners)

**1. Install the tools (one time)**
- A C++ compiler — **g++**. On Windows install [MSYS2](https://www.msys2.org/) or MinGW; on Mac run `xcode-select --install`; on Linux run `sudo apt install g++`.
- **Git** — download from [git-scm.com](https://git-scm.com/downloads).

**2. Get the code onto your computer (clone the repo)**

Open a terminal (Git Bash on Windows) and run:
```bash
git clone https://github.com/Trovic1/CPE302.git
cd CPE302
```
That downloads everything into a folder called `CPE302` and moves you into it.

**3. Run the notes program**
```bash
g++ hello.cpp -o hello && ./hello
```
Then type a number `1–8` to run any topic. (On Windows you can also run `./run.sh`.)

**4. Run a single example instead**
```bash
g++ examples/04_factorial.cpp -o demo && ./demo
```

**5. Stay up to date** — to pull the latest notes later:
```bash
git pull
```

## Contents
1. [if…else vs switch…case](#1-ifelse-vs-switchcase)
2. [Loops: for, while, do…while](#2-loops-for-while-dowhile)
3. [Arrays](#3-arrays)
4. [Factorial](#4-factorial)
5. [Pointers](#5-pointers)
6. [Classes and Objects](#6-classes-and-objects)

---

## 1. if…else vs switch…case

Both are **control structures** — they let the program choose which code to run.

| Use `if…else` when…                          | Use `switch…case` when…                       |
| -------------------------------------------- | --------------------------------------------- |
| You need to test **ranges** (`marks >= 70`)  | You compare one variable against **distinct, fixed values** |
| You need to combine **multiple conditions** (`a > 0 && b < 5`) | Each value maps to one clear outcome |
| Conditions are complex / non-equality        | Values are `int` or `char` constants          |

**Key idea:** `switch` can only check whether a single variable *equals* specific constant values. It cannot test ranges (`< 50`) or combined conditions. When you have many *distinct* cases (like the 7 weekdays), `switch` is cleaner than a long `if…else` chain.

```cpp
// Print the weekday for a number 1–7. Distinct values -> switch is ideal.
int num;
cout << "Enter a number between 1 and 7: ";
cin >> num;

switch (num) {
    case 1: cout << "Monday";    break;
    case 2: cout << "Tuesday";   break;
    case 3: cout << "Wednesday"; break;
    case 4: cout << "Thursday";  break;
    case 5: cout << "Friday";    break;
    case 6: cout << "Saturday";  break;
    case 7: cout << "Sunday";    break;
    default: cout << "Invalid input! Enter 1-7.";
}
```

> `break` stops the switch after a match. Without it, execution "falls through" into the next case.
> `default` runs when no case matches (like the final `else`).

The same problem with ranges — e.g. grading — *must* use `if…else` because `switch` cannot test `marks >= 70`:

```cpp
if (marks >= 70)      grade = "A";
else if (marks >= 60) grade = "B";
else if (marks >= 50) grade = "C";
else if (marks >= 40) grade = "D";
else                  grade = "F";
```

Full example: [`examples/01_switch_vs_if.cpp`](examples/01_switch_vs_if.cpp)

---

## 2. Loops: for, while, do…while

A loop repeats a block of code. Pick the loop by **when you know the repeat count**.

| Loop        | Use when…                                            |
| ----------- | ---------------------------------------------------- |
| `for`       | You know how many times to repeat (counting)         |
| `while`     | You repeat *while* a condition is true (may run 0 times) |
| `do…while`  | Same, but the body must run **at least once**        |

**`for` loop** — repeat a known number of times:
```cpp
// Print a message 5 times
for (int i = 0; i < 5; i++) {
    cout << "I am a cracked programmer" << endl;
}

// Multiplication table of 5
for (int i = 1; i <= 12; i++) {
    cout << "5 x " << i << " = " << 5 * i << endl;
}
```
The three parts of a `for`: `for (initialization; condition; update)`.

**`while` loop** — checks the condition *before* each run, so it may run zero times:
```cpp
char mychar = 'x';
while (mychar == 'x') {
    cout << "Enter a character (x to keep looping): ";
    cin >> mychar;
}
```

**`do…while` loop** — checks the condition *after* the body, so it always runs at least once:
```cpp
char input;
do {
    cout << "I am a programmer" << endl;
    cout << "Enter 'X' to stop: ";
    cin >> input;
} while (input != 'X' && input != 'x');
```

Full example: [`examples/02_loops.cpp`](examples/02_loops.cpp)

---

## 3. Arrays

An **array** stores many values of the **same type** under one name. Each value is reached by an **index** that starts at `0`.

```cpp
int scores[5] = {90, 85, 70, 60, 100};  // 5 ints, index 0..4

cout << scores[0];   // first  element -> 90
cout << scores[4];   // last   element -> 100
scores[1] = 88;      // change the second element
```

**Looping over an array** (the index goes from `0` to `size - 1`):
```cpp
int scores[5] = {90, 85, 70, 60, 100};
int size = 5;

int total = 0;
for (int i = 0; i < size; i++) {
    total += scores[i];          // add each element
}
double average = (double)total / size;
cout << "Average = " << average << endl;
```

**Things to remember**
- Indexing starts at **0**; the last valid index is `size - 1`.
- Going out of bounds (e.g. `scores[5]` above) is undefined behaviour — C++ does **not** check for you.
- The size is fixed when the array is created.
- A `string` can be treated like an array of `char`: `name[0]` is its first letter.

Common patterns — find the **largest** value:
```cpp
int max = scores[0];
for (int i = 1; i < size; i++) {
    if (scores[i] > max) max = scores[i];
}
```

Full example: [`examples/03_arrays.cpp`](examples/03_arrays.cpp)

---

## 4. Factorial

The factorial of `n` (written `n!`) is the product of all integers from `1` to `n`.
`5! = 5 × 4 × 3 × 2 × 1 = 120`. By definition `0! = 1`.

**Approach 1 — using a loop (iterative):**
```cpp
int n;
cout << "Enter a number: ";
cin >> n;

unsigned long long factorial = 1;   // big type: factorials grow fast
for (int i = 1; i <= n; i++) {
    factorial *= i;                 // factorial = factorial * i
}
cout << n << "! = " << factorial << endl;
```

**Approach 2 — using recursion** (a function that calls itself):
```cpp
unsigned long long factorial(int n) {
    if (n <= 1) return 1;            // base case: stops the recursion
    return n * factorial(n - 1);     // recursive case
}
```

> **Why `unsigned long long`?** Factorials explode in size — `21!` already overflows a 64-bit
> integer. For class exercises with small `n` this type is plenty.
> Always handle `n = 0` (answer is `1`) and reject negative input.

Full example: [`examples/04_factorial.cpp`](examples/04_factorial.cpp)

---

## 5. Pointers

A **pointer** is a variable that stores the **memory address** of another variable.
It lets you refer to the same storage from a different place in memory.

```cpp
int  var = 5;
int *ip;        // ip is a pointer to an int  (datatype *name)

ip = &var;      // &var = "address of var"

cout << var;    // value of var        -> 5
cout << ip;     // address stored in ip -> e.g. 0x7ffd...
cout << *ip;    // value AT that address (dereference) -> 5

*ip = 6;        // change var THROUGH the pointer
cout << var;    // -> 6  (var changed!)
```

Two key operators:
- `&x` — the **address of** `x`.
- `*p` — **dereference**: the value stored at the address `p` holds.

Full example: [`examples/05_pointers.cpp`](examples/05_pointers.cpp)

---

## 6. Classes and Objects

C++ was originally called *"C with classes."* A **class** groups related **data** (member
variables) and the **functions** that work on that data (member functions / methods). This style
of programming is called **OOP** (Object-Oriented Programming). An **object** is one concrete
instance created from a class.

- `private:` members can only be used *inside* the class (data hiding).
- `public:` members can be used from *outside* (the interface).
- A **constructor** has the same name as the class and runs automatically when an object is created — it initializes the data.

```cpp
class Student {
private:
    string name;
    string student_class;
    int    rownumber;
    double marks;

public:
    // Constructor: initializes members via an initializer list
    Student(const string& name, const string& student_class, int rownumber, double marks)
        : name(name), student_class(student_class), rownumber(rownumber), marks(marks) {}

    // Method: uses the object's own data, returns a letter grade
    string calculateGrade() {
        if (marks >= 70)      return "A";
        else if (marks >= 60) return "B";
        else if (marks >= 50) return "C";
        else if (marks >= 40) return "D";
        else                  return "F";
    }
};

int main() {
    Student s("Trovic", "CPE302", 12, 84.5);   // create an object
    cout << "Grade: " << s.calculateGrade();    // -> A
    return 0;
}
```

A simpler class with public data (a bank account):
```cpp
class BankAccount {
public:
    string name;
    int    balance;
};

BankAccount account;
account.name = "Trovic";
account.balance = 1000;
cout << account.name << " has $" << account.balance;
```

Full example: [`examples/06_classes.cpp`](examples/06_classes.cpp)

---

### Quick reference
- Include only the headers your program uses, such as `#include <iostream>` for input/output and `#include <string>` for `string`.
- `using namespace std;` is optional; it brings every name in `std` into the current scope and can cause naming conflicts in larger programs. You can write `std::cout`, `std::cin`, and `std::string` instead.
- Reaching the end of `main()` is the same as `return 0;`. Returning `0` explicitly is still useful because it clearly tells the operating system that the program succeeded; non-zero return values signal failure or another status to scripts and larger programs.
- `cout <<` prints; `cin >>` reads input; `endl` (or `"\n"`) starts a new line.
