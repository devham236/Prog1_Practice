# Lists

### Aufbau

- Zuerst musst brauchst du einen struct für die einzelnen Nodes. Jede Node hat einen int Wert und einen Node pointer auf das näcshte Element

```c
typedef struct Node
{
    int value;
    struct Node *next;
} Node;
```

- Dann brauchst du eine "root" Node, also den Anfang deiner linked List. Da jede Node auf eine andere zeigt, musst du Speicher dafür anlegen. Also allokierst du für "next" die Größe deines structs.

```c
Node root;
root.value = 5;
root.next = malloc(sizeof(Node));
```

- Man könnte für die Node nach root, nochmal eine Node Instanz anlegen und dieser einen Wert und den Node pointer geben.
- Das macht aber wenig Sinn für linked lists, weil man ja so wie in einer array jede Stelle einzeln belegt und das wollen wir nicht
- Also greift man auf die nächste Node von der root Node zu und gibt dieser dann mit root.next->next einen Wert.
- Du musst -> verwenden weil next ein pointer ist.

```c
Node root;

root.value = 5;
root.next = malloc(sizeof(Node));

root.next->value = 10;
root.next->next = NULL;

printf("First element: %d \n", root.value);
printf("Second element: %d \n", root.next->value);
```
