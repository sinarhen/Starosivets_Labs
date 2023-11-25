#include <iostream>
#include "utils.h"

char getYesOrNo() {
    char response = getValue<char>([&](char c){
        return (tolower(c) == 'y' || tolower(c) == 'n');
    });
    return response;
}


double getRandomNumber(int from, int to) {
    if (from > to) {
        std::cout << "From argument can't be less than to\n";
        return 0.0;
    }

    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned>(time(nullptr)));
        seeded = true;
    }

    double randomValue = from + static_cast<double>(rand()) / RAND_MAX * (to - from);
    return randomValue;
}
