// Prüfe ob ein Binärbaum monoton ist(parent < children)

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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

void inOrderPrint(IntTree *head)
{
    if (head != NULL)
    {
        inOrderPrint(head->left);
        printf("%d,", head->data);
        inOrderPrint(head->right);
    }
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

bool monoTree(IntTree *node)
{
    if (node == NULL)
    {
        return true;
    }
    
    if(node->left != NULL && node->left->data < node->data){
        return false;
    }

    if(node->right != NULL && node->right->data < node->data){
        return false;
    }

    return monoTree(node->left) && monoTree(node->right);
}

int main()
{
    printf("Starte Tests für monoTree...\n\n");

    // Testfall 1: Leerer Baum (NULL) -> Sollte true sein
    {
        bool result = monoTree(NULL);
        printf("Test 1 (Leerer Baum): %s (Erwartet: TRUE)\n", result ? "PASSED" : "FAILED");
    }

    // Testfall 2: Einzelner Knoten -> Sollte true sein
    {
        IntTree *root = newNode(10);
        bool result = monoTree(root);
        printf("Test 2 (Einzelner Knoten): %s (Erwartet: TRUE)\n", result ? "PASSED" : "FAILED");
        free(root);
    }

    // Testfall 3: Gültiger monotoner Baum (Wurzel < Kinder)
    //       10
    //      /  \
    //    15    20
    {
        int elements[] = {10, 15, 20};
        IntTree *root = createRandomTree(elements, NULL, 0, 3);
        bool result = monoTree(root);
        printf("Test 3 (Gültiger Baum): %s (Erwartet: TRUE)\n", result ? "PASSED" : "FAILED");
        // HINWEIS: Eine freeTree-Funktion wäre hier gut, um Speicherlecks zu vermeiden.
    }

    // Testfall 4: Ungültiger Baum (Linkes Kind ist kleiner als Parent)
    //       10
    //      /  \
    //     5    20
    {
        int elements[] = {10, 5, 20};
        IntTree *root = createRandomTree(elements, NULL, 0, 3);
        bool result = monoTree(root);
        printf("Test 4 (Ungültig - Linkes Kind kleiner): %s (Erwartet: FALSE)\n", !result ? "PASSED" : "FAILED");
    }

    // Testfall 5: Ungültiger Baum (Rechtes Kind ist kleiner als Parent)
    //       10
    //      /  \
    //    15    8
    {
        int elements[] = {10, 15, 8};
        IntTree *root = createRandomTree(elements, NULL, 0, 3);
        bool result = monoTree(root);
        printf("Test 5 (Ungültig - Rechtes Kind kleiner): %s (Erwartet: FALSE)\n", !result ? "PASSED" : "FAILED");
    }

    // Testfall 6: Tieferer, gültiger monotoner Baum
    //         5
    //       /   \
    //     10     12
    //    /  \    /
    //  15   20  13
    {
        // Array-Repräsentation für createRandomTree:
        // Index: 0   1   2   3   4   5
        // Wert:  5, 10, 12, 15, 20, 13
        int elements[] = {5, 10, 12, 15, 20, 13};
        IntTree *root = createRandomTree(elements, NULL, 0, 6);
        bool result = monoTree(root);
        printf("Test 6 (Tiefer gültiger Baum): %s (Erwartet: TRUE)\n", result ? "PASSED" : "FAILED");
    }

    // Testfall 7: Tieferer Baum, der erst weiter unten ungültig wird
    //         5
    //       /   \
    //     10     12
    //    /  \    /
    //  15    8  13   <- Die 8 verletzt die Bedingung (10 < 8 ist falsch)
    {
        int elements[] = {5, 10, 12, 15, 8, 13};
        IntTree *root = createRandomTree(elements, NULL, 0, 6);
        bool result = monoTree(root);
        printf("Test 7 (Erst tiefere Ebene ungültig): %s (Erwartet: FALSE)\n", !result ? "PASSED" : "FAILED");
    }

    return 0;
}