using namespace std;

char getFillMethod();

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
