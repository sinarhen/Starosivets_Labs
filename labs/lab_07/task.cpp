#include <iostream>
#include <iomanip>

#include "general/general.h"
#include "../utils/utils.h"
#include "../utils/matrix/matrix.h"

using namespace std;

// Namespace for the first task: Calculating routes for a chess king
namespace lab7_1 {
    // Function to initialize a matrix with zeros
    void initializeMatrix(int **matrix, int rows, int columns) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    // Function to calculate routes for a chess king
    void calculateRoutes(int **matrix, int rows, int columns) {
        matrix[0][0] = 1;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (j + 1 < columns) {
                    matrix[i][j + 1] += matrix[i][j];
                }
                if (i + 1 < rows) {
                    matrix[i + 1][j] += matrix[i][j];
                }
                if (i + 1 < rows && j + 1 < columns) {
                    matrix[i + 1][j + 1] += matrix[i][j];
                }
            }
        }
    }

    // Function to run the first task
    void run() {
        int n, m;

        cout << "Enter the number of rows (n): ";
        n = getValue<int>();

        cout << "Enter the number of columns (m): ";
        m = getValue<int>();

        int **chessboard = new int *[n];
        for (int i = 0; i < n; ++i) {
            chessboard[i] = new int[m];
        }

        initializeMatrix(chessboard, n, m);
        calculateRoutes(chessboard, n, m);
        printMatrix(chessboard, n, m);

        cout << "Total possible routes: " << chessboard[n - 1][m - 1] << endl;

        // Clean up memory
        for (int i = 0; i < n; ++i) {
            delete[] chessboard[i];
        }
        delete[] chessboard;
    }
}

// Namespace for the second task: Operations with a matrix
namespace lab7_2 {

    // Function to run the second task
    void run() {
        int n, m;

        cout << "Enter the number of rows (n): ";
        n = getValue<int>([&](int row) {
            if (row > 0) {
                return true;
            }
            cout << "Should be more or equal to 1\n";
            return false;
        });

        cout << "Enter the number of columns (m): ";
        m = getValue<int>([&](int col) {
            if (col > 0) {
                return true;
            }
            cout << "Should be more or equal to 1\n";
            return false;
        });

        cout << "Select matrix fill method. ";
        char fillMethod = getFillMethod();

        double **matrix = constructMatrix<double>(n, m, fillMethod);
        printMatrix(matrix, n, m);

        operationsOnMatrix(matrix, n, m);
        // Clean up memory
        for (int i = 0; i < n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

// Main function
int main() {
    int prev;
    while (true) {
        cout << "Choose a task:" << endl;
        cout << "[1]" << (prev == '1' ? "(previous)" : "") << " Calculating routes for chess king" << endl;
        cout << "[2]" << (prev == '2' ? "(previous)" : "") << " Operations with matrix" << endl;

        int task = getValue<int>([](int val) {
            return val == 1 || val == 2;
        });
        switch (task) {
            case 1:
                prev = '1';
                lab7_1::run();
                break;
            case 2:
                prev = '2';
                lab7_2::run();
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
