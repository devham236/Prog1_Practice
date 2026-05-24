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

### Iterieren

- Um durch eine linked list mit einem while loop zu iterieren, brauchst du erstmal einen Start, eine Abbruchbedingung und etwas was bei jedem Schritt passieren soll
- Du willst ja bei der root anfangen und dann jede Node durchgehen, also musst du in jedem Schritt dein curr auf die näcshte Node setzen, bis die aktuelle Node NULL ist.
- Du musst beim Start &root verwenden weil curr ein Node Pointer ist, das heißt curr kann nur eine Speicheradresse enthalten.
  Und weil root die ganze Struktur ist musst du das & verwenden, damit du die Speicheradresse von root bekommst

```c
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

    // Start
    Node *curr = &root;

    // Abbruchbedingung
    while (curr != NULL)
    {
        printf("%d \n", curr->value);

        // Iterationsschritt
        curr = curr->next;
    }

    free(root.next->next);
    free(root.next);
    return 0;
}
```
