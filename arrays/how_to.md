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

### Array wird "flach" übergeben und spaltenweise/zeilenweise etwas berechnen
- Wenn du das array "flach" übergeben bekommst, also einen Pointer auf den Anfang der Kette, dann kannst du nicht mehr a[j][i] verwenden, a liegt als eine lange Kette vor, wie halt 2D Arrays gespeichert werden.
- Beim Beispiel oben wird ja in den tests einfach a übergeben, hier ist es aber (int*) a, a wird also zu einem int pointer getypecasted.
- Um hier jetzt Spaltenweise etwas zu berechnen musst du a[j*cols+i]
- Bei zeilenweiser Berechnung gehst du erstmal durch rows und dann durch cols und vertauschst einfach j und i, also a[i*cols+j]
- Merk dir einfach, spaltenweise = J.Cole + i und zeilenweise einfach erstmal durch rows und dann durch cols und dann a[i*cols+j]

```c
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
}
```