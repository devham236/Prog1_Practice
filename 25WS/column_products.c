// make column_products && ./column_products
#include "base.h"
/*
Aufgabe:

Gegeben ist ein zweidimensionales Array.

Berechne für jede Spalte das Produkt der Elemente
und gib ein Array mit diesen Produkten zurück.
*/

int *column_products(int rows, int cols, int a[rows][cols])
{
}

// ================== TESTS ==================

void test_column_products(void)
{

    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int *r = column_products(3, 3, a);

    test_equal_i(r[0], 28);
    test_equal_i(r[1], 80);
    test_equal_i(r[2], 162);

    int b[2][2] = {
        {2, 3},
        {4, 5}};

    r = column_products(2, 2, b);

    test_equal_i(r[0], 8);
    test_equal_i(r[1], 15);
}

// ================== MAIN ==================

int main(void)
{

    test_column_products();

    return 0;
}