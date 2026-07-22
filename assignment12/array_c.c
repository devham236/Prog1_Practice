#include <stdio.h>


void tauscheArray(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while(left < right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        left++;
        right--;
    }
}

int main(void) {
    // Testdaten
    int daten[] = {1, 2, 3, 4, 5};
    int anzahl = sizeof(daten) / sizeof(daten[0]);

    // Vorherige Werte ausgeben
    printf("Vorher:  ");
    for (int i = 0; i < anzahl; i++) {
        printf("%d ", daten[i]);
    }
    printf("\n");

    // Funktionsaufruf
    tauscheArray(daten, anzahl);

    // Nachherige Werte ausgeben
    printf("Nachher: ");
    for (int i = 0; i < anzahl; i++) {
        printf("%d ", daten[i]);
    }
    printf("\n");

    return 0;
}