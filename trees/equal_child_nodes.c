// Schreiben Sie eine Methode, die überprüft, ob ein Child-Node
// in einem Binärbaum den gleichen Wert hat wie sein Parent-Node.
// Sie dürfen dazu eine Hilfsmethode schreiben.
// (Restliche Funktionalität des Binärbaums und Tests gegeben)

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

bool checkParentChildRecursive(IntTree *node, int value)
{
    if (node == NULL)
    {
        return false;
    }

    if (node->left != NULL && node->left->data == node->data)
    {
        return true;
    }

    if (node->right != NULL && node->right->data == node->data)
    {
        return true;
    }

    return checkParentChildRecursive(node->left, node->data) || checkParentChildRecursive(node->right, node->data);
}

bool checkParentChild(IntTree *node)
{
    return checkParentChildRecursive(node, node->data);
}

int main()
{
    // ==========================================
    // TESTFALL 1: Negativ (Keine Übereinstimmung)
    // ==========================================
    // Wir bauen manuell einen kleinen Baum:
    //      5
    //     / \
    //    3   8
    IntTree *testTreeNeg = newNode(5);
    testTreeNeg->left = newNode(3);
    testTreeNeg->right = newNode(8);

    printf("Test 1 (Erwartet: false / 0) -> Ergebnis: %d\n", checkParentChild(testTreeNeg));

    // ==========================================
    // TESTFALL 2: Positiv (Ein Child hat gleichen Wert)
    // ==========================================
    // Wir bauen einen Baum, bei dem ein Child den Wert des Parents matcht:
    //      5
    //     / \
    //    5   8   <-- Linkes Child hat denselben Wert wie die Root (5)
    IntTree *testTreePos = newNode(5);
    testTreePos->left = newNode(5);
    testTreePos->right = newNode(8);

    printf("Test 2 (Erwartet: true / 1)  -> Ergebnis: %d\n", checkParentChild(testTreePos));

    // TESTFALL 3: Match tiefer im Baum (Rechter Teilbaum ist clean, links ist ein Match)
    //        5
    //       / \
    //      3   8
    //     /
    //    3  <-- Match hier! (Parent 3 hat Child 3)
    IntTree *testTreeDeep = newNode(5);
    testTreeDeep->left = newNode(3);
    testTreeDeep->right = newNode(8);
    testTreeDeep->left->left = newNode(3); // Match weiter unten!

    printf("Test 3 (Erwartet: true / 1)  -> Ergebnis: %d\n", checkParentChild(testTreeDeep));

    // CleanUp für Test 3 nicht vergessen:
    free(testTreeDeep->left->left);
    free(testTreeDeep->left);
    free(testTreeDeep->right);
    free(testTreeDeep);

    // ==========================================
    // CleanUp (Speicher freigeben)
    // ==========================================
    // (Optional, aber guter Stil: Hier müsste der Speicher der Bäume wieder mit free() freigegeben werden)
    free(testTreeNeg->left);
    free(testTreeNeg->right);
    free(testTreeNeg);

    free(testTreePos->left);
    free(testTreePos->right);
    free(testTreePos);

    return 0;
}