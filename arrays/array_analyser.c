// a.) 2D-Matrix mit Buchstaben und - gegeben, Anzahl der gegebenen chars pro Spalte in 1D-Array speichern
// Eingabe 2D Array, a
// a - a a --> 3 <br>
// b - - - --> 0 --> [3,0] Rückgabe Array

#include <stdio.h>
#include <stdlib.h>
#include "base.h"

#define ROWS 3
#define COLS 2

int *countCharInArray(char inputArray[ROWS][COLS], char searchChar)
{
    int *result = malloc(COLS * sizeof(int));

    for (int i = 0; i < COLS; i++)
    {
        int count = 0;
        for (int j = 0; j < ROWS; j++)
        {
            char c = inputArray[j][i];

            if (c == searchChar)
            {
                count++;
            }
        }
        result[i] = count;
    }
    printf("\n");

    return result;
}

int main()
{
    // ================== TEST 1: Dein Original-Beispiel ==================
    char testArray1[ROWS][COLS] = {{'a', 'a'},
                                   {'a', '-'},
                                   {'-', 'b'}};

    int *result1 = countCharInArray(testArray1, 'a');
    test_equal_i(result1[0], 2);
    test_equal_i(result1[1], 1);

    // ================== TEST 2: Suche nach einem anderen Zeichen ('b') ==================
    int *result2 = countCharInArray(testArray1, 'b');
    test_equal_i(result2[0], 0); // In Spalte 0 gibt es kein 'b'
    test_equal_i(result2[1], 1); // In Spalte 1 gibt es ein 'b'

    // ================== TEST 3: Zeichen kommt gar nicht vor ==================
    char testArray2[ROWS][COLS] = {{'-', '-'},
                                   {'-', '-'},
                                   {'-', '-'}};

    int *result3 = countCharInArray(testArray2, 'x');
    test_equal_i(result3[0], 0);
    test_equal_i(result3[1], 0);

    // ================== TEST 4: Komplett voll mit dem gesuchten Zeichen ==================
    char testArray3[ROWS][COLS] = {{'z', 'z'},
                                   {'z', 'z'},
                                   {'z', 'z'}};

    int *result4 = countCharInArray(testArray3, 'z');
    test_equal_i(result4[0], 3); // Spalte 0 hat alle 3 Zeilen voll mit 'z'
    test_equal_i(result4[1], 3); // Spalte 1 hat alle 3 Zeilen voll mit 'z'

    return 0;
}