#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

using Matrix = vector<vector<int>>;

// Function prototypes
bool loadMatrices(const string& filename, Matrix& A, Matrix& B, int& N);
void printMatrix(const Matrix& M);
Matrix addMatrices(const Matrix& A, const Matrix& B);
Matrix multiplyMatrices(const Matrix& A, const Matrix& B);
void diagonalSums(const Matrix& M);
void swapRows(Matrix& M, int r1, int r2);
void swapCols(Matrix& M, int c1, int c2);
void updateElement(Matrix& M, int r, int c, int value);


int main() {
    string filename;
    cout << "Enter the input file name: ";
    cin >> filename;

    Matrix A, B;
    int N;

    if (!loadMatrices(filename, A, B, N)) {
        cerr << "Error loading file" << endl;
        return 1;
    }

    cout << "\nMatrix A:\n";
    printMatrix(A);
    cout << "\nMatrix B:\n";
    printMatrix(B);

    // 2. Add
    cout << "\nA + B = \n";
    Matrix sum = addMatrices(A, B);
    printMatrix(sum);

    // 3. Multiply
    cout << "\nA * B = \n";
    Matrix product = multiplyMatrices(A, B);
    printMatrix(product);

    // 4. Diagonal sums
    cout << "\nDiagonal sums for A:\n";
    diagonalSums(A);

    // 5. Swap rows
    cout << "\nSwapping rows 0 and 2 in A:\n";
    swapRows(A, 0, 2);
    printMatrix(A);

    // 6. Swap columns
    cout << "\nSwapping columns 1 and 3 in A:\n";
    swapCols(A, 1, 3);
    printMatrix(A);

    // 7. Update element
    cout << "\nUpdating element (2,2) to 99:\n";
    updateElement(A, 2, 2, 99);
    printMatrix(A);

    return 0;
}

// 1. Load from file
bool loadMatrices(const string& filename, Matrix& A, Matrix& B, int& N) {
    ifstream fin(filename);
    if (!fin.is_open()) return false;

    fin >> N;
    A.assign(N, vector<int>(N));
    B.assign(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> A[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> B[i][j];

    fin.close();
    return true;
}

// Print with formatting
void printMatrix(const Matrix& M) {
    for (auto& row : M) {
        for (auto& val : row)
            cout << setw(4) << val;
        cout << '\n';
    }
}

// 2. Add
Matrix addMatrices(const Matrix& A, const Matrix& B) {
    int N = A.size();
    Matrix C(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// 3. Multiply
Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    int N = A.size();
    Matrix C(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// 4. Diagonal sums
void diagonalSums(const Matrix& M) {
    int N = M.size();
    int mainSum = 0, secSum = 0;
    for (int i = 0; i < N; i++) {
        mainSum += M[i][i];
        secSum += M[i][N - 1 - i];
    }
    cout << "Main diagonal sum: " << mainSum << endl;
    cout << "Secondary diagonal sum: " << secSum << endl;
}

// 5. Swap rows
void swapRows(Matrix& M, int r1, int r2) {
    int N = M.size();
    if (r1 < 0 || r1 >= N || r2 < 0 || r2 >= N) {
        cout << "Invalid row.\n";
        return;
    }
    swap(M[r1], M[r2]);
}

// 6. Swap columns
void swapCols(Matrix& M, int c1, int c2) {
    int N = M.size();
    if (c1 < 0 || c1 >= N || c2 < 0 || c2 >= N) {
        cout << "Invalid column.\n";
        return;
    }
    for (int i = 0; i < N; i++)
        swap(M[i][c1], M[i][c2]);
}

// 7. Update element
void updateElement(Matrix& M, int r, int c, int value) {
    int N = M.size();
    if (r < 0 || r >= N || c < 0 || c >= N) {
        cout << "Invalid.\n";
        return;
    }
    M[r][c] = value;
}