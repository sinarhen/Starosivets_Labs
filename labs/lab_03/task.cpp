#include <iostream>
#include <cfloat>
#include <cmath>
#include <iomanip>

using namespace std;

namespace lab3 {
    // Declare variables and flags
    int x = 1, k, accuracy, continueCalc = 1;
    double innerSum, totalSum, temp;

    // Function to calculate factorial
    double calculateFactorial(int n) {
        if (n <= 1) {
            return 1.0;
        }
        return n * calculateFactorial(n - 1);
    }

    // Function to calculate power
    double calculatePower(double base, int exponent) {
        if (exponent <= 0) {
            return 1;
        }
        return base * calculatePower(base, exponent - 1);
    }

    // Function to display a row of the table
    void displayTableRow() {
        cout << setw(5) << x << setw(5) << k << setw(15) << innerSum << setw(15) << totalSum << endl;
    }

    // Function to display the table header
    void displayTableHeader() {
        cout << "==============================================" << endl;
        cout << "    x    k     10  innerSum       totalSum       " << endl;
        cout << "==============================================" << endl;
    }

    // Function to calculate table data
    void calculateTableData() {
        while (x <= 5) {
            while (true) {
                if (k == accuracy) {
                    cout << "Reached limit for inner cycle" << endl;
                    break;
                }
                temp = ((calculatePower(-1, k + 1) * calculatePower(x, 2 * k + 1)) /
                        (calculateFactorial(k) * (2 * k + 1)));

                if (fabs(temp) < FLT_MIN) {
                    break;
                }
                innerSum += temp;
                totalSum += innerSum;
                displayTableRow();
                k++;
            }
            innerSum = 0;
            k = 0;
            x++;
        }
    }

    // Function to ask for accuracy limit
    int askForAccuracy() {
        while (!accuracy) {
            cout << "Enter limit of operations for inner while:";
            cin >> accuracy;
            if (accuracy < 1) {
                accuracy = 0;
                cout << "Please provide a valid accuracy" << endl;
            }
        }
        return accuracy;
    }

    // Function to display the result
    void displayResult() {
        cout << "==============================================" << endl;
        cout << "total sum is " << totalSum << endl;
    }

    // Function to ask if the user wants to continue
    void askForRepeat() {
        char answer;
        while (true) {
            cout << "Continue? (y/n)";
            cin >> answer;
            if (tolower(answer) == 'y') {
                continueCalc = true;
                break;
            } else if (tolower(answer) == 'n') {
                continueCalc = false;
                break;
            }
            cout << "Wrong answer. Enter 'n' or 'y'" << endl;
        }
    }

    // Function to reset variables
    void reset() {
        x = 1;
        k = 0;
        accuracy = false;
        innerSum = 0;
        totalSum = 0;
    }

    // Main execution function
    void run() {
        while (continueCalc) {
            reset();
            askForAccuracy();
            displayTableHeader();
            calculateTableData();
            displayResult();
            askForRepeat();
        }
    }
}

int main() {
    lab3::run();
    return 0;
}
