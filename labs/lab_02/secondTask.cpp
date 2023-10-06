#include <iostream>
#include "../localutils.h"
#include <string.h>

using namespace std;

bool is_more_than_zero(string val);

int main(void){
    double a, b, c, d;
    
    std:: cout << "---Lab 02. Second task. Starosivets Bohdan---"<< endl;

    
    a = stod(getValue("Enter A:", is_more_than_zero));
    b = stod(getValue("Enter B:", is_more_than_zero));
    c = stod(getValue("Enter C:", is_more_than_zero));
    d = stod(getValue("Enter D:", is_more_than_zero));

    std:: cout << "\n\n";

    // Перевірка умови розташування прямокутника a, b всередині прямокутника c, d
    if ((a <= c && b <= d) || (a <= d && b <= c)) {
        std::cout << "Rectangle with sides: " << a << " and " << b << " can be placed inside rectangle with sides: " << c << " and " << d << ".\n";
    } else {
        std::cout << "You can't place rectangle with sides " << a << " and "  << b << " inside rectangle with sides: " << c << " and " << d << ".\n";
    }
    
    return 0;
}


bool is_more_than_zero(string val){
    bool exp = stof(val) > 0;
    if (!exp)
    {
        std:: cout << "Value must be > 0" << endl;
    }
    return exp;
}
