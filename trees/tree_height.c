// Berechne die Tiefe eines Baumes.
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

int treeHeight(IntTree *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int height = 1;

    if (node->left != NULL || node->right != NULL)
    {
        height++;
    }

    int left = treeHeight(node->left);
    int right = treeHeight(node->right);

    if (left > right)
    {
        return left + 1;
    }

    if (left < right)
    {
        return right + 1;
    }

    return height;
}

int main()
{
    printf("--- Test 1: Leerer Baum ---\n");
    IntTree *root1 = NULL;
    int res1 = treeHeight(root1);
    printf("Erwartet: 0, Erhalten: %d -> %s\n\n", res1, res1 == 0 ? "PASSED" : "FAILED");

    printf("--- Test 2: Nur Wurzelknoten ---\n");
    int arr2[] = {42};
    IntTree *root2 = createRandomTree(arr2, NULL, 0, 1);
    int res2 = treeHeight(root2);
    printf("Erwartet: 1, Erhalten: %d -> %s\n\n", res2, res2 == 1 ? "PASSED" : "FAILED");

    printf("--- Test 3: Mehrstufiger Baum ---\n");
    /* 1
       /   \
      2     3
     /
    4
    Tiefe/Höhe dieses Baumes ist 3 Ebenen.
    */
    int arr3[] = {1, 2, 3, 4};
    IntTree *root3 = createRandomTree(arr3, NULL, 0, 4);
    int res3 = treeHeight(root3);
    printf("Erwartet: 3, Erhalten: %d -> %s\n\n", res3, res3 == 3 ? "PASSED" : "FAILED");

    return 0;
}