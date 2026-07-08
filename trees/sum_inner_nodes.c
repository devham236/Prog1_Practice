// Summe aller internen Knoten die Kindknoten haben

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

int innerSum(IntTree *node)
{
    
    if (node == NULL)
    {
        return 0;
    }

    int sum = 0;

    if (node->left != NULL || node->right != NULL)
    {
        sum = node->data;
    }

    return innerSum(node->left) + innerSum(node->right) + sum;
}

int main()
{
    printf("Starte Tests für innerSum...\n\n");

    // Testfall 1: Leerer Baum (NULL) -> Summe: 0
    {
        int result = innerSum(NULL);
        printf("Test 1 (Leerer Baum): %d (Erwartet: 0) -> %s\n",
               result, (result == 0) ? "PASSED" : "FAILED");
    }

    // Testfall 2: Nur ein einziger Knoten (Wurzel) -> Ist ein Blatt, also Summe: 0
    {
        IntTree *root = newNode(10);
        int result = innerSum(root);
        printf("Test 2 (Nur Wurzel/Blatt): %d (Erwartet: 0) -> %s\n",
               result, (result == 0) ? "PASSED" : "FAILED");
        free(root);
    }

    // Testfall 3: Wurzel mit einem linken Kind
    //       10 (interner Knoten)
    //      /
    //     5 (Blatt)
    // Erwartete Summe: 10
    {
        int elements[] = {10, 5};
        IntTree *root = createRandomTree(elements, NULL, 0, 2);
        int result = innerSum(root);
        printf("Test 3 (Wurzel mit einem Kind): %d (Erwartet: 10) -> %s\n",
               result, (result == 10) ? "PASSED" : "FAILED");
    }

    // Testfall 4: Wurzel mit zwei Kindern (Standard-Minibaum)
    //       10 (interner Knoten)
    //      /  \
    //     5    15 (beide Blätter)
    // Erwartete Summe: 10
    {
        int elements[] = {10, 5, 15};
        IntTree *root = createRandomTree(elements, NULL, 0, 3);
        int result = innerSum(root);
        printf("Test 4 (Wurzel mit zwei Kindern): %d (Erwartet: 10) -> %s\n",
               result, (result == 10) ? "PASSED" : "FAILED");
    }

    // Testfall 5: Größerer Baum mit mehreren internen Knoten
    //         4 (intern)
    //       /   \
    //     2      6 (beide intern)
    //    / \    /
    //   1   3  5  (alle drei Blätter)
    // Interne Knoten: 4, 2, 6 -> Summe: 4 + 2 + 6 = 12
    {
        int elements[] = {4, 2, 6, 1, 3, 5};
        IntTree *root = createRandomTree(elements, NULL, 0, 6);
        int result = innerSum(root);
        printf("Test 5 (Mehrere interne Knoten): %d (Erwartet: 12) -> %s\n",
               result, (result == 12) ? "PASSED" : "FAILED");
    }

    // Testfall 6: "Degenerierter" Baum (Lineare Kette / "Spaghetti-Baum")
    //       1 (intern)
    //        \
    //         2 (intern)
    //          \
    //           3 (Blatt)
    // Interne Knoten: 1, 2 -> Summe: 1 + 2 = 3
    {
        // Da createRandomTree ein vollständiger Baum-Array-Parser ist,
        // bauen wir diesen speziellen Testbaum schnell von Hand:
        IntTree *root = newNode(1);
        root->right = newNode(2);
        root->right->right = newNode(3);

        int result = innerSum(root);
        printf("Test 6 (Lineare Kette): %d (Erwartet: 3) -> %s\n",
               result, (result == 3) ? "PASSED" : "FAILED");

        free(root->right->right);
        free(root->right);
        free(root);
    }

    return 0;
}