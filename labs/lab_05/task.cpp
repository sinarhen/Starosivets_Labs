#include <iostream>
#include "../utils.h"
#include <string>
#include "../filters.h"
#include <cmath>

using namespace std;

// Function to get an integer value that is more than one
int getIntegerMoreThanOne(){
    return stoi(getValue(isNumeric, isMoreThanOne));
}

namespace lab5_1 {
    int recursiveDepth = 0; // Variable to keep track of recursion depth

    // Iterative function to calculate the product of two integers
    int calculateIterative(int x, int y) {
        int result = 0;
        while (y > 0) {
            result += x; // Add x to the result
            y--;
        }
        return result;
    }

    // Recursive function to calculate the product of two integers
    int calculateRecursive(int x, int y) {
        if (!x || !y) return 0; // Base case: if either x or y is zero, return 0

        recursiveDepth++; // Increment the recursion depth
        return x + calculateRecursive(x, y - 1); // Recursively add x to the result
    }

    // Function to run the lab5_1 code
    void run() {
        int a, b;

        cout << "Enter the value of a: " << endl;
        a = getIntegerMoreThanOne();

        cout << "Enter the value of b: " << endl;
        b = getIntegerMoreThanOne();

        cout << "A is " << a << "\tB is " << b << endl;

        // Calculate and display the result using the recursive approach
        int result = calculateRecursive(a, b);
        
        // Calculate and display the result using the iterative approach
        if (result != calculateIterative(a, b)) {
            cout << "Result mismatch between recursive and iterative methods." << endl;
        } else {
            cout << "Result is " << result << endl;
            cout << "Recursion depth: " << recursiveDepth << " | Iterations: " << b << endl;
        }
    }
}

namespace lab5_2 {
    // Function to calculate the sum of digits in a number
    int sumOfDigits(int num, int sum = 0) {
        if (num <= 0)
        {
            return sum;
        }

        return sum + sumOfDigits(num / 10, num % 10);
    }

    // Function to count the number of k-digit numbers with a given digit sum
    int countNumbersWithSum(int k, int s, int counter = 0, int number = false) {
        if (number == pow(10, k) - 1){
            return counter;
        }
        if (!number){
            number = pow(10, k - 1);
        }
        if (sumOfDigits(number) == s){
            counter += 1;
        }
        return countNumbersWithSum(k, s, counter, number + 1);
    }

    void run(){
        cout << "Task 2" << endl;

        int k, s;
        cout << "Enter the k: ";
        k = getIntegerMoreThanOne();

        cout << "Enter the s: ";
        s = getIntegerMoreThanOne();

        int result = countNumbersWithSum(k, s);
        cout << "Result is " << result;
    }
}

int main() {
    cout << "Laboratory work 5. Made by Starosivets Bohdan (Variant 8)" << "\n\n\n";

    cout << "Choose task: (1 or 2)";
    string task = getValue([](string val){
        return (val == "1" || val == "2");
    });

    if (task == "1"){
        lab5_1::run();
    }
    if (task == "2"){
        lab5_2::run();
    }

    return 0; // Exit the program with a status code of 0
}
