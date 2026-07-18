#include "base.h"

int *col_prod(int *a, int rows, int cols)
{
    int *result = xmalloc(cols * sizeof(int));

    for (int i = 0; i < cols; i++)
    {
        int count = 1;
        for (int j = 0; j < rows; j++)
        {
            count *= a[(j * cols) + i];
        }
        result[i] = count;
    }

    return result;
}

void test(void)
{
    // ================== TEST 1: Dein Original-Beispiel (3x3 mit negativen Zahlen) ==================
    int a[3][3] = {
        {1, 2, 3},
        {-1, -2, -3},
        {3, 4, 5},
    };

    int *r1 = col_prod((int *)a, 3, 3);

    test_equal_i(r1[0], -3);
    test_equal_i(r1[1], -16);
    test_equal_i(r1[2], -45);

    free(r1);

    // ================== TEST 2: Eine 2x4 Matrix (Rechteckig + Multiplikation mit Null) ==================
    int b[2][4] = {
        {2, 5, 0, -4},
        {3, 4, 9, 2}};

    int *r2 = col_prod((int *)b, 2, 4);

    test_equal_i(r2[0], 6);
    test_equal_i(r2[1], 20);
    test_equal_i(r2[2], 0);
    test_equal_i(r2[3], -8);

    free(r2);

    // ================== TEST 3: Eine 4x1 Matrix (Nur eine einzige Spalte) ==================
    int c[4][1] = {
        {2},
        {3},
        {2},
        {5}};

    int *r3 = col_prod((int *)c, 4, 1);

    test_equal_i(r3[0], 60);

    free(r3);
}

int main(void)
{
    test();

    report_memory_leaks(true);
    return 0;
}