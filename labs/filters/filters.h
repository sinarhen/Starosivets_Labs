#include <iostream>
#include <cctype>

using namespace std;

bool isNumeric(string value){
    for (char c : value) {
        if (isalpha(c) && c != '-' && c != '.') {
            cout << "All characters must be digits" << endl;
            return false;
        }
    }
    return true;
}

bool isMoreThanOne(string value)
{
    if (stoi(value) < 1 ){
        cout << "Value must be more than one" << endl;
        return false;
    };
    return true;
}
