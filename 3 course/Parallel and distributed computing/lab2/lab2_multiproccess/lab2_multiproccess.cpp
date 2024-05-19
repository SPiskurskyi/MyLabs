#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <chrono>
#include "mpi.h"

using namespace std;

// ініціалізація функцій для роботи з матрицями
double** createEmptyMatrix(int rows, int cols);
void deleteMatrix(double** matrix, int rows);
void fillMatrix(double** matrix, int rows, int cols);
void fillMatrixRandom(double** matrix, int rows, int cols);
void chooseTypeFill(double** matrix, int rows, int cols);
double** multiplyMatrices(double** matrix1, double** matrix2, int rows1, int cols1, int rows2, int cols2);
double** multiplyMatrixByScalar(double** matrix, int rows, int cols, double scalar);
double** addMatrices(double** matrix1, double** matrix2, int rows, int cols);
double** subMatrices(double** matrix1, double** matrix2, int rows, int cols);
double** transposeMatrix(double** matrix, int rows, int cols);
string matrixToString(double** matrix, int rows, int cols);
void appendMatrixToFile(double** matrix, int rows, int cols, ofstream& outputFile);
double* convertTo1D(double** array, int rows, int cols);
double** convertTo2D(double* array, int rows, int cols);
double* allocateMemoryFor1DArray(int size);



