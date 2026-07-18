/*
 * Vervollständigen Sie die Funktion rowMult, die als Eingabeargumente einen Zeiger auf ein Integer-Array,
 * die Anzahl der Zeilen und die Anzahl der Spalten annimmt und das Produkt der Einträge in jeder einzelnen Zeile berechnet.
 * (Tipp: Der Eingabeparameter ist ein Zeiger auf ein Array und nicht das Array direkt => Eine manuelle Zeiger-Dereferenzierung ist erforderlich)
 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"

// TODO:
int *rowMult(int *a, int row, int col)
{
    int *result = xmalloc(row * sizeof(int));

    for (int i = 0; i < row; i++)
    {
        int product = 1;
        for (int j = 0; j < col; j++)
        {
            product *= a[i * col + j];
        }

        result[i] = product;
    }
    return result;
}

int main()
{
    // ================== TEST 1: Dein Original-Beispiel (3x3 mit Nullen) ==================
    int row1 = 3;
    int col1 = 3;
    int matrix1[3][3] = {
        {1, 2, 3},
        {5, 1, 7},
        {9, 0, 0}};

    int *result1 = rowMult((int *)matrix1, row1, col1);

    if (result1 != NULL)
    {
        test_equal_i(result1[0], 6);
        test_equal_i(result1[1], 35);
        test_equal_i(result1[2], 0);
        free(result1);
    }

    // ================== TEST 2: Eine 4x2 Matrix (Rechteckig + negative Zahlen) ==================
    int row2 = 4;
    int col2 = 2;
    int matrix2[4][2] = {
        {3, 4},
        {-2, 5},
        {-3, -3},
        {0, 7}};

    int *result2 = rowMult((int *)matrix2, row2, col2);

    if (result2 != NULL)
    {
        test_equal_i(result2[0], 12);
        test_equal_i(result2[1], -10);
        test_equal_i(result2[2], 9);
        test_equal_i(result2[3], 0);
        free(result2);
    }

    // ================== TEST 3: Eine 1x5 Matrix (Nur eine Zeile) ==================
    int row3 = 1;
    int col3 = 5;
    int matrix3[1][5] = {
        {2, 1, 3, 2, 2}};

    int *result3 = rowMult((int *)matrix3, row3, col3);

    if (result3 != NULL)
    {
        test_equal_i(result3[0], 24);
        free(result3);
    }

    return 0;
}
