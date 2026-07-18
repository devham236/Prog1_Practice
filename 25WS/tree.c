#include <stdlib.h>
#include <stdio.h>
/*
execute: gcc -o tree tree.c && ./tree

aufgabe: tree repräsentiert einen baum mit numerischen werte. die funktion sum_at_level soll die summe der werte
in ebene n eines binärbaums berechnen. die wurzel des baums befindet sich auf ebene 0. die kinder der wurzel auf ebene 1, deren kinder auf ebene 2, usw. 
implementieren sie die funktion int sum_at_level(tree* t, int target_level, int current_level), die den baum, die gesuchte ebene und die aktuelle ebene übergeben bekommt.

eigenes template, in der klausur etwas anders, aber eigene implementierung sollte gleich sein
*/
typedef struct tree_t
{
    struct tree_t *left;
    struct tree_t *right;
    int value;
} tree;

tree*  make_tree(tree*left, tree*right, int value){
    tree * t= malloc(sizeof(tree));
    t->left=left;
    t->right=right;
    t->value=value;
    return t;
}
void free_tree(tree*t){
    if(t==NULL){return;}
    free_tree(t->left);
    free_tree(t->right);
    free(t);
}

int sum_at_level(tree *t, int target_level,int current_level){
    //TODO
}


void test(int a, int b, int line){
    if(a==b){
        printf("test in zeile: %i erfolgreich\n", line);
        return;
    }
    printf("test in zeile: %i fehlgeschlagen %i != erwartet: %i\n", line,a,b);
}
void tests(){
    tree *t1=make_tree(make_tree(NULL,NULL,2),make_tree(NULL,NULL,5),3);
    tree* t2=make_tree(t1,make_tree(make_tree(NULL,NULL,7),make_tree(NULL,NULL,8),3),9);
    tree* t3=make_tree(t1,t2,0);
    tree* t4=make_tree(make_tree(t1,t2,7),t2,5);
    tree* t5=make_tree(t4,t3,0);
    test(sum_at_level(t1,0,0),3,__LINE__);
    test(sum_at_level(t1,1,0),7,__LINE__);
    test(sum_at_level(t2,0,0),9,__LINE__);
    test(sum_at_level(t2,1,0),6,__LINE__);
    test(sum_at_level(t2,2,0),22,__LINE__);
    test(sum_at_level(t3,0,0),0,__LINE__);
    test(sum_at_level(t3,3,0),22,__LINE__);
    test(sum_at_level(t4,3,0),35,__LINE__);
    test(sum_at_level(t5,4,0),57,__LINE__);
    free_tree(t2);
    free(t3);
    free(t4->left);
    free(t4);
    free(t5);
    
}
int main(int argc, char *argv[]) {
    tests();
}