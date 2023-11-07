#include <iostream>
#include "../../filters/filters.h"
#include "../../utils/utils.h"

using namespace std;

int getSize() {
    int val = getValue<int>(isMoreThanOne);
    return val;
}

char getYesOrNo() {
    char response;
    cin >> response;
    return response;
}

char getFillMethod() {
    char method;
    method = getValue<char>([](char val) {
        return (val == 'r' || val == 'm');
    });
    return method;
}


