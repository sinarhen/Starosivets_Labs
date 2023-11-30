#include <iostream>
#include "../utils/utils.h"

#include "../utils/matrix/matrix.h"

using namespace std;

int getMoreThanOne() {
    return getValue<int>([&](int val) {
        if (val < 1) {
            cout << "Must be more than one";
            return false;
        } else {
            return true;
        }
    });
}

pair<int, int> getRowsAndCols() {

    int rows, cols;
    cout << "Enter number of rows(>=1)" << endl;
    rows = getMoreThanOne();

    cout << "Enter number of cols(>=1)" << endl;
    cols = getMoreThanOne();
    return make_pair(rows, cols);
}

int main() {
    int rowsA, colsA, rowsB, colsB;


    cout << "Constructing first matrix..." << endl;
    pair<int, int> size = getRowsAndCols();
    rowsA = size.first;
    colsA = size.second;
    char fillMethodA = getFillMethod();
    int **matrixA = constructMatrix<int>(rowsA, colsA, fillMethodA);

    cout << "Constructing second matrix" << endl;
    size = getRowsAndCols();
    rowsB = size.first;
    colsB = size.second;
    char fillMethodB = getFillMethod();

    // Виділення та введення елементів для матриць A та B
    int **matrixB = constructMatrix<int>(rowsA, colsB, fillMethodB);

    // Виведення матриць A та B
    cout << "\nMatrix A:\n";
    printMatrix(matrixA, rowsA, rowsB);

    cout << "\nMatrix B:\n";
    printMatrix(matrixB, rowsA, colsB);

    // Додавання матриць A та B
    char choice;

    int **result = nullptr;
    int resultRows, resultCols;

    bool additionAvailable, multiplicationAvailable, resultMatrixAvailable;
    do {
        additionAvailable = rowsA == rowsB && colsA == colsB;
        multiplicationAvailable = colsA == rowsB;
        resultMatrixAvailable = result != nullptr;

        cout << "Choose an operation:" << endl;
        cout << "[1]" << ( !additionAvailable ? "(Unavailable for your matrixes) " : "")
             << "Add Matrixes" << endl;
        cout << "[2]" << ( !multiplicationAvailable ? "(Unavailable for your matrixes) " : "") << " Multiply matrixes" << endl;
        cout << "[3] Matrix A operations" << endl;
        cout << "[4] Matrix B operations" << endl;
        cout << "[5]" << (!resultMatrixAvailable ? "(Unavailable, try to add or multiply matrixes)" : "")
             << " Result matrix operations" << endl;
        int operation = getValue<int>([](int val) {
            return val >= 1 && val <= 5;
        });

        switch (operation) {
            case 1:
                if (!additionAvailable) {
                    cout << "Unavailable" << endl;
                    break;
                }
                result = addMatrices<int>(matrixA, matrixB, rowsA, colsA);
                resultRows = rowsA;
                resultCols = colsA;
                printMatrix<int>(result, resultRows, resultCols);
                break;
            case 2:
                if (!multiplicationAvailable) {
                    cout << "Unavailable" << endl;
                    break;
                }
                result = multiplyMatrices<int>(matrixA, matrixB, rowsA, colsA, rowsB, colsB);
                resultRows = rowsA;
                resultCols = colsB;
                printMatrix<int>(result, resultRows, resultCols);
                break;
            case 3:
                operationsOnMatrix<int>(matrixA, rowsA, colsA);
                break;
            case 4:
                operationsOnMatrix<int>(matrixB, rowsB, colsB);
                break;
            case 5:
                if (!resultMatrixAvailable) {
                    cout << "Unavailable" << endl;
                    break;
                }
                operationsOnMatrix<int>(result, resultRows, resultCols);
                break;
            default:
                cout << "Invalid option." << endl;
        }
        cout << "Do you want to perform another operation on matrixes? (y/n): ";
        choice = getYesOrNo();

    } while (choice == 'y');

    deallocateMatrix<int>(matrixA, rowsA);
    deallocateMatrix(matrixB, rowsB);
    deallocateMatrix(result, resultRows);
    return 0;
}
