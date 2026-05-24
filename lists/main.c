#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

int main(void)
{
    // root element
    Node root;
    root.value = 5;

    // zweites element
    root.next = malloc(sizeof(Node));
    root.next->value = 10;

    // drittes element
    root.next->next = malloc(sizeof(Node));
    root.next->next->value = 4;

    // letztes element
    root.next->next->next = NULL;

    for (Node *curr = &root; curr != NULL; curr = curr->next)
    {
        printf("%d \n", curr->value);
    }

    free(root.next->next);
    free(root.next);
    return 0;
}
