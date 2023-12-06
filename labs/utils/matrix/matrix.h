#include <iostream>

#include "../utils.h"
#include <iomanip>

using namespace std;


template <typename T>
void deallocateMatrix(T**& matrix, int rows) {
    if (matrix == nullptr) {
        return;  // Matrix is already deallocated or uninitialized
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = nullptr;  // Set the pointer to null to avoid using it after deallocation
}

char getFillMethod(){
    cout << "Available fill methods:\n";
    cout << " 'r' - fill with random numbers" << endl;
    cout << " 'm' - fill manually" << endl;
    cout << " 'a' - only allocate" << endl;
    char method;
    method = getValue<char>([](char val) {
        return (val == 'r' || val == 'm' || val == 'a');
    });
    return method;
}

template <typename T>
void printMatrix(T** matrix, int rows, int columns) {

    for (int i = 0; i < rows; i++) {
        cout << "| ";
        for (int j = 0; j < columns; j++) {
            std::cout << setw(4) << matrix[i][j] << " ";;
        }
        cout << "|\n";
    }
}

// Function to select a row
int selectRow(int rows) {
    return getValue<int>([&](int val) {
        if (val <= rows + 1 && val >= 1) // Max row
            return true;
        cout << "Invalid row selected\n";
        cout << "Select row between 1 and " << rows + 1 << ": ";
        return false;
    });
}

// Function to select a column
int selectCol(int cols) {
    return getValue<int>([&](int val) {
        if (val < cols + 1 && val >= 1) // Max row
            return true;
        cout << "Invalid column selected\n";
        cout << "Select column between 1 and " << cols + 1 << ": ";
        return false;
    });
}

// Function to swap rows in a matrix
template <typename T>
void swapRows(T **matrix, int columns, int row1, int row2) {
    for (int j = 0; j < columns; j++) {
        swap(matrix[row1][j], matrix[row2][j]);
    }
}
// Function to swap columns in a matrix
template <typename T>
void swapColumns(T **matrix, int rows, int col1, int col2) {
    for (int i = 0; i < rows; i++) {
        swap(matrix[i][col1], matrix[i][col2]);
    }
}

// Function to multiply a row by a constant
template <typename T>
void multiplyRow(T **matrix, int columns, int row, double multiplier) {
    for (int j = 0; j < columns; j++) {
        matrix[row][j] *= multiplier;
    }
}

// Function to multiply a column by a constant
template <typename T>
void multiplyColumn(T **matrix, int rows, int col, double multiplier) {
    for (int i = 0; i < rows; i++) {
        matrix[i][col] *= multiplier;
    }
}

// Function to add a row to another row
template <typename T>
void addRowToRow(T **matrix, int columns, int srcRow, int destRow) {
    for (int j = 0; j < columns; j++) {
        matrix[destRow][j] += matrix[srcRow][j];
    }
}

// Function to add a column to another column
template <typename T>
void addColumnToColumn(T **matrix, int rows, int srcCol, int destCol) {
    for (int i = 0; i < rows; i++) {
        matrix[i][destCol] += matrix[i][srcCol];
    }
}

// Function to create a matrix with manually entered numbers
template <typename T>
T **createMatrixWithManualEnteredNumbers(int rows, int cols) {
    T **matrix = new T *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new T[cols];
    }

    T temp;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "[" << i << "][" << j << "] = ";
            temp = getValue<T>();
            matrix[i][j] = temp;
        }
    }

    return matrix;
}

// Function to create a matrix with random numbers
template <typename T>
T **createMatrixWithRandomNumbers(int rows, int cols, T from, T to) {

    T **matrix = new T *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new T[cols];
    }

    T randomValue;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; ++j) {
            randomValue = getRandomNumber(from, to);
            matrix[i][j] = randomValue;
        }
    }

    return matrix;
}

template <typename T>
T** allocateMatrix(int rows, int cols) {
    T** matrix = new T*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new T[cols];
    }
    return matrix;
}

// Function to construct a matrix based on the fill method
template <typename T>
T **constructMatrix(int rows, int cols, char fillMethod) {
    T **matrixPointer = nullptr;

    if (fillMethod == 'r') {
        std::cout << "from: ";
        T from = getValue<T>();

        std::cout << "to: ";
        T to = getValue<T>();

        matrixPointer = createMatrixWithRandomNumbers<T>(rows, cols, from, to);
    }
    else if (fillMethod == 'm') {
        matrixPointer = createMatrixWithManualEnteredNumbers<T>(rows, cols);
    } else if (fillMethod == 'a'){
        matrixPointer = allocateMatrix<T>(rows, cols);
    }

    return matrixPointer;
}

