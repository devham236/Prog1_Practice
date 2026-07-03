// Überprüft, ob Knotensumme im Baum == 0, also alle Knoten haben 0 als value oder komplett leer.

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

bool isTreeZero(IntTree *node)
{
    if (node == NULL)
    {
        return true;
    }

    if (node->data != 0)
    {
        return false;
    }

    if (node->left != NULL && node->left->data != 0)
    {
        return false;
    }
    if (node->right != NULL && node->right->data != 0)
    {
        return false;
    }

    return isTreeZero(node->left) && isTreeZero(node->right);
}

int main()
{

    printf("--- Starte Tests für Baum-Summe == 0 ---\n\n");

    // ---------------------------------------------------------
    // Test 1: Komplett leerer Baum (NULL)
    // Erwartung: Soll laut Aufgabe als "wahr" (1) gewertet werden.
    // ---------------------------------------------------------
    {
        IntTree *root = NULL;
        int expected = 1;              // true
        int result = isTreeZero(root); // Nenne deine Funktion wie du magst
        printf("Test 1 (Leerer Baum): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    // ---------------------------------------------------------
    // Test 2: Ein einzelner Knoten mit Wert 0
    // Erwartung: true (1)
    // ---------------------------------------------------------
    {
        int arr[] = {0};
        IntTree *root = createRandomTree(arr, NULL, 0, 1);
        int expected = 1;
        int result = isTreeZero(root);
        printf("Test 2 (Ein Knoten, Wert 0): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    // ---------------------------------------------------------
    // Test 3: Ein einzelner Knoten mit Wert ungleich 0
    // Erwartung: false (0)
    // ---------------------------------------------------------
    {
        int arr[] = {5};
        IntTree *root = createRandomTree(arr, NULL, 0, 1);
        int expected = 0;
        int result = isTreeZero(root);
        printf("Test 3 (Ein Knoten, Wert 5): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    // ---------------------------------------------------------
    // Test 4: Größerer Baum, bei dem ALLE Knoten 0 sind
    // Erwartung: true (1)
    // ---------------------------------------------------------
    {
        // Struktur:
        //       0
        //      / \
        //     0   0
        int arr[] = {0, 0, 0};
        IntTree *root = createRandomTree(arr, NULL, 0, 3);
        int expected = 1;
        int result = isTreeZero(root);
        printf("Test 4 (Alle Knoten 0): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    // ---------------------------------------------------------
    // Test 5: FALLE! Die mathematische Summe ist 0, aber Knoten sind ungleich 0
    // Struktur: Wurzel = 5, Kinder = -5 und 0.
    // Mathematische Summe: 5 + (-5) + 0 = 0.
    // Erwartung: false (0), weil eben NICHT alle Knoten den Wert 0 haben!
    // ---------------------------------------------------------
    {
        // Struktur:
        //       5
        //      / \
        //    -5   0
        int arr[] = {5, -5, 0};
        IntTree *root = createRandomTree(arr, NULL, 0, 3);
        int expected = 0;
        int result = isTreeZero(root);
        printf("Test 5 (Mathematische Summe 0, Werte nicht): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    // ---------------------------------------------------------
    // Test 6: Großer Baum, eine versteckte 1 ganz tief unten
    // Erwartung: false (0)
    // ---------------------------------------------------------
    {
        // Struktur:
        //         0
        //        / \
        //       0   0
        //      / \
        //     0   1  <-- Hier versteckt sich der Störenfried!
        int arr[] = {0, 0, 0, 0, 1};
        IntTree *root = createRandomTree(arr, NULL, 0, 5);
        int expected = 0;
        int result = isTreeZero(root);
        printf("Test 6 (Versteckte 1 in Ebene 3): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    printf("\n--- Tests beendet ---\n");
    return 0;
}