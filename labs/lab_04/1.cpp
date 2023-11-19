#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

using namespace std;

float accuracy;  // Точність
float x,
        y,
        sv,  //Початкове значення
ev,  // Кінцеве значення
step,  // Крок
standart;
float error;

float arcsin(float x)
{
    float sum = x, member = x;
    int n = 1;
    float upperPart;
    float lowerPart;

    do
    {
        upperPart = (2 * n - 1);
        lowerPart = (2 * n);
        member *=  upperPart / lowerPart * (x * x / (2 * n + 1));
        sum += member;
        n++;
        if (fabs(member) < FLT_MIN || fabs(member) > FLT_MAX)
        {
            break;
        }
    } while (fabs(member) < accuracy);
    return sum;
}
void task1() {
    bool flag;

    cout << "Provide start value, end value and step: " << endl;
    cin >> sv >> ev >> step;
    cout << "Provide accuracy: ";
    cin >> accuracy;

    cout << "\n========================================================" << endl;
    cout << " x           y            standart           error" << endl;
    cout << "\n========================================================" << endl;

    for (x = sv; x <= ev; x += step) {
        flag = true;
        if (x >= -2 && x < 0) {
            y = arcsin(x / 2) / arcsin(2 * x);
            standart = asin(x / 2) / asin(2 * x);
            error = fabs(standart - y);
        }
        else if (x >= 0 && x <= 2) {
            y = arcsin(x + 5) / arcsin(x * x);
            standart = asin(x + 5) / asin(x * x);
            error = fabs(standart - y);
        }
        else {
            flag = false;
        }
        if (!flag || standart != standart)
        {
            cout << setw(5) << x << setw(15) << "       function not defined" << endl;
        }
        else
        {
            cout << setw(5) << x << setw(15) << y << setw(15) << standart << setw(18) << error << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "\t\t\tСтаросівець Богдан Володимирович" << endl;
    cout << "\t\t\tГрупа IПЗ - 12.1" << endl;
    cout << "\t\t\tЛабораторна робота №4.1 вар.4" << endl << endl;

    task1();
}