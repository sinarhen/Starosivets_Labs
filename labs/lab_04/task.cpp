#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

using namespace std;

// Common variables and functions for both tasks
namespace common
{
    double accuracy = 1.0;

    // Function for entering the calculation accuracy
    void enterAccuracy()
    {
        while (accuracy >= 1.0)
        {
            cout << "Enter accuracy in the format of 10^-5: ";
            cin >> accuracy;
        }
    }
}

namespace lab4_1
{
    float y, sv, ev, step, standart, error;

    // Function to calculate arcsin(x)
    float arcsinRecursive(float x, float sum = 0, float member = 0, int n = 1)
    {
        member = (2 * n - 1) / (2 * n) * (x * x / (2 * n + 1));
        sum += member;

        if (fabs(member) < FLT_MIN || fabs(member) > FLT_MAX || fabs(member) >= common::accuracy)
        {
            return sum;
        }

        return arcsinRecursive(x, sum, member, n + 1);
    }

    // Function to perform task 1
    void run()
    {
        cout << "Enter the initial value, end value, and step: ";
        cin >> sv >> ev >> step;

        cout << "Enter the accuracy: ";
        common::enterAccuracy();

        cout << "\n========================================================" << endl;
        cout << " x           y            standart           error" << endl;
        cout << "\n========================================================" << endl;

        for (float x = sv; x <= ev; x += step)
        {
            bool flag = true;
            if (x >= -2 && x < 0)
            {
                y = arcsinRecursive(x / 2) / arcsinRecursive(2 * x);
                standart = asin(x / 2) / asin(2 * x);
                error = fabs(standart - y);
            }
            else if (x >= 0 && x <= 2)
            {
                y = arcsinRecursive(x + 5) / arcsinRecursive(x * x);
                standart = asin(x + 5) / asin(x * x);
                error = fabs(standart - y);
            }
            else
            {
                flag = false;
            }

            if (!flag || isnan(standart))
            {
                cout << setw(5) << x << setw(15) << "       function not defined" << endl;
            }
            else
            {
                cout << setw(5) << x << setw(15) << y << setw(15) << standart << setw(18) << error << endl;
            }
        }
    }
}

namespace lab4_2
{
    double result;
    const double pi = 3.14159;

    // Function to calculate the value of Pi
    double calculatePiRecursive(int i, double member = 0)
    {
        member = (i > 0) ? (2 * i - 1) + (i * i) / member : 4 / member;

        if (fabs(member - pi) < common::accuracy)
        {
            return member;
        }

        return calculatePiRecursive(i - 1, member);
    }
    // Function to perform task 2
    void run()
    {
        common::enterAccuracy();
        int i;
        cout << "Enter i value, for example 10 or more";
        cin >> i;
        result = calculatePiRecursive(i);
        cout << "The value of the calculated Pi is: " << result << endl;
    }
}

int main()
{
    setlocale(LC_CTYPE, "en_US.UTF-8");
    cout << "Lab 4, Variant 4, Bohdan Starosivets, IPZ-12(1)" << endl;
    cout << "Choose a task (1 or 2): ";
    int choice;
    do {
        cin >> choice;

        if (choice == 1)
        {
            lab4_1::run();
        }
        else if (choice == 2)
        {
            lab4_2::run();
        }
        else
        {
            choice = false;
            cout << "Invalid task choice. Choose 1 or 2." << endl;
        }

    } while (!choice);

    return 0;
}