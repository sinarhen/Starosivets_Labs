#include <iostream>
#include <cmath>

using namespace std;

namespace lab4
{
    const double pi = 3.14159;  // Константа, яка виражає число π
    double accuracy = 1.0, result;     // Точність обчислення

    // Функція для представлення авторства та опису завдання
    void represent()
    {
        cout << "lab 4, var 4, Старосівець Богдан, ІПЗ-12(1)" << endl;
        cout << "Вправа 2" << endl;
        cout << "-----------------------------------------------------------------------------------------" << endl;
        cout << "Обчислити нескінчений ланцюговий дріб, задавши точність обчислення (10^-5) з клавіатури." << endl;
        cout << "Ланцюговий дріб виражає число π." << endl;
        cout << "-----------------------------------------------------------------------------------------" << endl;
    }

    // Функція для введення точності обчислення
    void enterAccuracy()
    {
        while (accuracy >= 1.0)
        {
            cout << "Введіть точність у форматі 10^-5: ";
            cin >> accuracy;
        }
    }

    // Функція для обчислення числа Pi
    double calculatePi()
    {
        int i;
        cout << "Введіть i (наприклад, 10 або більше): ";
        cin >> i;
        double member = 2 * i + 1;
        do
        {
            if (i > 0)
                member = (2 * i - 1) + (i * i) / member;
            else
                member = 4 / member;
            i--;
        } while (fabs(member - pi) >= accuracy);

        result = member; // Зберегти результат в змінну result
        return result;
    }

    // Функція для ініціалізації та виконання всіх кроків
    void initialize()
    {
        represent();
        enterAccuracy();
        result = calculatePi();
        cout << "Значення обчисленого числа Pi: " << result << endl;
    }
}

int main()
{
    lab4::initialize(); // Виклик функції для ініціалізації та виконання програми
}
