//
// Created by Bohdan on 25.11.2023.
//

#include <iostream>
#include <iomanip>
#include "../../utils/utils.h"

using namespace std;


char getFillMethod() {
    cout << "Available fill methods:\n";
    cout << " 'r' - random" << endl;
    cout << " 'm' - manual" << endl;
    char method;
    method = getValue<char>([](char val) {
        return (val == 'r' || val == 'm');
    });
    return method;
}


