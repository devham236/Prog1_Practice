// Knoten auf der Konsole ausgeben, die sowohl über einen linken, als auch einen rechten
// Nachfolger verfügen und deren rechter Nachfolger größer ist als der linke Nachfolger.
// Nehmen Sie dabei an, dass der Baum unsortiert ist.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void printSorted(IntTree *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL && node->right != NULL && node->left->data < node->right->data)
    {
        printf("%d\n", node->data);
    }

    printSorted(node->left);
    printSorted(node->right);
}

int main()
{
    printf("--- TEST 1: Automatischer Baum aus Array ---\n");
    // Dieses Array baut folgenden Baum auf:
    //         10
    //        /  \
    //       5    15
    //      / \   /
    //     20  8 3
    //
    // Erwartung für printSorted:
    // - Knoten 10: Hat links(5) und rechts(15). Rechts > Links (15 > 5) -> GÜLTIG
    // - Knoten 5:  Hat links(20) und rechts(8). Rechts < Links (8 < 20) -> UNGÜLTIG
    // - Knoten 15: Hat nur links(3), rechts ist NULL -> UNGÜLTIG

    int treeEntries[] = {10, 5, 15, 20, 8, 3};
    int arrayLength = sizeof(treeEntries) / sizeof(treeEntries[0]);

    IntTree *root1 = NULL;
    root1 = createRandomTree(treeEntries, root1, 0, arrayLength);

    printf("In-Order Struktur des Baums: ");
    inOrderPrint(root1);
    printf("\n");

    printf("Aufruf deiner printSorted-Funktion (Sollte nur Knoten 10 finden):\n");
    printSorted(root1);

    printf("\n--- TEST 2: Manueller Extremtest (Grenzfälle) ---\n");
    // Wir bauen einen kleinen Baum händisch, um Edge Cases zu testen
    IntTree *root2 = newNode(100);
    root2->left = newNode(50);
    root2->right = newNode(50); // exakt gleich groß! Darf NICHT ausgegeben werden (> statt >=)

    // Ein tieferer Knoten, der gültig ist
    root2->left->left = newNode(10);
    root2->left->right = newNode(30); // 30 > 10 -> GÜLTIG

    printf("Aufruf deiner printSorted-Funktion (Sollte nur Knoten 50 finden):\n");
    printSorted(root2);

    // Speicher aufräumen wird hier vernachlässigt, da das Programm eh endet
    return 0;
}