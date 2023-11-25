#include <iostream>
#include "../../utils/utils.h"
#include "utils.h"


using namespace std;
// function to ask from user size of array
int getSize();

// function to create array filled with random numbers

template <typename T>
T* createArrayWithRandomNumbers(int size, T from, T to) {
    srand(static_cast<unsigned>(time(nullptr)));

    T* array = new T[size];

    for (int i = 0; i < size; i++) {
        T randomValue = static_cast<T>(getRandomNumber(static_cast<int>(from), static_cast<int>(to)));
        array[i] = randomValue;
    }

    return array;
}

// function to get from console 'r' or 'm'
char getFillMethod();

// function to output each array element through iteration

template <typename T>
void outputArray(T* arr, int size) {
    cout << "{ ";
    for (int i = 0; i < size - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1] << " }\n";
}

// function to create array with manually inputted numeric values

template <typename T>
T* createArrayWithManualEnteredNumbers(int size) {
    T* array = new T[size];

    for (int i = 0; i < size; i++) {
        std::cout << "Enter " << i << "-th element: ";
        array[i] = getValue<T>();
    }

    return array;
}

// function to make array with defined size, method of filling values (random, manually)
template <typename T>
T* constructArray(int size, char fillMethod) {
    T* arrayPointer = nullptr;

    if (fillMethod == 'r') {
        std::cout << "from: ";
        int from = getValue<T>();

        std::cout << "to: ";
        int to = getValue<T>();

        arrayPointer = createArrayWithRandomNumbers<T>(size, from, to);
    }
    if (fillMethod == 'm') {
        arrayPointer = createArrayWithManualEnteredNumbers<T>(size);
    }

    return arrayPointer;
}

