#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>

using namespace std;


template <typename T, class... FilterFuncs>
T getValue(FilterFuncs... funcs) {
    T value;
    bool isValid = false;

    while (!isValid) {
        if (!(cin >> value)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid value." << endl;
        } else if (!(... && funcs(value))) {
            cout << "Invalid input. Please enter a valid value." << endl;
        } else {
            isValid = true;
        }
    }
    return value;
}

#endif // UTILS_H