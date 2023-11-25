#include "../../filters/filters.h"
#include "../../utils/utils.h"

using namespace std;

int getSize() {
    int val = getValue<int>(isMoreThanOne);
    return val;
}

char getFillMethod() {
    cout << "Available methods";
    cout << " 'r' - random" << endl;
    cout << " 'm' - manual" << endl;
    char method;
    method = getValue<char>([](char val) {
        return (val == 'r' || val == 'm');
    });
    return method;
}


