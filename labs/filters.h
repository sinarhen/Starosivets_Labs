#include <iostream>
# before lab_06
// bool isNumeric(string value){
//     for (char c : value) {
//         if (isalpha(c) && c != '-' && c != '.') {
//             cout << "All characters must be digits" << endl;
//             return false;
//         }
//     }
//     return true;
// }
// bool isMoreThanOne(string value)
// {
//     if (stoi(value) < 1 ){
//         cout << "Value must be more than one" << endl;
//         return false;
//     };
//     return true;
// }
# after lab_06
bool isMoreThanOne(int val)
{
    if (val < 1 ){
        std::cout << "Value must be more than one" << endl;
        return false;
    };
    return true;
}
