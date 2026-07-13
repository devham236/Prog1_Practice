// Summe aller rechten Nachfolger
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

int rightSum(IntTree *node)
{
    if(node == NULL){
        return 0;
    }

    int sum = 0;

    if(node->right != NULL){
        sum = node->right->data;
    }

    return rightSum(node->right) + rightSum(node->left) + sum;
}

int main()
{
    printf("--- Test 1: Leerer Baum ---\n");
    IntTree *root1 = NULL;
    int res1 = rightSum(root1);
    printf("Erwartet: 0, Erhalten: %d -> %s\n\n", res1, res1 == 0 ? "PASSED" : "FAILED");

    printf("--- Test 2: Nur ein Wurzelknoten ---\n");
    int arr2[] = {5};
    IntTree *root2 = createRandomTree(arr2, NULL, 0, 1);
    int res2 = rightSum(root2);
    printf("Erwartet: 0, Erhalten: %d -> %s\n\n", res2, res2 == 0 ? "PASSED" : "FAILED");

    printf("--- Test 3: Komplexer Baum ---\n");
    /* 10
         /  \
        5    15
       / \   /
      3   7 12
      Erwartete rechte Nachfolger: 15 und 7. Summe = 22.
    */
    int arr3[] = {10, 5, 15, 3, 7, 12};
    IntTree *root3 = createRandomTree(arr3, NULL, 0, 6);
    int res3 = rightSum(root3);
    printf("Erwartet: 22, Erhalten: %d -> %s\n\n", res3, res3 == 22 ? "PASSED" : "FAILED");

    // Hier müsste theoretisch noch der Speicher freigegeben werden,
    // aber für die Testausgabe reicht das so.
    return 0;
}