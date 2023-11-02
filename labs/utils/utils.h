#include <iostream>

using namespace std;

template <class... FilterFuncs>
string getValue(FilterFuncs... funcs);

template <class... FilterFuncs>
string getValue(FilterFuncs... funcs) {
    string value;
    while (true) {
        cin >> value;
        if (!(... && funcs(value))) {
            cout << "Invalid input. Please enter a valid value." << endl;
        } else {
            break;
        }
    }
    return value;
}
