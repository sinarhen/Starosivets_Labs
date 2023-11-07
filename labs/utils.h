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

using namespace std;


template <typename T, class... FilterFuncs>
T getValue(FilterFuncs... funcs) {
    T value;
    while (true) {
        cin >> value;
        if (!(... && funcs(value))) {
            cout << "Invalid input. Please enter a valid value." << endl;
        } else if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid value." << endl;
        } else {
            return value;
        }
    }
}

#endif // UTILS_H
