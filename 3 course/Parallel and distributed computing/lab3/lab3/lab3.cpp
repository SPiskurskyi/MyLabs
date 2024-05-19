//тестова програма
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>
int** CreateMatrix(int n);
int*** CreateMatrix3D(int n);

void DeleteMatrix(int** a, int n);
void DeleteMatrix3D(int*** a, int n);

void FillMatrixA(int** a, int n);
void FillMatrixB(int** a, int n);

void InputMatrix(int** a, int n);
void PrintMatrix(int** a, int n);
void PrintMatrix3D(int*** a, int n);
void PrintMatrixToFile(FILE* f, char* title, int** a, int n);
int** Martix3Dto2D(int** a, int*** b, int n);

int** MultMatrix(int** c, int** a, int** b, int n);
int** MultMatrixOneTime(int** c, int** a, int** b, int n);
int** MultMatrixLocalAlgorithm(int** c, int** a, int** b, int n);
void MultMatrixRecursAalgorithm(int*** c3D, int*** a3D, int*** b3D, int n);
int*** MultMatrixRA(int** a, int** b, int n);
int NumberOfMult(int** c, int n);

int c_ops = 0;

int main(void)
{
    srand((unsigned int)time(NULL));
    int n;
    printf("Enter the matrix size n : ");
    scanf_s("%d", &n);
    int** A = CreateMatrix(n);
    int** B = CreateMatrix(n);
    int in;
    printf("\nSelect an input option : 1 - manual input, else - random input : ");
    scanf_s("%d", &in);
    printf("\n");
    const char* fileName = "Results.txt";
    FILE* file = fopen(fileName, "w");
    if (file == NULL)
    {
        printf("\nError opening file. Check the path and permissions !\n");
        return 1;
    }
    if (in == 1)
    {
        // input matrix A
        FillMatrixA(A, n);
        PrintMatrixToFile(file, (char*)"Matrix A = ", A, n);
        printf("Matrix A :\n");
        PrintMatrix(A, n);
        // manual input matrix B
        printf("Enter the elements of matrix B :\n");
        InputMatrix(B, n);
        PrintMatrixToFile(file, (char*)"Matrix B = ", B, n);
        printf("Matrix B :\n");
        PrintMatrix(B, n);
    }
    else
    {
        printf("Random input... \n\n"); \
            // random input matrix A
            FillMatrixA(A, n);
        PrintMatrixToFile(file, (char*)"Matrix B = ", A, n);
        printf("Matrix A :\n");
        PrintMatrix(A, n);
        // random input matrix B
        FillMatrixB(B, n);
        PrintMatrixToFile(file, (char*)"Matrix B = ", B, n);
        printf("Matrix B :\n");
        PrintMatrix(B, n);
    }
    int** C = CreateMatrix(n);
    MultMatrix(C, A, B, n);
    printf("\n");
    printf("Matrix C = A * B :\n");
    PrintMatrixToFile(file, (char*)"(common) Matrix C = A * B = ", C, n);
    PrintMatrix(C, n);
    printf("Number of multiplication operations : %d \n", (n * n * n));
    printf("Number of addition operations : %d \n", ((n - 1) * n * n));
    printf("Total number of operations : %d \n", (n * n * n) + ((n - 1) * n * n));
    printf("\n");
    MultMatrixOneTime(C, A, B, n);
    printf("Matrix C = A * B, program with one-time assignment :\n");
    PrintMatrixToFile(file, (char*)"(program with one-time assignment) Matrix C = A * B = ", C, n);
    PrintMatrix(C, n);
    printf("Number of multiplication operations : %d \n", (n * n * n));
    printf("Number of addition operations : %d \n", (n * n * n));
    printf("Total number of operations : %d \n", (n * n * n) * 2);
    printf("\n");
    MultMatrixLocalAlgorithm(C, A, B, n);
    printf("Matrix C = A * B, program with the localized algorithm:\n");
    PrintMatrixToFile(file, (char*)"(program with the localized algorithm) Matrix C = A * B = ", C, n);
    PrintMatrix(C, n);
    printf("Number of multiplication operations : %d \n", (n * n * n));
    printf("Number of addition operations : %d \n", (n * n * n));
    printf("Total number of operations : %d \n", (n * n * n) * 2);
    printf("\n");

    int*** C3D = CreateMatrix3D(n);
    C3D = MultMatrixRA(A, B, n);
    Martix3Dto2D(C, C3D, n);
    printf("Matrix C = A * B, program with the recursive localized algorithm :\n");
    PrintMatrixToFile(file, (char*)"(program with the recursive localized algorithm) Matrix C = A * B = ", C, n);
    PrintMatrix3D(C3D, n);
    printf("Number of addition operations : %d \n", c_ops);
    printf("Number of multiplication operations : 0 \n");
    printf("Total number of operations : %d \n", c_ops);
    printf("\n");
    printf("\n");
    DeleteMatrix(A, n);
    DeleteMatrix(B, n);
    DeleteMatrix(C, n);
    fclose(file);
    return 0;
}

