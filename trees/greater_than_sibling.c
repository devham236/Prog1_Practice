#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct IntTree
{
    int data;
    struct IntTree *left;
    struct IntTree *right;
} IntTree;

IntTree *newNode(int data)
{
    IntTree *temp = malloc(sizeof(IntTree));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

IntTree *createRandomTree(int treeEntries[], IntTree *node, int index, int arrayLength)
{
    IntTree *temp = NULL;
    if (index < arrayLength)
    {
        temp = newNode(treeEntries[index]);
        node = temp;
        node->left = createRandomTree(treeEntries, node->left, 2 * index + 1, arrayLength);
        node->right = createRandomTree(treeEntries, node->right, 2 * index + 2, arrayLength);
    }
    return temp;
}

int countGreaterThanSibling(IntTree *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int sum = 0;

    if (node->left != NULL && node->right != NULL)
    {
        if ((node->left->data > node->right->data) || (node->left->data < node->right->data))
        {
            sum++;
        }
    }

    return sum + countGreaterThanSibling(node->left) + countGreaterThanSibling(node->right);
}

int main()
{
    printf("--- Starte Tests für countGreaterThanSibling ---\n\n");

    // Test 1: Leerer Baum
    {
        IntTree *root = NULL;
        int expected = 0;
        int result = countGreaterThanSibling(root);
        printf("Test 1 (Leerer Baum): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    // Test 2: Nur ein Knoten (Keine Geschwister vorhanden)
    {
        int arr[] = {10};
        IntTree *root = createRandomTree(arr, NULL, 0, 1);
        int expected = 0;
        int result = countGreaterThanSibling(root);
        printf("Test 2 (Ein Knoten): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    // Test 3: Zwei Geschwister (Links = 8, Rechts = 3) -> Links ist größer (1 Treffer)
    {
        //       10
        //      /  \
        //     8    3
        int arr[] = {10, 8, 3};
        IntTree *root = createRandomTree(arr, NULL, 0, 3);
        int expected = 1;
        int result = countGreaterThanSibling(root);
        printf("Test 3 (Einfaches Geschwisterpaar): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    // Test 4: Gleiche Geschwister (Links = 5, Rechts = 5) -> Kein Knoten ist ECHT größer (0 Treffer)
    {
        //        10
        //       /  \
        //      5    5
        int arr[] = {10, 5, 5};
        IntTree *root = createRandomTree(arr, NULL, 0, 3);
        int expected = 0;
        int result = countGreaterThanSibling(root);
        printf("Test 4 (Gleiche Geschwister): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    // Test 5: Komplexer Baum
    {
        //         10
        //        /  \
        //       7    4      -> 7 > 4 (1 Treffer)
        //      / \  / \
        //     9  2  5  8    -> 9 > 2 (1 Treffer), 8 > 5 (1 Treffer)
        // Gesamt = 3 Treffer
        int arr[] = {10, 7, 4, 9, 2, 5, 8};
        IntTree *root = createRandomTree(arr, NULL, 0, 7);
        int expected = 3;
        int result = countGreaterThanSibling(root);
        printf("Test 5 (Komplexer Baum): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    printf("\n--- Tests beendet ---\n");
    return 0;
}