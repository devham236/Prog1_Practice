#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void inser_end(Node **root, int v)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->value = v;
    new_node->next = NULL;

    // if (*root == NULL)
    // {
    //     *root = new_node;
    //     return;
    // }

    Node *curr = *root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

int main(void)
{
    Node *root = malloc(sizeof(Node));
    root->value = 15;
    root->next = NULL;

    inser_end(&root, 28);
    inser_end(&root, 2);
    inser_end(&root, -33);

    for (Node *curr = root; curr != NULL; curr = curr->next)
    {
        printf("%d \n", curr->value);
    }

    return 0;
}
