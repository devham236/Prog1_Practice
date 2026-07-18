// 4. Aufgabe: (Original-Formulierung war sehr kompliziert und abschreckend,
// sinngemäß war folgendes gefordert): implementieren Sie die Funktion
// "void derive_polynoms(int *polynoms, int *results)", die Ableitung der Polynome
// aus dem polynoms-Array in das results-Array schreibt.

// Hört sich erstmal schrecklich kompliziert an - schauen wir uns an, was die
// eigentlich von uns wollen: ein Array { 1, 2, 3 } bspw. soll "übersetzt" bedeuten
// f(x) = 1 * x⁰ + 2 * x¹ + 3 * x². Leitet man das ab, erhält man
// f'(x) = 2 * x⁰ + 6 * x¹. Das results-Array soll also für results[0] die 2
// enthalten und für results[1] die 6. Angegeben waren noch weitere Testfälle, die
// allesamt aber ähnlich waren. Kann mich an keinen "komplizierten" Testfall
// erinnern. Im Endeffekt war das ein 3-Zeiler - wenn man sich von der
// zunächst kompliziert erscheinenden Aufgabenstellung nicht abschrecken ließ.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "base.h"

void derivePolynoms(int length, int *polynoms, int *result)
{
    for (int i = 1; i < length; i++)
    {
        result[i - 1] = polynoms[i] * i;
    }
}

int main()
{
    // ================== TEST 1 ==================
    int polynoms1[3] = {1, 2, 3};
    int result1[2] = {0, 0};

    // Wir übergeben die '3', weil das Eingabe-Array 3 Elemente hat
    derivePolynoms(3, polynoms1, result1);

    test_equal_i(result1[0], 2);
    test_equal_i(result1[1], 6);

    // ================== TEST 2 (Ein längeres Polynom zum Testen!) ==================
    // f(x) = 2*x^0 + 3*x^1 + 4*x^2 + 5*x^3  (Länge 4)
    // Ableitung f'(x) = 3 + 8x + 15x^2     ->  {3, 8, 15} (Länge 3)
    int polynoms2[4] = {2, 3, 4, 5};
    int result2[3] = {0, 0, 0};

    // Wir übergeben die '4'
    derivePolynoms(4, polynoms2, result2);

    test_equal_i(result2[0], 3);
    test_equal_i(result2[1], 8);
    test_equal_i(result2[2], 15);

    return 0;
}