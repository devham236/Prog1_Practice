#include <stdio.h>
#include <stdbool.h>

// Struct fuer den Array-Iterator
typedef struct {
    const int *array; // Zeiger auf das zu iterierende Array
    int size;         // Gesamtanzahl der Elemente
    int index;        // Aktuelle Position
} ArrayIterator;

// Erstellt und initialisiert einen neuen Iterator
ArrayIterator create_iterator(const int arr[], int size) {
    ArrayIterator it;
    it.array = arr;
    it.size = size;
    it.index = 0;
    return it;
}

// Prueft, ob noch weitere Elemente vorhanden sind
bool iterator_has_next(const ArrayIterator *it) {
    // TODO: Implementiere hier deine Logik
    if(it->index < it->size){
        return true;
    }
    else{
        return false;
    }
}

// Gibt das aktuelle Element zurück und rueckt den Iterator vor
int iterator_next(ArrayIterator *it) {
    // TODO: Implementiere hier deine Logik
    int val = it->array[it->index];
    it->index++;
    return val;

}

int main(void) {
    int daten[] = {10, 20, 30, 40, 50};
    int anzahl = sizeof(daten) / sizeof(daten[0]);

    // Iterator erstellen
    ArrayIterator it = create_iterator(daten, anzahl);

    // Iteration durchführen
    printf("Array-Elemente via Iterator:\n");
    while (iterator_has_next(&it)) {
        int wert = iterator_next(&it);
        printf("%d ", wert);
    }
    printf("\n");

    return 0;
}