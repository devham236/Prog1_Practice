// run make is_yellow_blue && ./is_yellow_blue
/*
    Methode soll true ausgeben wenn root bsp. blau und kinder gelb sind und false wenn root bsp. blau und eins der Kinder blau ist.
    Also root und Kind dürfen nicht die selbe Farbe haben
*/
#include "base.h"

typedef enum
{
    YELLOW,
    BLUE
} Colour;

typedef struct Tree
{
    Colour colour;
    struct Tree *left;
    struct Tree *right;
} Tree;

Tree *newNode(Colour colour)
{
    Tree *temp = malloc(sizeof(Tree));
    temp->colour = colour;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bool is_yellow_blue(Tree *t)
{
    if (t == NULL)
    {
        return true;
    }

    if (t->left != NULL && t->left->colour == t->colour)
    {
        return false;
    }

    if (t->right != NULL && t->right->colour == t->colour)
    {
        return false;
    }

    return is_yellow_blue(t->left) && is_yellow_blue(t->right);
}

void test_is_yellow_blue(void)
{
    // ---------------------------------------------------------
    // Test case 1: Leerer Baum
    //
    //       NULL
    // ---------------------------------------------------------
    Tree *t1 = NULL;
    test_equal_b(is_yellow_blue(t1), true);

    // ---------------------------------------------------------
    // Test case 2: Balancierter Baum mit gültigen Farben
    //
    //              (BLUE)
    //             /      \
    //        (YELLOW)  (YELLOW)
    // ---------------------------------------------------------
    Tree *t2 = newNode(BLUE);
    t2->left = newNode(YELLOW);
    t2->right = newNode(YELLOW);
    test_equal_b(is_yellow_blue(t2), true);

    // ---------------------------------------------------------
    // Test case 3: Ungültig (linkes Kind hat dieselbe Farbe wie die Wurzel)
    //
    //              (BLUE)
    //             /      \
    //        (BLUE)    (YELLOW)   <-- Fehler: BLUE hat BLUE als Kind
    // ---------------------------------------------------------
    Tree *t3 = newNode(BLUE);
    t3->left = newNode(BLUE);
    t3->right = newNode(YELLOW);
    test_equal_b(is_yellow_blue(t3), false);

    // ---------------------------------------------------------
    // Test case 4: Tieferer Baum (perfekt alternierend)
    //
    //               (BLUE)
    //             /        \
    //       (YELLOW)      (YELLOW)
    //        /    \        /    \
    //   (BLUE)   (BLUE) (BLUE)  (BLUE)
    // ---------------------------------------------------------
    Tree *t4 = newNode(BLUE);
    t4->left = newNode(YELLOW);
    t4->right = newNode(YELLOW);
    t4->left->left = newNode(BLUE);
    t4->left->right = newNode(BLUE);
    t4->right->left = newNode(BLUE);
    t4->right->right = newNode(BLUE);
    test_equal_b(is_yellow_blue(t4), true);

    // ---------------------------------------------------------
    // Test case 5: Baum mit nur einem Kind (gültig)
    //
    //              (BLUE)
    //             /
    //        (YELLOW)
    // ---------------------------------------------------------
    Tree *t5 = newNode(BLUE);
    t5->left = newNode(YELLOW);
    test_equal_b(is_yellow_blue(t5), true);
}

int main(void)
{
    test_is_yellow_blue();
    report_memory_leaks(true);
    return 0;
}