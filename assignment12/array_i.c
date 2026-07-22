#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double *data;
    int rows, cols;
} Matrix;

typedef double (*MapFunc)(double value, double param);

double threshold_map(double value, double threshold)
{
    return value >= threshold ? 1.0 : 0.0;
}

Matrix map(Matrix m, MapFunc func, double param)
{
    Matrix result;
    result.rows = m.rows;
    result.cols = m.cols;

    result.data = malloc(result.rows * result.cols * sizeof(double));

    for(int i = 0; i < m.rows; i++){
        for (int j = 0; j < m.cols; j++)
        {
            double mapResult = func(m.data[i * m.cols + j], param);

            result.data[i * result.cols + j] = mapResult;
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

int main(void)
{
    // Testdaten: 2x3 Matrix
    double a[2][3] = {
        {1.5, 4.0, 0.2},
        {7.8, 3.0, 5.5}};
    Matrix m = {(double *)a, 2, 3};

    printf("Original Matrix:\n");
    print_matrix(m);

    double threshold = 3.0;

    // Aufruf der map-Funktion mit der Schwellenwert-Funktion
    Matrix mapped_matrix = map(m, threshold_map, threshold);

    printf("Mapped Matrix (Schwellenwert = %g):\n", threshold);
    print_matrix(mapped_matrix);

    // Speicher wieder freigeben
    free(mapped_matrix.data);

    return 0;
}