// make max_path_sum && ./max_path_sum

#include "base.h"

typedef struct Tree {
    int value;
    struct Tree* left;
    struct Tree* right;
} Tree;


// erstellt einen Knoten
Tree* node(Tree* left, int value, Tree* right) {
    Tree* t = xmalloc(sizeof(Tree));
    t->value = value;
    t->left = left;
    t->right = right;
    return t;
}


// erstellt ein Blatt
Tree* leaf(int value) {
    return node(NULL, value, NULL);
}


/*
Aufgabe:

Berechne die größte Pfadsumme von der Wurzel
zu einem Blatt.

Ein leerer Baum liefert 0.
*/

int max_path_sum(Tree* t) {

    if (t == NULL) {
        return 0;
    }

    // Blatt
    if (t->left == NULL && t->right == NULL) {
        return t->value;
    }

    // nur rechter Teilbaum vorhanden
    if (t->left == NULL) {
        return t->value + max_path_sum(t->right);
    }

    // nur linker Teilbaum vorhanden
    if (t->right == NULL) {
        return t->value + max_path_sum(t->left);
    }

    int left_sum = max_path_sum(t->left);
    int right_sum = max_path_sum(t->right);

    if (left_sum > right_sum) {
        return t->value + left_sum;
    } else {
        return t->value + right_sum;
    }
}


// ================== TESTS ==================

void test_max_path_sum(void) {

    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    Tree* t1 =
        node(
            node(leaf(4), 2, leaf(5)),
            1,
            node(leaf(6), 3, leaf(7))
        );

    test_equal_i(max_path_sum(t1), 11);


    /*
            5
           /
          2
         /
        1
    */

    Tree* t2 =
        node(
            node(
                leaf(1),
                2,
                NULL
            ),
            5,
            NULL
        );

    test_equal_i(max_path_sum(t2), 8);


    Tree* t3 = leaf(10);
    test_equal_i(max_path_sum(t3), 10);

    test_equal_i(max_path_sum(NULL), 0);
}


// ================== MAIN ==================

int main(void) {

    test_max_path_sum();

    return 0;
}