// Function to add two matrices
template <typename T>
T** addMatrices(T** matrixA, T** matrixB, int rows, int cols) {
    if (rows != cols) throw "Rows and cols should be equal";
    T** result = allocateMatrix<T>(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    return result;
}

template <typename T>
T** multiplyMatrices(T** matrixA, T** matrixB, int rowsA, int colsA, int rowsB, int colsB) {
    if (colsA != rowsB) throw "To multiply matrices, columns in matrixA should be equal to rowsB";

    T** result = constructMatrix<T>(rowsA, colsB, 'a');

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return result;
}

template <typename T>
void printRow(T** matrix, int rows, int cols, int rowIndex) {
    if (rowIndex < 0 || rowIndex >= rows) {
        cout << "Invalid row index.\n";
        return;
    }

    cout << "Row " << rowIndex << ": ";
    for (int j = 0; j < cols; ++j) {
        cout << matrix[rowIndex][j] << " ";
    }
    cout << endl;
}

template <typename T>
void printColumn(T** matrix, int rows, int cols, int columnIndex) {
    if (columnIndex < 0 || columnIndex >= cols) {
        cout << "Invalid column index.\n";
        return;
    }

    cout << "Column " << columnIndex << ": ";
    for (int i = 0; i < rows; ++i) {
        cout << matrix[i][columnIndex] << endl;
    }
}
template <typename T>
void removeRow(T**& matrix, int& rows, int cols, int rowIndex) {
    if (rowIndex < 0 || rowIndex >= rows) {
        cout << "Invalid row index.\n";
        return;
    }

    // Create a new matrix with reduced rows
    T** newMatrix = new T*[rows - 1];
    for (int i = 0, newRow = 0; i < rows; ++i) {
        if (i != rowIndex) {
            newMatrix[newRow] = new T[cols];
            for (int j = 0; j < cols; ++j) {
                newMatrix[newRow][j] = matrix[i][j];
            }
            ++newRow;
        }
    }

    // Deallocate memory of the old matrix
    deallocateMatrix(matrix, rows);

    // Update matrix and rows
    matrix = newMatrix;
    --rows;
}

template <typename T>
void removeColumn(T**& matrix, int rows, int& cols, int columnIndex) {
    if (columnIndex < 0 || columnIndex >= cols) {
        cout << "Invalid column index.\n";
        return;
    }

    // Create a new matrix with reduced columns
    T** newMatrix = new T*[rows];
    for (int i = 0; i < rows; ++i) {
        newMatrix[i] = new T[cols - 1];
        for (int j = 0, newCol = 0; j < cols; ++j) {
            if (j != columnIndex) {
                newMatrix[i][newCol] = matrix[i][j];
                ++newCol;
            }
        }
    }

    // Deallocate memory of the old matrix
    deallocateMatrix(matrix, rows);

    // Update matrix and cols
    matrix = newMatrix;
    --cols;
}

template <typename T>
void operationsOnMatrix(T** matrix, int n, int m)
{
    char choice;
    do {
        cout << "Choose an operation:" << endl;
        cout << "[1] Swap rows" << endl;
        cout << "[2] Swap columns" << endl;
        cout << "[3] Multiply row by constant" << endl;
        cout << "[4] Multiply column by constant" << endl;
        cout << "[5] Add row to another row" << endl;
        cout << "[6] Add column to another column" << endl;
        cout << "[7] Remove row" << endl;
        cout << "[8] Remove column" << endl;
        cout << "[9] Print row" << endl;
        cout << "[10] Print column" << "\n\n";
        cout << "[0] back" << endl;

        int operation = getValue<int>([](int val) {
            return val >= 0 && val <= 10;
        });

        int row1, row2, col1, col2, row, col;
        double multiplier;

        switch (operation) {
            case 1:
                cout << "Enter the rows to swap: ";
                row1 = selectRow(n);

                cout << "Enter the second row: ";
                row2 = selectRow(n);

                swapRows<T>(matrix, m, row1 - 1, row2 - 1);
                break;

            case 2:
                cout << "Enter the first column: ";
                col1 = selectCol(m);

                cout << "Enter the second column: ";
                col2 = selectCol(m);

                swapColumns<T>(matrix, n, col1 - 1, col2 - 1);
                break;

            case 3:
                cout << "Enter the row to multiply: ";
                row = selectRow(n);

                cout << "Enter the multiplier:";
                multiplier = getValue<double>();

                multiplyRow<T>(matrix, m, row - 1, multiplier);
                break;

            case 4:
                cout << "Enter the column to multiply: ";
                col = selectCol(m);

                cout << "Enter the multiplier";
                multiplier = getValue<double>();
                multiplyColumn<T>(matrix, n, col - 1, multiplier);
                break;

            case 5:
                cout << "Enter the source row: ";
                row1 = selectRow(n);

                cout<<"Enter the destination row: ";
                row2 = selectRow(n);

                addRowToRow<T>(matrix, m, row1 - 1, row2 - 1);
                break;

            case 6:
                cout << "Enter the source column: ";
                col1 = selectCol(m);

                cout << "Enter the destination column: ";
                col2 = selectCol(m);

                addColumnToColumn<T>(matrix, n, col1 - 1, col2 - 1);
                break;
            case 7:
                if (n == 1)
                {
                    cout << "You only have 1 row" << endl;
                    break;
                }
                cout << "Which row you want to remove?" << endl;
                row1 = selectRow(n);

                removeRow<T>(matrix, n, m, row1 - 1);
                break;
            case 8:
                if (m < 2)
                {
                    cout << "You only have 1 col";
                    break;
                }
                cout << "Which col you want to remove?" << endl;
                col1 = selectRow(m);

                removeColumn<T>(matrix, n, m, col1 - 1);
                break;
            case 9:
                row1 = selectRow(n);
                printRow<T>(matrix, n, m, row1 - 1);
                break;
            case 10:
                col1 = selectCol(m);
                printColumn<T>(matrix, n, m,  col1 - 1);
                break;
            case 0:
                return;
            default:
                cout << "Invalid operation." << endl;
                break;
        }

        printMatrix(matrix, n, m);

        cout << "Do you want to perform another operation? (y/n): ";
        choice = getYesOrNo();

    } while (choice == 'y');

}
