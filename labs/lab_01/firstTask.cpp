#include <iostream>
#include <cmath>
#include "../utils/utils.h" // Assuming localutils.h contains necessary functions.

using namespace std;

// Function prototype for the calculation task with three parameters.
double calculationTask(double a, double b, double c);

int main() 
{
    cout << "Lab1.Starosivets Bohdan\n--- FUNCTION DOES THIS CALCULATIONS: arctg(4A/(B*B*C) - 1)^0.5 --- " << endl;
    
    // Input A value and store it in 'a'.
    double a, b, c;

    cout << "Enter the A" << endl;
    getValue(a);

    cout << "Enter the B" << endl;
    getValue(b);

    cout << "Enter the C" << endl;
    getValue(c);

    // Call the calculationTask function with three parameters and print the result.
    cout << "Answer is " << calculationTask(a, b, c);

    // The program ends here.
    return 0;
}


// Function prototype for the calculation task with four parameters.
double calculationTask(double a, double b, double c) {

    double arithmetic = sqrt(atan(4*a/b*b*c - 1));

    return arithmetic;
}