int main(int argc, char** argv) {
    // MPI
    int numtasks, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        // введення розміру матриць і вибору отримання результатів
        int n;
        while (true) {
            cout << "Enter n: ";
            cin >> n;
            if (n > 0) {
                break;
            }
            else {
                cout << "\"n\" must be greater or equals than 1. Try again." << endl;
            }
        }
        int choice;
        while (true) {
            cout << "\nEnter 1 to write all data to file or 2 to print on screen: ";
            cin >> choice;
            if (choice == 1 || choice == 2) {
                break;
            }
            else {
                cout << "Enter correct choice!" << endl;
            }
        }
        cout << endl;



        // створення і заповнення A КОРИСТУВАЧЕМ
        double** A = createEmptyMatrix(n, n);
        cout << "Matrix A (n * n)" << endl;
        chooseTypeFill(A, n, n);

        // створення і заповнення A1 КОРИСТУВАЧЕМ
        double** A1 = createEmptyMatrix(n, n);
        cout << "Matrix A1 (n * n)" << endl;
        chooseTypeFill(A1, n, n);

        // створення і заповнення b1 КОРИСТУВАЧЕМ
        double** b1 = createEmptyMatrix(n, 1);
        cout << "Matrix b1 (n * 1)" << endl;
        chooseTypeFill(b1, n, 1);

        // створення і заповнення c1 КОРИСТУВАЧЕМ
        double** c1 = createEmptyMatrix(n, 1);
        cout << "Matrix c1 (n * 1)" << endl;
        chooseTypeFill(c1, n, 1);

        // створення і заповнення A2 КОРИСТУВАЧЕМ
        double** A2 = createEmptyMatrix(n, n);
        cout << "Matrix A2 (n * n)" << endl;
        chooseTypeFill(A2, n, n);

        // створення і заповнення B2 КОРИСТУВАЧЕМ
        double** B2 = createEmptyMatrix(n, n);
        cout << "Matrix B2 (n * n)" << endl;
        chooseTypeFill(B2, n, n);


        // надсилання розміру і вибору виводу процесу 1
        MPI_Send(&n, 1, MPI_INT, 1, 101, MPI_COMM_WORLD);
        MPI_Send(&choice, 1, MPI_INT, 1, 102, MPI_COMM_WORLD);

        // надсилання даних процесу 1
        double* A1_send = convertTo1D(A1, n, n);
        double* b1_send = convertTo1D(b1, n, 1);
        double* c1_send = convertTo1D(c1, n, 1);
        MPI_Send(A1_send, n * n, MPI_DOUBLE, 1, 103, MPI_COMM_WORLD);
        MPI_Send(b1_send, n * 1, MPI_DOUBLE, 1, 104, MPI_COMM_WORLD);
        MPI_Send(c1_send, n * 1, MPI_DOUBLE, 1, 105, MPI_COMM_WORLD);

        // надсилання даних процесу 2
        double* A2_send = convertTo1D(A2, n, n);
        double* B2_send = convertTo1D(B2, n, n);
        MPI_Send(A2_send, n * n, MPI_DOUBLE, 2, 106, MPI_COMM_WORLD);
        MPI_Send(B2_send, n * n, MPI_DOUBLE, 2, 107, MPI_COMM_WORLD);

        // стоврення і заповнення b ПО ЗАМОВЧУВАННЮ
        double** b = createEmptyMatrix(n, 1);
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                b[i - 1][0] = i;
            }
            else {
                b[i - 1][0] = 15 / i;
            }
        }

        // обрахунок y1 = A * b
        double** y1 = multiplyMatrices(A, b, n, n, n, 1);
        double** y1T = transposeMatrix(y1, n, 1);

        //пересилка в 2 процес
        double* y1_send = convertTo1D(y1, n, 1);
        MPI_Send(y1_send, n, MPI_DOUBLE, 2, 501, MPI_COMM_WORLD);

        double* y2_recv = allocateMemoryFor1DArray(n);
        MPI_Recv(y2_recv, n, MPI_DOUBLE, 1, 502, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        double** y2 = convertTo2D(y2_recv, n, 1);

        double** y2y1T = multiplyMatrices(y2, y1T, n, 1, 1, n);

        double* y2T_recv = allocateMemoryFor1DArray(n);
        MPI_Recv(y2T_recv, n, MPI_DOUBLE, 1, 504, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        double** y2T = convertTo2D(y2T_recv, 1, n);

        double* y2y1T_send = convertTo1D(y2y1T, n, n);
        MPI_Send(y2y1T_send, n * n, MPI_DOUBLE, 1, 503, MPI_COMM_WORLD);

        double** y1T_plus_y2T = addMatrices(y1T, y2T, 1, n);

        double* y1T_plus_y2T_send = convertTo1D(y1T_plus_y2T, 1, n);
        MPI_Send(y1T_plus_y2T_send, n, MPI_DOUBLE, 1, 505, MPI_COMM_WORLD);


        // типи виводу
        if (choice == 1) {
            // створення і заповнення файлу
            ofstream outputFile("Process1.txt", ios::app);
            outputFile << "<=== Process 1 ===>" << endl << endl
                << "A:" << endl << matrixToString(A, n, n) << endl
                << "A1:" << endl << matrixToString(A1, n, n) << endl
                << "b1:" << endl << matrixToString(b1, n, 1) << endl
                << "c1:" << endl << matrixToString(c1, n, 1) << endl
                << "A2:" << endl << matrixToString(A2, n, n) << endl
                << "B2:" << endl << matrixToString(B2, n, n) << endl
                << "b:" << endl << matrixToString(b, n, 1) << endl
                << "y1:" << endl << matrixToString(y1, n, 1) << endl
                << "y1T:" << endl << matrixToString(y1T, 1, n) << endl
                << "y2y1T:" << endl << matrixToString(y2y1T, 1, 1) << endl
                << "y1T_plus_y2T:" << endl << matrixToString(y1T_plus_y2T, 1, n) << endl << endl;
            outputFile.close();
        }
        else if (choice == 2) {
            cout << "<=== Process 1 ===>" << endl << endl
                << "A:" << endl << matrixToString(A, n, n) << endl
                << "A1:" << endl << matrixToString(A1, n, n) << endl
                << "b1:" << endl << matrixToString(b1, n, 1) << endl
                << "c1:" << endl << matrixToString(c1, n, 1) << endl
                << "A2:" << endl << matrixToString(A2, n, n) << endl
                << "B2:" << endl << matrixToString(B2, n, n) << endl
                << "b:" << endl << matrixToString(b, n, 1) << endl
                << "y1:" << endl << matrixToString(y1, n, 1) << endl
                << "y1T:" << endl << matrixToString(y1T, 1, n) << endl
                << "y2y1T:" << endl << matrixToString(y2y1T, 1, 1) << endl
                << "y1T_plus_y2T:" << endl << matrixToString(y1T_plus_y2T, 1, n) << endl << endl;
            
            int signal = 1;
            MPI_Send(&signal, 1, MPI_INT, 1, 901, MPI_COMM_WORLD);
        }

    }
    else if (rank == 1) {


        // отримання розміру та вибору
        int n, choice;
        MPI_Recv(&n, 1, MPI_INT, 0, 101, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&choice, 1, MPI_INT, 0, 102, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // отримання робочих матриць
        double* A1_recv = allocateMemoryFor1DArray(n * n);
        double* b1_recv = allocateMemoryFor1DArray(n * 1);
        double* c1_recv = allocateMemoryFor1DArray(n * 1);

        MPI_Recv(A1_recv, n* n, MPI_DOUBLE, 0, 103, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(b1_recv, n * 1, MPI_DOUBLE, 0, 104, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(c1_recv, n * 1, MPI_DOUBLE, 0, 105, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        double** A1 = convertTo2D(A1_recv, n, n);
        double** b1 = convertTo2D(b1_recv, n, 1);
        double** c1 = convertTo2D(c1_recv, n, 1);

        // надсилання розміру і вибору процесу 2
        MPI_Send(&n, 1, MPI_INT, 2, 111, MPI_COMM_WORLD);
        MPI_Send(&choice, 1, MPI_INT, 2, 112, MPI_COMM_WORLD);

        // таймер старт
        auto start = chrono::high_resolution_clock::now();

        // обрахунок y2 = 15 * b1 * A1 + c1
        b1 = multiplyMatrixByScalar(b1, n, 1, 15);
        double** A1_mult_b1 = multiplyMatrices(A1, b1, n, n, n, 1);
        double** y2 = addMatrices(A1_mult_b1, c1, n, 1);
        double** y2T = transposeMatrix(y2, n, 1);

        double* y2_send = convertTo1D(y2, n, 1);
        MPI_Send(y2_send, n, MPI_DOUBLE, 0, 502, MPI_COMM_WORLD);

        double* y2T_send = convertTo1D(y2T, 1, n);
        MPI_Send(y2T_send, n, MPI_DOUBLE, 0, 504, MPI_COMM_WORLD);

        double* y2y1T_recv = allocateMemoryFor1DArray(n * n);
        MPI_Recv(y2y1T_recv, n * n, MPI_DOUBLE, 0, 503, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        double** y2y1T = convertTo2D(y2y1T_recv, n, n);

        double** y2Ty2y1T = multiplyMatrices(y2T, y2y1T, 1, n, n, n);

        double* Y3_recv = allocateMemoryFor1DArray(n * n);
        MPI_Recv(Y3_recv, n * n, MPI_DOUBLE, 2, 506, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        double** Y3 = convertTo2D(Y3_recv, n, n);

        double** y2Ty2y1TY3 = multiplyMatrices(y2Ty2y1T, Y3, 1, n, n, n);

        double* y1T_plus_y2T_recv = allocateMemoryFor1DArray(n);
        MPI_Recv(y1T_plus_y2T_recv, n, MPI_DOUBLE, 0, 505, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        double** y1T_plus_y2T = convertTo2D(y1T_plus_y2T_recv, 1, n);
        
        double* Y3Y3y1_T_recv = allocateMemoryFor1DArray(n);
        MPI_Recv(Y3Y3y1_T_recv, n, MPI_DOUBLE, 2, 507, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        double** Y3Y3y1_T = convertTo2D(Y3Y3y1_T_recv, 1, n);

        double** x = addMatrices(addMatrices(y1T_plus_y2T, Y3Y3y1_T, 1, n), y2Ty2y1TY3, 1, n);

        // таймер стоп
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start);
        int time = duration.count();

        // типи виводу
        if (choice == 1) {
            // створення і заповнення файлу
            ofstream outputFile("Process2.txt", ios::app);
            outputFile << "<=== Process 2 ===>" << endl << endl
                << "A1:" << endl << matrixToString(A1, n, n) << endl
                << "b1:" << endl << matrixToString(b1, n, 1) << endl
                << "c1:" << endl << matrixToString(c1, n, 1) << endl
                << "A1_mult_b1:" << endl << matrixToString(A1_mult_b1, n, 1) << endl
                << "y2:" << endl << matrixToString(y2, n, 1) << endl
                << "y2T:" << endl << matrixToString(y2T, 1, n) << endl
                << "y2Ty2y1T:" << endl << matrixToString(y2Ty2y1T, 1, n) << endl
                << "y2Ty2y1TY3:" << endl << matrixToString(y2Ty2y1TY3, 1, n) << endl
                << "x:" << endl << matrixToString(x, 1, n) << endl
                << "TIME: " << time << " milliseconds " << endl << endl;
            outputFile.close();
        }
        else if (choice == 2) {
            int signal;
            MPI_Recv(&signal, 1, MPI_INT, 0, 901, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            cout << "<=== Process 2 ===>" << endl << endl
                << "A1:" << endl << matrixToString(A1, n, n) << endl
                << "b1:" << endl << matrixToString(b1, n, 1) << endl
                << "c1:" << endl << matrixToString(c1, n, 1) << endl
                << "A1_mult_b1:" << endl << matrixToString(A1_mult_b1, n, 1) << endl
                << "y2:" << endl << matrixToString(y2, n, 1) << endl
                << "y2T:" << endl << matrixToString(y2T, 1, n) << endl
                << "y2Ty2y1T:" << endl << matrixToString(y2Ty2y1T, 1, n) << endl
                << "y2Ty2y1TY3:" << endl << matrixToString(y2Ty2y1TY3, 1, n) << endl
                << "x:" << endl << matrixToString(x, 1, n) << endl 
                << "TIME: " << time << " milliseconds " << endl << endl;

            MPI_Send(&signal, 1, MPI_INT, 2, 902, MPI_COMM_WORLD);
        }

    }
    else if (rank == 2) {
        // отримання вибору і розміру
        int n, choice;
        MPI_Recv(&n, 1, MPI_INT, 1, 111, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&choice, 1, MPI_INT, 1, 112, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // отримання робочих матриць
        double* A2_recv = allocateMemoryFor1DArray(n * n);
        double* B2_recv = allocateMemoryFor1DArray(n * n);

        MPI_Recv(A2_recv, n* n, MPI_DOUBLE, 0, 106, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(B2_recv, n* n, MPI_DOUBLE, 0, 107, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        double** A2 = convertTo2D(A2_recv, n, n);
        double** B2 = convertTo2D(B2_recv, n, n);
        
        // створення і заповнення C2 ПО ЗАМОВЧУВАННЮ
        double** C2 = createEmptyMatrix(n, n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < n; j++) {
                C2[i - 1][j - 1] = 15 / (pow((double)i, 2) + (double)j);
            }
            C2[i - 1][n - 1] = 15 / (pow((double)i, 2) + (double)n);
        }

        // обрахунок Y3 = A2 * C2 + B2
        double** A2_mult_C2 = multiplyMatrices(A2, C2, n, n, n, n);
        double** Y3 = addMatrices(A2_mult_C2, B2, n, n);

        double* Y3_send = convertTo1D(Y3, n, n);
        MPI_Send(Y3_send, n * n, MPI_DOUBLE, 1, 506, MPI_COMM_WORLD);

        double** Y3Y3 = multiplyMatrices(Y3, Y3, n, n, n, n);

        double* y1_recv = allocateMemoryFor1DArray(n);
        MPI_Recv(y1_recv, n, MPI_DOUBLE, 0, 501, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        double** y1 = convertTo2D(y1_recv, n, 1);

        double** Y3Y3y1 = multiplyMatrices(Y3Y3, y1, n, n, n, 1);
        double** Y3Y3y1_T = transposeMatrix(Y3Y3y1, n, 1);

        double* Y3Y3y1_T_send = convertTo1D(Y3Y3y1_T, 1, n);
        MPI_Send(Y3Y3y1_T_send, n, MPI_DOUBLE, 1, 507, MPI_COMM_WORLD);

        // типи виводу
        if (choice == 1) {
            // створення і заповнення файлу
            ofstream outputFile("Process3.txt", ios::app);
            outputFile << "<=== Process 3 ===>" << endl << endl
                << "A2:" << endl << matrixToString(A2, n, n) << endl
                << "B2:" << endl << matrixToString(B2, n, n) << endl
                << "C2:" << endl << matrixToString(C2, n, n) << endl
                << "A2_mult_C2:" << endl << matrixToString(A2_mult_C2, n, n) << endl
                << "Y3:" << endl << matrixToString(Y3, n, n) << endl
                << "Y3Y3:" << endl << matrixToString(Y3Y3, n, n) << endl
                << "Y3Y3y1:" << endl << matrixToString(Y3Y3y1, n, 1) << endl
                << "Y3Y3y1_T:" << endl << matrixToString(Y3Y3y1_T, 1, n) << endl;
            outputFile.close();
        }
        else if (choice == 2) {
            int signal;
            MPI_Recv(&signal, 1, MPI_INT, 1, 902, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            cout << "<=== Process 3 ===>" << endl << endl
                << "A2:" << endl << matrixToString(A2, n, n) << endl
                << "B2:" << endl << matrixToString(B2, n, n) << endl
                << "C2:" << endl << matrixToString(C2, n, n) << endl
                << "A2_mult_C2:" << endl << matrixToString(A2_mult_C2, n, n) << endl
                << "Y3:" << endl << matrixToString(Y3, n, n) << endl
                << "Y3Y3:" << endl << matrixToString(Y3Y3, n, n) << endl
                << "Y3Y3y1:" << endl << matrixToString(Y3Y3y1, n, 1) << endl
                << "Y3Y3y1_T:" << endl << matrixToString(Y3Y3y1_T, 1, n) << endl;
        }
    }

    MPI_Finalize();
    return 0;
}



// Функція для створення пустої матриці заданого розміру
double** createEmptyMatrix(int rows, int cols) {
    // Виділення пам'яті для двовимірного масиву
    double** matrix = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
    }
    return matrix;
}

// виділення пам'яті під одновимірний масив
double* allocateMemoryFor1DArray(int size) {
    return new double[size];
}

// Функція для звільнення пам'яті, зайнятої матрицею
void deleteMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Функція для заповнення матриці з клавіатури
void fillMatrix(double** matrix, int rows, int cols) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Функція для заповнення матриці випадковими числами
void fillMatrixRandom(double** matrix, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = (double)(rand() % 10 + 1);
        }
    }
}

// Функція для вибору заповнення
void chooseTypeFill(double** matrix, int rows, int cols) {
    int choice;
    while (true) {
        cout << "Enter 1 to manually or 2 to generation: ";
        cin >> choice;
        if (choice == 1) {
            fillMatrix(matrix, rows, cols);
            cout << "Matrix is full." << endl << endl;
            break;
        }
        else if (choice == 2) {
            fillMatrixRandom(matrix, rows, cols);
            cout << "Matrix is full." << endl << endl;
            break;
        }
        else {
            cout << "Wrong option. Try again." << endl << endl;
        }
    }
}

// Функція для множення двох матриць
double** multiplyMatrices(double** matrix1, double** matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        cout << "Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return nullptr;
    }
    double** resultMatrix = createEmptyMatrix(rows1, cols2);
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return resultMatrix;
}

// Функція для множення матриці на число
double** multiplyMatrixByScalar(double** matrix, int rows, int cols, double scalar) {
    double** resultMatrix = createEmptyMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            resultMatrix[i][j] = matrix[i][j] * scalar;
        }
    }
    return resultMatrix;
}

// Функція для додавання двох матриць
double** addMatrices(double** matrix1, double** matrix2, int rows, int cols) {
    double** resultMatrix = createEmptyMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return resultMatrix;
}

// Функція для віднімання двох матриць
double** subMatrices(double** matrix1, double** matrix2, int rows, int cols) {
    double** resultMatrix = createEmptyMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return resultMatrix;
}

// Функція для транспонування матриці
double** transposeMatrix(double** matrix, int rows, int cols) {
    double** transposedMatrix = createEmptyMatrix(cols, rows);
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
    return transposedMatrix;
}

// Функція для створення стрінги з матриці
string matrixToString(double** matrix, int rows, int cols) {
    string result;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result += to_string(matrix[i][j]) + " ";
        }
        result += "\n"; // Додаємо роздільник нового рядка після кожного рядка матриці
    }
    return result;
}

// Функція для запису матриці у файл (дозапис)
void appendMatrixToFile(double** matrix, int rows, int cols, ofstream& outputFile) {

    if (!outputFile.is_open()) {
        cout << "Error: Unable to open file for writing." << endl;
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            outputFile << matrix[i][j] << " ";
        }
        outputFile << endl;
    }
}

// Функція для конвертації двовимірного масиву у одновимірний
double* convertTo1D(double** array, int rows, int cols) {
    double* result = new double[rows * cols];
    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[index++] = array[i][j];
        }
    }
    return result;
}

// Функція для конвертації одновимірного масиву у двовимірний
double** convertTo2D(double* array, int rows, int cols) {
    double** result = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        result[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            result[i][j] = array[i * cols + j];
        }
    }
    return result;
}