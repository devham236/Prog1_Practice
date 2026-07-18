# How to

- Wenn du ein Array int matrix[2][3] hast (2 Zeilen, 3 Spalten), sieht das im Speicher so aus:
[ Zeile 0, Spalte 0 ] [ Zeile 0, Spalte 1 ] [ Zeile 0, Spalte 2 ] [ Zeile 1, Spalte 0 ] [ Zeile 1, Spalte 1 ] ...

### Spaltenweise durchgehen und etwas berechnen
- Wenn du Spaltenweise durch die 2D array gehen willst, geht der äußere loop durch die Spalten und der innere durch die Zeilen und du greifst dann mit array[Zeile][Spalte] auf die einzelnen Einträge des arrays

```c
int *column_products(int rows, int cols, int a[rows][cols])
{
    int *result = xmalloc(cols * sizeof(int));

    for (int i = 0; i < cols; i++)
    {
        int col_result = 1;
        for (int j = 0; j < rows; j++)
        {
            col_result *= a[j][i];
        }

        result[i] = col_result;
    }
    printf("Länge der result array: %d\n", cols);

    return result;
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
```