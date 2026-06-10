# Lists !

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

- Um durch eine linked list mit einem **while loop** zu iterieren, brauchst du erstmal einen Start, eine Abbruchbedingung und etwas was bei jedem Schritt passieren soll
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

- Mit einem for loop durch eine linked list zu iterieren funktioniert eigentlich sehr ähnlich, du nimmst deinen Start, die Abbruchbedindung und den Iterationschritt und legst alles in die Klammer

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

    for (Node *curr = &root; curr != NULL; curr = curr->next)
    {
        printf("%d \n", curr->value);
    }

    free(root.next->next);
    free(root.next);
    return 0;
}
```

### Hinzufügen

- Um an das Ende einer linked list hinzuzufügen müssen wir grob gesagt ans Ende der linked list iterieren und dann sagen, das die näcshte Node einen Wert hat.
- Zunächst erstellen wir unsere root in der main Funktion. In diesem Fall ist root ein Pointer der auf die erste Node im Speicher zeigt.

```c
Node *root = malloc(sizeof(Node));
root->value = 15;
root->next = NULL;
```

- Du willst in der insert_end Funktion den originalen root Pointer verändern, deswegen brauchst du die Speicheradresse des Pointers selbst und musst diesen übergeben, deswegen musst bei deinen Funktionsaufrufen &root verwenden

```c
inser_end(&root, 28);
inser_end(&root, 2);
inser_end(&root, -33);
```

- Wenn du eine Funktion void insert_end(Node\* root) hättest und diese mit insert_end(root) aufrufst, kopiert C die Adresse. Wenn du dann in der Funktion dann root = ... änderst, wird nur die lokale Kopie geändert, das root in der main bleibt unberührt.

- Als erstes ersstellen wir die neue Node in der insert_end FUnktion, die das Ende der linked list sein soll, deswegen ist next = NULL
- Unser Start ist der root Pointer, wir gehen dann bis ans Ende und sagen dann nach dem while loop das next der aktuellen Node gleich unser neue erstellte Node ist.
- Der auskommentierte if block ist dazu da um zu überprüfen ob die Liste nur ein NULL enthält also eine leere Liste, wenn das der Fall ist, ist unsere new_node der neue Start.

```c
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
```