int** CreateMatrix(int n)
{
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    return a;
}
int*** CreateMatrix3D(int n)
{
    int*** a = new int** [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int* [n];
        for (int j = 0; j < n; j++)
        {
            a[i][j] = new int[n + 1];
        }
    }
    return a;
}
void DeleteMatrix(int** a, int n)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}
void DeleteMatrix3D(int*** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            delete[] a[i][j];
        delete[] a[i];
    }
    delete[] a;
}
void FillMatrixA(int** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0, k = n - 1; j < n && k >= 0; j++, k--)
        {
            if (i < n / 2)
            {
                if (j < i + 1)
                {
                    a[i][j] = 1;
                    a[i][k] = 1;
                }
                else if (k > i) a[i][k] = 0;
            }
            else if (i >= n / 2)
            {
                if (k > i - 1)
                {
                    a[i][j] = 1;
                    a[i][k] = 1;
                }
                else if (j < i) a[i][j] = 0;
            }
        }
    }
}
void FillMatrixB(int** a, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
    for (int i = n / 2; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = (rand() % 7) + 1;
        }
    }
}
void InputMatrix(int** a, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
    printf("Enter Matrix B\n");
    for (int i = n / 2; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[%d][%d]\t", i, j);
            scanf_s("%d", &a[i][j]);
            if (a[i][j] == 0)
            {
                printf("Incorrect input, element of matrix B can`t be equal 0. Try again\n");
                j--;
            }
        }
    }
}
void PrintMatrix(int** a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    printf("\n");
}
int** Martix3Dto2D(int** a, int*** b, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            a[i][j] = b[i][j][n];
    }
    return a;
}
void PrintMatrix3D(int*** a, int n)
{
    int i, j;
    for (int k = 1; k <= n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                printf("%d\t", a[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
}
void PrintMatrixToFile(FILE* f, char* title, int** a, int n)
{
    fprintf(f, title);
    fprintf(f, "\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fprintf(f, "%d\t", a[i][j]);
        fprintf(f, "\n");
    }
    fprintf(f, "\n");
}
// c = a * b
int** MultMatrix(int** c, int** a, int** b, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
        }
    }
    return c;
}
int** MultMatrixOneTime(int** c, int** a, int** b, int n)
{
    int*** c3D = CreateMatrix3D(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c3D[i][j][0] = 0;
            for (int k = 0; k < n; k++)
                c3D[i][j][k + 1] = c3D[i][j][k] + a[i][k] * b[k][j];
        }
    }
    Martix3Dto2D(c, c3D, n);
    DeleteMatrix3D(c3D, n);
    return c;
}
int** MultMatrixLocalAlgorithm(int** c, int** a, int** b, int n)
{
    int*** c3D = CreateMatrix3D(n);
    int*** a3D = CreateMatrix3D(n);
    int*** b3D = CreateMatrix3D(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c3D[i][j][0] = 0;
            a3D[i][j][0] = a[i][j];
            b3D[i][j][0] = b[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c3D[i][j][k + 1] = c3D[i][j][k] + a3D[i][k][j] * b3D[k][j][i];
                a3D[i][k][j + 1] = a3D[i][k][j];
                b3D[k][j][i + 1] = b3D[k][j][i];
            }
        }
    }
    Martix3Dto2D(c, c3D, n);
    DeleteMatrix3D(c3D, n);
    DeleteMatrix3D(a3D, n);
    DeleteMatrix3D(b3D, n);
    return c;
}
void MultMatrixRecursAalgorithm(int*** c3D, int*** a3D, int*** b3D, int n)
{
    static int i = 0, j = 0, k = 0;
    if (i < n)
    {
        if (j < n)
        {
            if (k < n)
            {
                a3D[i][k][j + 1] = a3D[i][k][j];
                b3D[k][j][i + 1] = b3D[k][j][i];
                if (a3D[i][k][0] == 0 || k < n / 2)
                    c3D[i][j][k + 1] = 0;
                else
                {
                    c3D[i][j][k + 1] = c3D[i][j][k] + b3D[k][j][i];
                    c_ops++;
                }
                k++;
                MultMatrixRecursAalgorithm(c3D, a3D, b3D, n);
            }
            k = 0;
            j++;
            MultMatrixRecursAalgorithm(c3D, a3D, b3D, n);
        }
        j = 0;
        i++;
        MultMatrixRecursAalgorithm(c3D, a3D, b3D, n);
    }
}
int*** MultMatrixRA(int** a, int** b, int n)
{
    int*** c3D = CreateMatrix3D(n);
    int*** a3D = CreateMatrix3D(n);
    int*** b3D = CreateMatrix3D(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c3D[i][j][0] = 0;
            a3D[i][j][0] = a[i][j];
            b3D[i][j][0] = b[i][j];
        }
    }
    MultMatrixRecursAalgorithm(c3D, a3D, b3D, n);
    DeleteMatrix3D(a3D, n);
    DeleteMatrix3D(b3D, n);
    return c3D;
}
int NumberOfMult(int** c, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (c[i][j] != 0)
                count++;
            else
                continue;
        }
    }
    return count;
}