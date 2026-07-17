# include "base.h"

typedef struct {
     int value;
     struct InstList* next;
}IntList;

//ergänze Konstrukurfunktion und so (was in der KLausur alles gegeben)

//Aufgabe war eine Funktion zu schreiben, die die Differenz zwischen dem Maximum und dem Minium einer Liste berechnet.

int diff_max_min(IntList* list) {
    return -1; //todo, implement
}

void test_diff_max_min(void) {
    // denk dir Testfälle aus (war in der Klausur gegeben)
}

int main(void) {
    test_diff_max_min();
    return 0;
}
