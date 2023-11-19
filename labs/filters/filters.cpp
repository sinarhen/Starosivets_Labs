#include <iostream>

using namespace std;

bool isMoreThanOne(int val)
{
    if (val < 1 ){
        cout << "Value must be more than one" << endl;
        return false;
    };
    return true;
}