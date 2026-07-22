/*
Compile: make dot_product
Run: ./dot_product
*/

#include <stdio.h>

double dot_product(const double a[], const double b[], int length) {

    double result = 0;

    for(int i = 0; i < length; i++){
        result += (a[i] * b[i]);
    }

    return result;
}

int main(void) {
    // Testdaten
    double v1[] = {1.0, 2.0, 3.0};
    double v2[] = {4.0, 5.0, 6.0};
    int len = sizeof(v1) / sizeof(v1[0]);

    // Funktionsaufruf
    double result = dot_product(v1, v2, len);

    // Ausgabe zur Überprüfung
    printf("Skalarprodukt: %g\n", result);

    return 0;
}