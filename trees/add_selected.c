/*
make add_selected && ./add_selected
*/

#include "base.h"

// Represents a binary tree with integer values.
typedef struct Tree
{
    int value;
    struct Tree *left;
    struct Tree *right;
} Tree;

// Creates a new binary tree node.
Tree *new_tree(Tree *left, int value, Tree *right)
{
    Tree *n = xcalloc(1, sizeof(Tree));
    n->left = left;
    n->value = value;
    n->right = right;
    return n;
}

// <purpose statement>
int add_selected(Tree *t, String path, int sum)
{
    if (t == NULL || path[0] == '\0')
    {
        return sum;
    }

    if (path[0] == '+')
    {
        return add_selected(t, path + 1, sum + t->value);
    }
    else if (path[0] == 'l')
    {
        return add_selected(t->left, path + 1, sum);
    }
    else if (path[0] == 'r')
    {
        return add_selected(t->right, path + 1, sum);
    }

    return add_selected(t, path + 1, sum);
}

// Creates a leaf node.
Tree *leaf(int value)
{
    return new_tree(NULL, value, NULL);
}

// Creates a node.
Tree *node(Tree *left, int value, Tree *right)
{
    return new_tree(left, value, right);
}

void test(void)
{
    Tree *t;
    //    1
    //  2   5
    // 7 3 4 6
    t = node(node(leaf(7), 2, leaf(3)), 1, node(leaf(4), 5, leaf(6)));
    test_equal_i(add_selected(t, "+", 0), 1);
    test_equal_i(add_selected(t, "++", 0), 2);
    test_equal_i(add_selected(t, "rrrr+", 0), 0);
    test_equal_i(add_selected(t, "+r", 0), 1);
    test_equal_i(add_selected(t, "r+", 0), 5);
    test_equal_i(add_selected(t, "+r+", 0), 1 + 5);
    test_equal_i(add_selected(t, "+r+r", 0), 1 + 5);
    test_equal_i(add_selected(t, "+r+r+", 0), 1 + 5 + 6);
    test_equal_i(add_selected(t, "rl+", 0), 4);
    test_equal_i(add_selected(t, "+lr+", 0), 1 + 3);
    test_equal_i(add_selected(t, "lr", 0), 0);
}

int main(void)
{
    test();
    return 0;
}