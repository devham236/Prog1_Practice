/*
make row_sum && ./row_sum
*/

#include "base.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// <purpose statement>
int *row_sum(int *a, int rows, int cols)
{
    int *result = malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        printf("\n");
        for (int j = 0; j < cols; j++)
        {
            printf("%d \n", a[i * cols + j]);
            sum += a[i * cols + j];
        }
        result[i] = sum;
    }

    return result;
}

// Hilfsfunktion zum Vergleichen und Ausgeben der Ergebnisse
void print_test_result(int test_nr, int *result, int *expected, int length)
{
    if (result == NULL)
    {
        printf("Test %d: FAIL (NULL-Pointer zurückgegeben)\n", test_nr);
        return;
    }

    bool pass = true;
    for (int i = 0; i < length; i++)
    {
        if (result[i] != expected[i])
        {
            pass = false;
            break;
        }
    }

    printf("Test %d: %s [", test_nr, pass ? "PASS" : "FAIL");
    for (int i = 0; i < length; i++)
    {
        printf("%d%s", result[i], (i < length - 1) ? ", " : "");
    }
    printf("]\n");
}

void run_tests(void)
{
    // Test 1: Gemischte Werte (positiv, negativ)
    {
        int a[3][3] = {
            {1, 2, 3},
            {-1, -2, -3},
            {3, 4, 5},
        };
        int expected[] = {6, -6, 12};
        int *margin = row_sum((int *)a, 3, 3);

        print_test_result(1, margin, expected, 3);

        if (margin != NULL)
            free(margin);
    }

    // Test 2: Rechteckige Matrix (2 Zeilen, 4 Spalten)
    {
        int a[2][4] = {
            {1, 1, 1, 1},
            {5, 10, 15, 20}};
        int expected[] = {4, 50};
        int *margin = row_sum((int *)a, 2, 4);

        print_test_result(2, margin, expected, 2);

        if (margin != NULL)
            free(margin);
    }

    // Test 3: Matrix mit Nullen
    {
        int a[1][3] = {
            {0, 0, 0}};
        int expected[] = {0};
        int *margin = row_sum((int *)a, 1, 3);

        print_test_result(3, margin, expected, 1);

        if (margin != NULL)
            free(margin);
    }
}

int main(void)
{
    printf("--- Starte Tests für row_sum ---\n\n");
    run_tests();
    printf("\n--- Tests beendet ---\n");
    return 0;
}