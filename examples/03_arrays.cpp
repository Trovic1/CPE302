// 03 - Arrays: many values of the same type, reached by index (starts at 0)

#include <iostream>
using namespace std;

int main() {
    int scores[5] = {90, 85, 70, 60, 100};  // indices 0..4
    int size = 5;

    // Access by index
    cout << "First score: " << scores[0] << endl;   // 90
    cout << "Last score:  " << scores[4] << endl;    // 100

    // Loop over every element
    cout << "All scores: ";
    for (int i = 0; i < size; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    // Pattern: sum and average
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += scores[i];
    }
    double average = (double)total / size;
    cout << "Total = " << total << ", Average = " << average << endl;

    // Pattern: find the largest value
    int max = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] > max) max = scores[i];
    }
    cout << "Highest score = " << max << endl;

    return 0;
}
