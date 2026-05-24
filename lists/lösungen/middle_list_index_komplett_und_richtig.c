#include "base.h"

typedef struct Node{
    int value; 
    struct Node* next; 
} Node; 
//buisness as usual 
Node* create_node (int data){
    
    Node* new_node = xmalloc(sizeof(Node)); 
    new_node->value = data; 
    new_node->next = NULL; 
    

    return new_node; 
}
//nicht nötig aber gut um zu schauen ob deine Liste auch so aussieht wie du denkst 
void print_list(Node* head){
    Node* current = head; 
    while(current != NULL){
        printf("%d ->", current->value); 
        current = current->next; 
    }
    printf("NULL \n"); 
}

//erste essentielle Funktion zum lösen dieser Aufagbe, wenn du nicht weißt wie groß die Liste ist, kannst du ihren Mittelpunkt nicht bestimmen 
int get_list_size(Node* head){
    int count = 0; 
    while (head != NULL){
        head = head->next; 
        count++; 
    }
    return count; 
    
}

// das eigentliche todo 
 int get_middle_data(Node* head){
    //wenn die Liste gerade ist sollen wir eine 0 zurückgeben 
    if(get_list_size(head)% 2 == 0){
        return 0; 
    }else{
    //um den mittleren Wert zu kriegen teile ich die Größe durch zwei und runde auf, die Funktion ist in base.h bzw in math.h->base.h 
       int mid = ceil(get_list_size(head) / 2); 
        //einfach loopen bis man in der Mitte ist 
       for (int i = 0; i < mid; i++){
            head = head->next; 
       }
       return head->value; 
       
       

    }
 }


void test(){
    Node* head = create_node(1);

    Node* one = create_node(2); 
    head->next = one; 

    Node* two = create_node(3); 
    one->next = two; 

    test_equal_i(2, get_middle_data(head)); 

    // print_list(head);  
    // printf("%d \n", get_list_size(head)); 


    //und wieder mal die Knoten die man allokiert hat wieder freigeben, sonst gibts auf die finger 
    
    while (head != NULL){
        Node* tmp = head; 
        head = head->next; 
        free(tmp); 
    }
    
}


int main(){
    test();  
    report_memory_leaks(true); 
    return 0; 
}