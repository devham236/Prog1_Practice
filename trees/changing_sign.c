// Schreiben Sie eine Methode, die zurückgibt, wie häufig es Child-
// und Parent-Nodes gibt, bei denen sich das Vorzeichen unterscheidet.

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

int count = 0;
int changingSignRecursive(IntTree *node, int value)
{

    if (node == NULL)
    {
        return 0;
    }

    if (node->left != NULL)
    {
        if ((node->left->data < 0 && value > 0) || (node->left->data > 0 && value < 0))
        {
            count++;
        }
    }

    if (node->right != NULL)
    {
        if ((node->right->data < 0 && value > 0) || (node->right->data > 0 && value < 0))
        {
            count++;
        }
    }

    changingSignRecursive(node->left, node->data);
    changingSignRecursive(node->right, node->data);

    return count;
}

int changingSign(IntTree *node)
{
    if (node != NULL)
    {
        count = 0;
        return changingSignRecursive(node, node->data);
    }

    return 0;
}

int main()
{
    printf("--- Starte Tests für changingSign ---\n\n");

    // ---------------------------------------------------------
    // Test 1: Leerer Baum
    // ---------------------------------------------------------
    {
        IntTree *root = NULL;
        int expected = 0;
        int result = changingSign(root);
        printf("Test 1 (Leerer Baum): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    // ---------------------------------------------------------
    // Test 2: Nur ein Knoten (Wurzel) ohne Kinder
    // ---------------------------------------------------------
    {
        int arr[] = {5};
        IntTree *root = createRandomTree(arr, NULL, 0, 1);
        int expected = 0;
        int result = changingSign(root);
        printf("Test 2 (Ein Knoten): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
        // Hier müsste man streng genommen den Baum wieder free'n,
        // für den Test-Scope lassen wir es kurz so.
    }

    // ---------------------------------------------------------
    // Test 3: Keine Vorzeichenwechsel (Alle positiv oder Null)
    // 0 wird hier als nicht-negativ gewertet (kein echter Wechsel zu +)
    // ---------------------------------------------------------
    {
        // Struktur:
        //       5
        //      / \
        //     10  0
        int arr[] = {5, 10, 0};
        IntTree *root = createRandomTree(arr, NULL, 0, 3);
        int expected = 0;
        int result = changingSign(root);
        printf("Test 3 (Kein Wechsel): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    // ---------------------------------------------------------
    // Test 4: Einfache Vorzeichenwechsel (Wurzel positiv, Kinder negativ)
    // ---------------------------------------------------------
    {
        // Struktur:
        //       5
        //      / \
        //    -3   -8
        // Wechsel: 5 -> -3 (ja), 5 -> -8 (ja) => 2 Wechsel
        int arr[] = {5, -3, -8};
        IntTree *root = createRandomTree(arr, NULL, 0, 3);
        int expected = 2;
        int result = changingSign(root);
        printf("Test 4 (Zwei Wechsel): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    // ---------------------------------------------------------
    // Test 5: Komplexerer Baum mit gemischten Vorzeichen
    // ---------------------------------------------------------
    {
        // Struktur:
        //         -10
        //        /    \
        //       5      -2
        //      / \     /
        //    -3   4   7
        //
        // Wechsel-Analyse:
        // -10 -> 5  (Wechsel 1)
        // -10 -> -2 (Nein)
        //   5 -> -3 (Wechsel 2)
        //   5 -> 4  (Nein)
        //  -2 -> 7  (Wechsel 3)
        // Gesamt = 3 Wechsel
        int arr[] = {-10, 5, -2, -3, 4, 7};
        IntTree *root = createRandomTree(arr, NULL, 0, 6);
        int expected = 3;
        int result = changingSign(root);
        printf("Test 5 (Komplexer Baum): Erwartet = %d, Erhalten = %d -> %s\n",
               expected, result, (result == expected) ? "PASS" : "FAIL");
    }

    printf("\n--- Tests beendet ---\n");
    return 0;
}