// make lowest_version && ./lowest_version

#include "base.h"

typedef struct Node {
    int version;
    int value;
    struct Node* next;
} Node;


Node* node(int version, int value, Node* next) {
    Node* n = xmalloc(sizeof(Node));
    n->version = version;
    n->value = value;
    n->next = next;
    return n;
}


// Beispiel-Testfunktion
bool test(int version) {
    return version % 2 == 0;
}


/*
Aufgabe:

Finde den value des Knotens mit der kleinsten Version,
für den test(version) == true gilt.
*/

int value_of_lowest_valid_version(Node* list) {

    int min_version = 0;
    int result = 0;
    bool found = false;

    for (Node* current = list; current != NULL; current = current->next) {

        if (test(current->version)) {

            if (!found || current->version < min_version) {

                min_version = current->version;
                result = current->value;
                found = true;
            }
        }
    }

    return result;
}


void test_lowest_version(void) {

    Node* list =
        node(5,10,
        node(2,7,
        node(8,4,
        node(3,20,NULL))));

    test_equal_i(value_of_lowest_valid_version(list), 7);

}


int main(void) {

    test_lowest_version();

    return 0;
}