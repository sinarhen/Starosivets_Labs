
#include <iostream>
#include "../utils/sparse_matrix/sparse_matrix.h"

using namespace std;

namespace task1
{
    int run() {
        CRSMatrix<int> matrix1, matrix2;
        generateTwoSparseMatrices(matrix1, matrix2);

        int prev;
        while (true) {
            cout << "Choose an operation:" << endl;
            cout << "[1]" << (prev == 1 ? "(previous)" : "") << " Matrix Operations" << endl;
            cout << "[0] Exit" << endl;

            int operation = getValue<int>([](int val) {
                return val == 1 || val == 0;
            });

            switch (operation) {
                case 1:
                    prev = 1;
                    CRSMatrixOperationsMenu(matrix1, matrix2);
                    break;
                case 0:
                    return 0;
                default:
                    throw "Something went wrong.";
            }

            cout << "Do you want to choose another operation? (y/n): ";
            auto choice = getYesOrNo();

            if (choice != 'y') {
                break;  // Exit the loop if the user doesn't want to choose another operation
            }
        }

        return 0;
    }
}


int main() {
    using namespace std;

    int prev;
    while (true) {
        cout << "Choose a task:" << endl;
        cout << "[1]" << (prev == '1' ? "(previous)" : "") << "Sparse Matrixes" << endl;

        int task = getValue<int>([](int val) {
            return val == 1;
        });
        switch (task) {
            case 1:
                prev = '1';
                task1::run();
                break;
            default:
                throw "Something went wrong.";
        }

        cout << "Do you want to do another task? (y/n): ";
        auto choice = getYesOrNo();

        if (choice != 'y') {
            break;  // Exit the loop if the user doesn't want to do another task
        }
    }

    return 0;
}
