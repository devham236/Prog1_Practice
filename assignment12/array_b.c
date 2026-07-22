#include <stdio.h>
#include "base.h"

double berechneMittelwert(double arr[], int size)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum / size;
}

int main(void)
{
    // Testdaten
    double daten[] = {1.5, 2.5, 3.0, 4.0, 5.0};
    int anzahl = sizeof(daten) / sizeof(daten[0]);

    // Funktionsaufruf
    double ergebnis = berechneMittelwert(daten, anzahl);

    // Ausgabe zur Überprüfung
    printf("Berechneter Mittelwert: %.2f\n", ergebnis);

    return 0;
}