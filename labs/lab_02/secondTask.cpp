<<<<<<< HEAD
#include <iostream>
#include "../utils/utils.h"
#include <string.h>

using namespace std;

bool is_more_than_zero(string val);

int main(void){
    double a, b, c, d;
    
    std:: cout << "---Lab 02. Second task. Starosivets Bohdan---"<< endl;


    cout << "Enter A: ";
    getValue(a);

    cout << "Enter B: ";
    getValue(b);

    cout << "Enter C: ";
    getValue(c);

    cout << "Enter D: ";
    getValue(d);


    std:: cout << "\n\n";

    // Перевірка умови розташування прямокутника a, b всередині прямокутника c, d
    if ((a <= c && b <= d) || (a <= d && b <= c)) {
        std::cout << "Rectangle with sides: " << a << " and " << b << " can be placed inside rectangle with sides: " << c << " and " << d << ".\n";
    } else {
        std::cout << "You can't place rectangle with sides " << a << " and "  << b << " inside rectangle with sides: " << c << " and " << d << ".\n";
    }
    
    return 0;
}


bool is_more_than_zero(double val){
    bool exp = val > 0;
    if (!exp)
    {
        std:: cout << "Value must be > 0" << endl;
    }
    return exp;
}
=======
#include <iostream>
#include "../utils/utils.h"
#include <string.h>

using namespace std;

bool is_more_than_zero(string val);

int main(void){
    double a, b, c, d;
    
    std:: cout << "---Lab 02. Second task. Starosivets Bohdan---"<< endl;


    cout << "Enter A: ";
    getValue(a);

    cout << "Enter B: ";
    getValue(b);

    cout << "Enter C: ";
    getValue(c);

    cout << "Enter D: ";
    getValue(d);


    std:: cout << "\n\n";

    // Перевірка умови розташування прямокутника a, b всередині прямокутника c, d
    if ((a <= c && b <= d) || (a <= d && b <= c)) {
        std::cout << "Rectangle with sides: " << a << " and " << b << " can be placed inside rectangle with sides: " << c << " and " << d << ".\n";
    } else {
        std::cout << "You can't place rectangle with sides " << a << " and "  << b << " inside rectangle with sides: " << c << " and " << d << ".\n";
    }
    
    return 0;
}


bool is_more_than_zero(double val){
    bool exp = val > 0;
    if (!exp)
    {
        std:: cout << "Value must be > 0" << endl;
    }
    return exp;
}
>>>>>>> origin/main
