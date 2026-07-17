// make largest_odd_version && ./largest_odd_version

#include "base.h"

typedef struct Node {
    int value;
    int version;
    struct Node* next;
} Node;


// erstellt neuen Knoten
Node* node(int value, int version, Node* next) {
    Node* n = xmalloc(sizeof(Node));
    n->value = value;
    n->version = version;
    n->next = next;
    return n;
}


/*
Aufgabe:

Finde den Knoten mit der größten ungeraden Version,
die <= max_version ist.

Schreibe dessen value in result.
Gib die Version zurück.

Falls kein passender Knoten existiert → return -1
*/

int largest_odd_version(Node* head, int max_version, int* result) {

    int best_version = -1;

    for (Node* current = head; current != NULL; current = current->next) {

        if (current->version % 2 == 1 && current->version <= max_version) {

            if (current->version > best_version) {

                best_version = current->version;
                *result = current->value;
            }
        }
    }

    return best_version;
}


// ================== TESTS ==================

void test_largest_odd_version(void) {

    int r;

    Node* list =
        node(10,2,
        node(7,5,
        node(4,3,
        node(8,9,NULL))));

    test_equal_i(largest_odd_version(list, 6, &r), 5);
    test_equal_i(r, 7);

    test_equal_i(largest_odd_version(list, 4, &r), 3);
    test_equal_i(r, 4);

    test_equal_i(largest_odd_version(list, 1, &r), -1);

    test_equal_i(largest_odd_version(NULL, 10, &r), -1);
}


// ================== MAIN ==================

int main(void) {

    test_largest_odd_version();

    return 0;
}