#include <limits.h>
#include "base.h"

typedef struct {
     int value;
     struct IntList* next;
} IntList;

//ergänze Konstrukurfunktion und so (was in der KLausur alles gegeben)
//Aufgabe war eine Funktion zu schreiben, die die Differenz zwischen dem Maximum und dem Minium einer Liste berechnet.

int diff_max_min(IntList* list) {
    if (list == NULL) return 0;
    int min = INT_MAX;
    int max = INT_MIN;
    IntList* current = list;
    while (current != NULL) {
        int val = current->value;
        if (val >= max) {
            max = val;
        }
        if (val < min) {
            min = val;
        }
        current = current->next;
    }
    return max - min;
}

void test_diff_max_min(void) {
    IntList elem5_0 = {2, NULL};
    IntList elem4_0 = {3, &elem5_0};
    IntList elem3_0 = {10, &elem4_0};
    IntList elem2_0 = {-1, &elem3_0};
    IntList elem1_0 = {6, &elem2_0};
    IntList list_0 = {1, &elem1_0};
    test_equal_i(diff_max_min(&list_0), 11);

    IntList list_1 = {5, NULL};
    test_equal_i(diff_max_min(&list_1), 0);

    test_equal_i(diff_max_min(NULL), 0);
}

int main(void) {
    test_diff_max_min();
    return 0;
}
