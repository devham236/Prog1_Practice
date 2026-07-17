// make flatten_array && ./flatten_array

#include "base.h"

typedef struct Node {
    int* values;
    int length;
    struct Node* next;
} Node;

typedef struct IntList {
    int value;
    struct IntList* next;
} IntList;


// erstellt neuen Listenknoten
IntList* list_node(int value, IntList* next) {
    IntList* n = xmalloc(sizeof(IntList));
    n->value = value;
    n->next = next;
    return n;
}


/*
Aufgabe:

Gegeben ist eine Liste von Structs.
Jedes Struct enthält ein Array und eine Länge.

Erzeuge eine neue Liste, die alle Werte
in der Reihenfolge ihres Auftretens enthält.
*/

IntList* flatten_array(Node* head) {

    IntList* result = NULL;
    IntList* tail = NULL;

    for (Node* current = head; current != NULL; current = current->next) {

        for (int i = 0; i < current->length; i++) {

            IntList* n = list_node(current->values[i], NULL);

            if (result == NULL) {
                result = n;
                tail = n;
            } else {
                tail->next = n;
                tail = n;
            }
        }
    }

    return result;
}


// ================== TESTS ==================

void test_flatten_array(void) {

    int a[] = {1,2,3};
    int b[] = {4,5};
    int c[] = {6};

    Node* list =
        (Node[]){
            {a,3,NULL},
            {b,2,NULL},
            {c,1,NULL}
        };

    list[0].next = &list[1];
    list[1].next = &list[2];

    IntList* r = flatten_array(&list[0]);

    test_equal_i(r->value, 1);
    test_equal_i(r->next->value, 2);
    test_equal_i(r->next->next->value, 3);
    test_equal_i(r->next->next->next->value, 4);
}


// ================== MAIN ==================

int main(void) {

    test_flatten_array();

    return 0;
}