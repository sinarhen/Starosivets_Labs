#include <iostream>
#include <chrono>
#include "../utils.h"
using namespace std;

template <typename T>
void print1DArray(const T* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// Function to get the current time in seconds
double getCurrentTimeInSeconds() {
    auto now = chrono::high_resolution_clock::now().time_since_epoch();
    return chrono::duration_cast<std::chrono::milliseconds>(now).count() / 1000.0;
}

template <typename T>
struct CRSMatrix
{
    T* AN;
    T* JA;
    T* IA;

    int numRows;
    int numCols;
    int nnz;
};

template <typename T>
T getCRSMatrixElement(const CRSMatrix<T>& matrix, int row, int col) {
    // Iterate through the row to find the element in the given column
    for (int k = matrix.IA[row]; k < matrix.IA[row + 1]; ++k) {
        if (matrix.JA[k] == col) {
            return matrix.AN[k];  // Return the non-zero element
        }
    }
    return 0;  // Return 0 for zero elements
}


// Function to generate a CRS matrix
template <typename T>
void generateSparseMatrix(CRSMatrix<T>& matrix)
{
    srand(static_cast<unsigned>(time(0)));

    const double density = 0.3;
    const int maxValue = 100;

    matrix.numRows = rand() % 10 + 1;
    matrix.numRows += (matrix.numRows % 2 == 0) ? 0 : 1;
    matrix.numCols = rand() % 10 + 1;  // Generate the number of columns once
    matrix.nnz = 0;

    matrix.AN = new int[matrix.numCols * matrix.numRows];
    matrix.JA = new int[matrix.numCols * matrix.numRows];
    matrix.IA = new int[matrix.numRows + 1];

    for (int i = 0; i < matrix.numRows; ++i)
    {
        matrix.IA[i] = matrix.nnz;

        for (int j = 0; j < matrix.numCols; ++j)
        {
            if (rand() / static_cast<double>(RAND_MAX) < density)
            {
                int value = rand() % (maxValue + 1);
                matrix.AN[matrix.nnz] = value;
                matrix.JA[matrix.nnz] = j;
                matrix.nnz++;
            }
        }
    }

    matrix.IA[matrix.numRows] = matrix.nnz;
}

template <typename T>
void printCRSMatrix(const CRSMatrix<T>& matrix) {
    for (int i = 0; i < matrix.numRows; ++i) {
        for (int j = matrix.IA[i]; j < matrix.IA[i + 1]; ++j) {
            std::cout << "(" << i << ", " << matrix.JA[j] << "): " << matrix.AN[j] << " ";
        }
        std::cout << std::endl;
    }
}


void printCRSMatrix(CRSMatrix<int>& matrix){
    printCRSMatrix<int>(matrix);
}

void generateTwoSparseMatrices(CRSMatrix<int>& matrix1, CRSMatrix<int>& matrix2)
{
    // Generate the first matrix
    generateSparseMatrix(matrix1);

    // Ensure matrix2 has the same dimensions as matrix1
    matrix2.numRows = matrix1.numRows;
    matrix2.numCols = matrix1.numCols;
    matrix2.nnz = 0;

    // Define the density for the second matrix
    const double density = 0.3;  // Adjust the density for the second matrix

    matrix2.AN = new int[matrix2.numCols * matrix2.numRows];
    matrix2.JA = new int[matrix2.numCols * matrix2.numRows];
    matrix2.IA = new int[matrix2.numRows + 1];

    for (int i = 0; i < matrix2.numRows; ++i)
    {
        matrix2.IA[i] = matrix2.nnz;

        for (int j = 0; j < matrix2.numCols; ++j)
        {
            if (rand() / static_cast<double>(RAND_MAX) < density)
            {
                int value = rand() % (100 + 1);
                matrix2.AN[matrix2.nnz] = value;
                matrix2.JA[matrix2.nnz] = j;
                matrix2.nnz++;
            }
        }
    }

    matrix2.IA[matrix2.numRows] = matrix2.nnz;
}

CRSMatrix<int> sparseMatrixProduct(const CRSMatrix<int>& matrix1, const CRSMatrix<int>& matrix2)
{
    CRSMatrix<int> result;

    // Check if the matrix dimensions are compatible for multiplication
    if (matrix1.numCols != matrix2.numRows) {
        cerr << "Error: Incompatible matrix dimensions for multiplication." << endl;
        cerr << "Matrix 1 columns: " << matrix1.numCols << ", Matrix 2 rows: " << matrix2.numRows << endl;
        return result;  // Return an empty matrix as an error indicator
    }

    // Initialize result matrix dimensions
    result.numRows = matrix1.numRows;
    result.numCols = matrix2.numCols;
    result.nnz = 0;

    // Allocate memory for result matrix
    result.AN = new int[result.numCols * result.numRows];
    result.JA = new int[result.numCols * result.numRows];
    result.IA = new int[result.numRows + 1];

    // Iterate through the rows of the first matrix
    for (int i = 0; i < matrix1.numRows; ++i) {
        // Initialize a temporary array to store the result of the dot product
        int* tempRow = new int[result.numCols];
        fill(tempRow, tempRow + result.numCols, 0);

        // Iterate through the non-zero elements of the current row in the first matrix
        for (int j = matrix1.IA[i]; j < matrix1.IA[i + 1]; ++j) {
            int colIndex = matrix1.JA[j];  // Column index of the non-zero element
            int value = matrix1.AN[j];      // Value of the non-zero element

            // Iterate through the columns of the second matrix corresponding to the non-zero element
            for (int k = matrix2.IA[colIndex]; k < matrix2.IA[colIndex + 1]; ++k) {
                int rowIndex = i;               // Row index in the result matrix
                int columnIndex = matrix2.JA[k]; // Column index in the result matrix
                int product = value * matrix2.AN[k]; // Product of the non-zero elements

                // Add the product to the temporary array
                tempRow[columnIndex] += product;
            }
        }

        // Update the result matrix with the computed values from the temporary array
        for (int colIndex = 0; colIndex < result.numCols; ++colIndex) {
            if (tempRow[colIndex] != 0) {
                result.AN[result.nnz] = tempRow[colIndex];
                result.JA[result.nnz] = colIndex;
                ++result.nnz;
            }
        }

        // Update the IA array with the current nnz count
        result.IA[i + 1] = result.nnz;

        // Deallocate memory for the temporary array
        delete[] tempRow;
    }

    return result;
}

CRSMatrix<int> standardMatrixProduct(const CRSMatrix<int>& matrix1, const CRSMatrix<int>& matrix2)
{
    CRSMatrix<int> result;

    // Check if the matrix dimensions are compatible for multiplication
    if (matrix1.numCols != matrix2.numRows) {
        cerr << "Error: Incompatible matrix dimensions for multiplication." << endl;
        return result;  // Return an empty matrix as an error indicator
    }

    // Initialize result matrix dimensions
    result.numRows = matrix1.numRows;
    result.numCols = matrix2.numCols;
    result.nnz = 0;

    // Allocate memory for result matrix
    result.AN = new int[result.numCols * result.numRows];
    result.JA = new int[result.numCols * result.numRows];
    result.IA = new int[result.numRows + 1];

    // Iterate through the rows of the first matrix
    for (int i = 0; i < matrix1.numRows; ++i) {
        // Iterate through the columns of the second matrix
        for (int j = 0; j < matrix2.numCols; ++j) {
            int dotProduct = 0;

            // Compute the dot product of the current row from the first matrix and current column from the second matrix
            for (int k = 0; k < matrix1.numCols; ++k) {
                int value1 = getCRSMatrixElement(matrix1, i, k);
                int value2 = getCRSMatrixElement(matrix2, k, j);
                dotProduct += value1 * value2;
            }

            // If the dot product is non-zero, update the result matrix
            if (dotProduct != 0) {
                result.AN[result.nnz] = dotProduct;
                result.JA[result.nnz] = j;
                ++result.nnz;
            }
        }

        // Update the IA array with the current nnz count
        result.IA[i + 1] = result.nnz;
    }

    return result;
}

// Function to compare the time and memory usage for both algorithms
void compareAlgorithms(const CRSMatrix<int>& matrix1, const CRSMatrix<int>& matrix2) {
    // Measure time and memory for sparse algorithm
    double sparseStartTime = getCurrentTimeInSeconds();
    CRSMatrix<int> sparseResult = sparseMatrixProduct(matrix1, matrix2);
    double sparseEndTime = getCurrentTimeInSeconds();
    double sparseTime = sparseEndTime - sparseStartTime;

    // Measure time and memory for standard algorithm
    double standardStartTime = getCurrentTimeInSeconds();
    CRSMatrix<int> standardResult = standardMatrixProduct(matrix1, matrix2);
    double standardEndTime = getCurrentTimeInSeconds();
    double standardTime = standardEndTime - standardStartTime;

    // Print the results
    cout << "Sparse Algorithm Time: " << sparseTime << " seconds, Memory: " << sizeof(sparseResult) << " bytes" << endl;
    cout << "Standard Algorithm Time: " << standardTime << " seconds, Memory: " << sizeof(standardResult) << " bytes" << endl;

    // Additional code for comparing the content of the results if needed
}



void CRSMatrixOperationsMenu(CRSMatrix<int>& matrix1, CRSMatrix<int>& matrix2) {
    char choice;
    do {
        cout << "Matrix Operations Menu:" << endl;
        cout << "[1] Display Matrices" << endl;
        cout << "[2] Print Sparse Matrices as 1D Arrays" << endl;
        cout << "[3] Compute Sparse Matrix Product" << endl;
        cout << "[4] Compute Standard Matrix Product" << endl;
        cout << "[5] Compare Algorithms" << endl;
        cout << "[0] Back to Main Menu" << endl;

        int operation = getValue<int>([](int val) {
            return val >= 0 && val <= 5;
        });

        switch (operation) {
            case 1:
                cout << "Matrix 1:" << endl;
                printCRSMatrix(matrix1);
                cout << "Matrix 2:" << endl;
                printCRSMatrix(matrix2);
                break;
            case 2:
                cout << "Sparse Matrix 1 as 1D Array:" << endl;
                print1DArray(matrix1.AN, matrix1.nnz);
                cout << "Sparse Matrix 2 as 1D Array:" << endl;
                print1DArray(matrix2.AN, matrix2.nnz);
                break;
            case 3:
                cout << "Sparse Matrix Product:" << endl;
                printCRSMatrix(sparseMatrixProduct(matrix1, matrix2));
                break;
            case 4:
                cout << "Standard Matrix Product:" << endl;
                printCRSMatrix(standardMatrixProduct(matrix1, matrix2));
                break;
            case 5:
                compareAlgorithms(matrix1, matrix2);
                break;
            case 0:
                return;
            default:
                cout << "Invalid operation." << endl;
                break;
        }

        cout << "Do you want to perform another operation? (y/n): ";
        choice = getYesOrNo();

    } while (choice == 'y');
}

