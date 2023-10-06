#include <iostream>
#include <cmath>
#include "../localutils.h"

using namespace std;

double calculationTask(double x, double y) {
    return pow(x, 3) + 3*x*x*y + pow(y, 3);
}

int main(void) {
    cout << "Lab1.Starosivets Bohdan\n---FUNCTION DOES THIS CALCULATIONS: x^3 + 3(x^2)y + y^3 --- " << endl;
    
    // Input X value and store it in 'x' 
    double x = getDoubleValue("Enter x: ");
    
    // Input Y value and store it in 'y' 
    double y = getDoubleValue("Enter y: ");

    // Define variable result for output
    double result = calculationTask(x, y);
    
    // Outputting the result
    cout << result << endl;

    // Return result
    return 0;
}