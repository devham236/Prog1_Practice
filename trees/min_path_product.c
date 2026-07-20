// make min_path_product && ./min_path_product

#include "base.h"

typedef struct Tree
{
    int value;
    struct Tree *left;
    struct Tree *right;
} Tree;

// erstellt einen Knoten
Tree *node(Tree *left, int value, Tree *right)
{
    Tree *t = xmalloc(sizeof(Tree));
    t->value = value;
    t->left = left;
    t->right = right;
    return t;
}

// erstellt ein Blatt
Tree *leaf(int value)
{
    return node(NULL, value, NULL);
}

// Hilfsfunktion: Gibt den kleineren von zwei Werten zurück
int min(int a, int b)
{
    return (a < b) ? a : b;
}

/*
Aufgabe:

Berechne das kleinste Pfadprodukt von der Wurzel zu einem Blatt.
(Multipliziere alle Knotenwerte entlang des Pfades).

Ein leerer Baum liefert 0.

Hinweis: Wir gehen hier nur von positiven Zahlen im Baum aus (> 0).
*/

int min_path_product(Tree *t)
{

    if (t == NULL)
    {
        return 0;
    }

    if (t->left == NULL && t->right == NULL)
    {
        return t->value;
    }

    int left_tree = min_path_product(t->left);
    int right_tree = min_path_product(t->right);

    if (t->left != NULL && t->right != NULL)
    {
        return min(left_tree, right_tree) * t->value;
    }

    if (t->left != NULL && t->right == NULL)
    {
        return left_tree * t->value;
    }

    return right_tree * t->value;
}

// ================== TESTS ==================

void test_min_path_product(void)
{

    /*
            2
          /   \
         4     3
        / \   / \
       5   1 6   2
    */

    // Pfade & Produkte:
    // 2 * 4 * 5 = 40
    // 2 * 4 * 1 = 8  <-- Das Minimum!
    // 2 * 3 * 6 = 36
    // 2 * 3 * 2 = 12

    Tree *t1 =
        node(
            node(leaf(5), 4, leaf(1)),
            2,
            node(leaf(6), 3, leaf(2)));

    test_equal_i(min_path_product(t1), 8);

    /*
            3
           /
          4
         /
        2
    */
    // Produkt: 3 * 4 * 2 = 24

    Tree *t2 =
        node(
            node(
                leaf(2),
                4,
                NULL),
            3,
            NULL);

    test_equal_i(min_path_product(t2), 24);

    // Einzelnes Blatt
    Tree *t3 = leaf(10);
    test_equal_i(min_path_product(t3), 10);

    // Leerer Baum
    test_equal_i(min_path_product(NULL), 0);
}

// ================== MAIN ==================

int main(void)
{

    test_min_path_product();

    return 0;
}