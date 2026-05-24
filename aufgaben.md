* [ ] Aufgabe 1 middleListIndex
  * Schreiben Sie eine Funktion, die das mittlere Element einer verketteten Listen zurückgibt. Wenn die Liste eine gerade Anzahl an Elementen hat soll eine Null zurückgegeben werden.
* [ ] Aufgabe 2 minMaxWeights
  * Aus einer Liste Hanteln(mit Gewicht und Preis) so auswählen, dass man ein bestimmtes Gewicht möglichst günstig erreicht. Die beste kombinaton sollte man durch "einfach alles ausprobieren" herausfinden.
* [ ] Aufgabe 3 GroupItems
  * Implementieren Sie die Funktion List \*groupItems(List \*list). Diese bekommt eine Liste von Elementen übergeben und gruppiert diese Elemente nach Kategorie. Die Ele- mente der übergebenen Liste sind vom Typ (Zeiger auf) Item. Die zurückzugebende Liste soll Elemente vom Typ (Zeiger auf) Group enthalten. Jede Gruppe enthält den Namen der Kategorie, die Summe der Item-Werte der Kategorie, das Maximum der Item-Werte der Kate- gorie sowie die Anzahl der Items in der Kategorie. Implementieren Sie Group \*findGroup(List \*list, char \*category) als Hilfs- funktion. Diese gibt die erste Gruppe zurück, deren Kategorie mit der übergebenen Kategorie übereinstimmt. Gibt NULL zurück, falls keine solche Gruppe existiert. Die übergebene Liste enthält Elemente vom Typ (Zeiger auf) Group.
* [ ] Aufgabe 4 copyNElementsFromList
  * Liste mit Zahlen gegeben, die ersten n Elemente in neuer Liste speichern und zurückgeben, falls n > Listengröße komplette Liste zurückgeben, falls n = 0 nichts zurückgeben 
    * Eingabe: Liste (1,2,3), n = 2
    * Rückgabe (1,2)
* [ ] Aufgabe 5 treeToList
  * Aus einem Tree eine Liste machen
* [ ] Aufgabe 6 intersperseList
  * implementieren Sie eine Funktion "IntList\* intersperse(IntList \*list, int x)", die zwischen die Listenelemente den übergebenen Wert x einfügt. Die Funktion soll dabei die Ursprungsliste nicht verändern, sondern einen Zeiger auf die veränderte Kopie zurückgeben. Diese muss dynamisch allokiert werden - [ ] dies konnte man mit einer node()-Funktion bspw. erledigen, die bereits in der .c-Datei vorhanden war. Beispiele (Testfälle waren wieder vorgegeben): intersperse([1, 2, 3], -3) = [1, -3, 2, -3, 3] intersperse([1, 2], -3) = [1, -3, 2] Wichtigster Testfall war noch: intersperse([ ], -3) = [ ] Je nach Implementation konnte vorkommen, dass ihr im letzten Testfall statt "[ ]" "[0]" erhaltet. Lösung: man musste für den Fall, dass die übergebene IntList NULL ist, NULL zurückgeben.
* [ ] Aufgabe 7 nodeDifference
  * Differenz zwischen dem minimalen und dem maximalem Element in einer Liste von INT berechnen
* [ ] Aufgabe 8 mergeLists
  * Zwei Listen mergen
* [ ] Aufgabe 9 intToList
  * Int wird vorgeben und jede Dezimalziffer soll in eine Liste übergeben werden und dann umwandeln in eine Liste mit Binärdarstellung
* [ ] Aufgabe 10 listFunctions ham
  * Aus einer Liste letztes Element, list Size herausfinden, pop,push und Append List funktion schreiben
* [ ] Aufgabe 11 int_to_binary_list
  * Bsp: 65 -> [1, 0, 0, 0, 0, 0, 1], 0 -> [0], 10 -> [1, 0, 1, 0]
* [ ] Aufgabe 12 
  * Schreibe eine Funktion int count_element(int element, List \*list), die zählt, wie oft die Zahl element in der gegebenen Liste vorkommt
  * Schreibe eine Funktion List short_list(List \*list), die eine neue Liste erstellt, in die solange alle Zahlen aus list übernommen werden, bis entweder list zu ende ist oder die Zahl bereits zweimal in der neuen Liste vorhanden ist (dann wird sie einfach übersprungen).

    Beispiele: 

    \[1, 3, 4, 3, 3, 2, 1, 1\] -> \[1, 3, 4, 3, 2, 1\]

    \[5, 8, 2, 3, 2, 5, 8, 5, 2, 3, 8\] -> \[5, 8, 2, 3, 2, 5, 8, 3\]