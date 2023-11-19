#include <iostream>
#include "../utils/utils.h"
#include <string.h>


using namespace std;



int main(void){
    float x, z, res;
    
    std::cout << "---Lab 02. First task. Starosivets Bohdan---"<< endl;
    cout << "Enter X: ";
    getValue(x);

    cout << "Enter Z: ";
    getValue(z);
    std:: cout << "\n\n";

    if (x > 0 && z > 0 && x != z)
    {   
        std:: cout << "Condition: x > 0, z > 0, x != z" << endl;
        res = (x-z)/(x+z);
    } else if (x == 0)
    {
        std:: cout << "Condition: x = 0" << endl;
        res = 2 * x + 5 * z;
    } else {
        res = 1;
    }

    cout << "Result is: " << res << endl;

    return 0;
}

