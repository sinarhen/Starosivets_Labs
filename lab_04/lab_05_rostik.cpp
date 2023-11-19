#include <iostream>

using namespace std;

namespace task1
{
    int Recurse(int n)
    {
        if (n == 1 || n == 2)
            return 0;
        else if (n == 3)
            return 1;
        else if (n % 2 == 0)
            return (2 * Recurse(n / 2));
        else
            return (Recurse(n / 2) + Recurse((n / 2) + 1));
    }

    int task1()
    {
        int n;
        cout << "Enter the number of soldiers: ";
        cin >> n;

        cout << "Recursive variant: " << Recurse(n) << endl;

        return 0;
    }
}
namespace task2
{
    void RecurseDigit(int n)
    {
        if (n >= 10)
            RecurseDigit(n / 10);

        cout << n % 10 << ' ';
    }

    int task2()
    {
        int n;
        do
        {
            cout << "Enter a positive integer n: ";
            cin >> n;
            if (n < 0)
                cout << "A positive integer! Try again." << endl;
        } while (n < 0);

        RecurseDigit(n);
        cout << endl;

        return 0;
    }
}
int main()
{
    int ch;
    cout << "Lab 5 Derkach Rostyslav (6 variant), IPZ-12.1" << endl;
    do {
        cout << "\tChose the task:\n[1] Task 1\n[2] Task 2\n[0] Exit" << endl;
        cin >> ch;
        switch (ch)
        {
            case 0:
                cout << "Exiting program";
                break;
            case 1:
                task1::task1();
                break;
            case 2:
                task2::task2();
                break;
            default:
                cout << "Wrong enter!\n";
                break;
        }
    } while (ch != 0);
}
