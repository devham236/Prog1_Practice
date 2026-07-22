#include <stdio.h>

int findMaximum(const int arr[], int size)
{
    int max = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int findMinimum(const int arr[], int size)
{
    int min = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

int vergleiche(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

double findMedian(int arr[], int size)
{

    qsort(arr, size, sizeof(int), vergleiche);

    int index = (size - 1) / 2;

    return arr[index];
}

int main(void)
{
    // Testdaten
    int daten[] = {7, 2, 9, 1, 5, 4, 8};
    int anzahl = sizeof(daten) / sizeof(daten[0]);

    // Funktionsaufrufe
    int max = findMaximum(daten, anzahl);
    int min = findMinimum(daten, anzahl);
    double median = findMedian(daten, anzahl);

    // Ausgabe zur Ueberpruefung
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Median:  %.2f\n", median);

    return 0;
}