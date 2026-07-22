/*
Compile: make transpose
Run: ./transpose
make transpose && ./transpose
*/

#include "base.h"

typedef struct
{
    double *data;
    int rows, cols;
} Matrix;

Matrix transpose(Matrix m)
{
    Matrix result;

    result.cols = m.rows;
    result.rows = m.cols;

    result.data = xmalloc(result.cols * result.rows * sizeof(double));

    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            double value = m.data[i * m.cols + j];
            result.data[j * result.cols + i] = value;
        }
    }

    return result;
}

void print_matrix(Matrix m)
{
    int i = 0;
    for (int y = 0; y < m.rows; y++)
    {
        for (int x = 0; x < m.cols; x++)
        {
            printf("%g ", m.data[i++]);
        }
        printf("\n");
    }
    printf("\n");
}

void test(void)
{
    // Testdaten: 2x3 Matrix
    double a[2][3] = {
        {1, 2, 3},
        {4, 5, 6},
    };
    Matrix m = {(double *)a, 2, 3};

    printf("Original Matrix:\n");
    print_matrix(m);

    // Funktionsaufruf
    Matrix result = transpose(m);

    printf("Transponierte Matrix:\n");
    print_matrix(result);
    printf("%d rows, %d cols\n", result.rows, result.cols);
}

int main(void)
{
    test();
    return 0;
}