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
    float arcsin(float x)
    {
        float sum = x, member = x;
        int n = 1;

        do
        {
            member *= (2 * n - 1) / (2 * n) * (x * x / (2 * n + 1));
            sum += member;
            n++;

            if (fabs(member) < FLT_MIN || fabs(member) > FLT_MAX)
            {
                break;
            }
        } while (fabs(member) >= common::accuracy);

        return sum;
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
                y = arcsin(x / 2) / arcsin(2 * x);
                standart = asin(x / 2) / asin(2 * x);
                error = fabs(standart - y);
            }
            else if (x >= 0 && x <= 2)
            {
                y = arcsin(x + 5) / arcsin(x * x);
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
    double calculatePi()
    {
        int i;
        cout << "Enter i (for example, 10 or more): ";
        cin >> i;
        double member = 2 * i + 1;
        do
        {
            if (i > 0)
                member = (2 * i - 1) + (i * i) / member;
            else
                member = 4 / member;
            i--;

        } while (fabs(member - pi) >= common::accuracy);

        return member;
    }

    // Function to perform task 2
    void run()
    {
        common::enterAccuracy();
        result = calculatePi();
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
