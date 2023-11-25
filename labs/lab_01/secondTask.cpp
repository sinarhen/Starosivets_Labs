#include <iostream>
#include <cmath>
#include "../utils/utils.h"
#include "../filters/filters.h"

using namespace std;

double calculationTask(double x, double y) {
    return pow(x, 3) + 3*x*x*y + pow(y, 3);
}

int main(void) {
    cout << "Lab1.Starosivets Bohdan\n---FUNCTION DOES THIS CALCULATIONS: x^3 + 3(x^2)y + y^3 --- " << endl;

    double x, y;

    // Input X value and store it in 'x'
    cout << "Enter the x: ";
    x = getValue<double>();

    // Input Y value and store it in 'y' 
    cout << "Enter the y: ";
    y = getValue<double>();

    // Define variable result for output
    double result = calculationTask(x, y);
    
    // Outputting the result
    cout << result << endl;

    // Return result
    return 0;
}