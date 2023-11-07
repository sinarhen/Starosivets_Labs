/* before lab_06 */

// #include <iostream>

// using namespace std;

// template <class... FilterFuncs>
// string getValue(FilterFuncs... funcs);

// template <class... FilterFuncs>
// string getValue(FilterFuncs... funcs) {
//     string value;
//     while (true) {
//         cin >> value;
//         if (!(... && funcs(value))) {
//             cout << "Invalid input. Please enter a valid value." << endl;
//         } else {
//             break;
//         }
//     }
//     return value;
// }

/* AFTER lab_06 */
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
