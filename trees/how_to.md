# How to

### Kinder vergleichen

- Wenn du zwei Kindknoten vergleichen musst, kannst du eigentlich immer nur ein if aufstellen nach deiner Abbruchbedingung und erstmal überprüfen ob beide nicht null sind und dann das was in der Aufgabe verlangt wird überprüfen:

```c
// Knoten auf der Konsole ausgeben, die sowohl über einen linken, als auch einen rechten
// Nachfolger verfügen und deren rechter Nachfolger größer ist als der linke Nachfolger.
// Nehmen Sie dabei an, dass der Baum unsortiert ist.

void printSorted(IntTree *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL && node->right != NULL && node->left->data < node->right->data)
    {
        printf("%d\n", node->data);
    }

    printSorted(node->left);
    printSorted(node->right);
}
```

### Beim Durchlauf etwas zählen

- Wenn du Eltern und Kinder vergleichen willst, berechne die Vorzeichenwechsel lokal pro Knoten und addiere die Ergebnisse der Teilbäume einfach auf, so brauchst du weder globale Variablen noch ein Zurücksetzen vor jedem Test.
- Deine Abbruchbedingung (NULL) gibt 0 zurück, und am Ende der Funktion gibst du den lokalen count zusammen mit den Aufrufen für den linken und rechten Teilbaum zurück (count + changingSign(node->left) + ...).

```c
static bool hasSignChange(int parent, int child)
{
    return (parent > 0 && child < 0) || (parent < 0 && child > 0);
}

int changingSign(IntTree *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int count = 0;

    // 1. Prüfen, ob das linke Kind existiert und ein anderes Vorzeichen hat
    if (node->left != NULL)
    {
        if (hasSignChange(node->data, node->left->data))
        {
            count++;
        }
    }

    // 2. Prüfen, ob das rechte Kind existiert und ein anderes Vorzeichen hat
    if (node->right != NULL)
    {
        if (hasSignChange(node->data, node->right->data))
        {
            count++;
        }
    }

    // 3. Ergebnisse aus dem linken und rechten Teilbaum aufaddieren
    return count + changingSign(node->left) + changingSign(node->right);
}
```

### Größte Pfadsumme (von Wurzel) berechnen

- Ein Pfad von der Wurzel aus geht immer bis zum letzten Knoten, der keine Kinder mehr hat
- Jeder Teilbaum guckt welches Kind größer ist, links oder rechts und wählt dann das größere aus und addiert den eigenen Knotenwert dazu und schiebt es weiter nach oben.

```c
int max_path_sum(Tree *t)
{
    if (t == NULL)
    {
        return 0;
    }

    if (t->left == NULL && t->right == NULL)
    {
        return t->value;
    }
    int left_tree = max_path_sum(t->left);
    int right_tree = max_path_sum(t->right);

    return max(left_tree, right_tree) + t->value;
}
```
