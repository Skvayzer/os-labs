#include <stdio.h>
#include <stdlib.h>

struct LinkedList{
    struct Node* start;
    int size;
};
struct Node{
    struct Node* next;
    int data;
};
void print_list(struct LinkedList* list){
    struct Node* current = list->start;
    do{
        if(current == NULL)
            break;
        printf("%d ", current->data);
        current = current->next;
    } while(current!=NULL);
    printf("\n");
}
void insert_node(int value, struct LinkedList* list, int index){
    if(index>list->size || index<=0){
        printf("There's no such index!\n");
        return;
    }
    struct Node* current = list->start;
    struct Node* previous = NULL;
    for(int i=0;i<index;i++){
        previous=current;
        current = current->next;
    }

    struct Node* inserted = (struct Node*) malloc(sizeof(struct Node));
    inserted->data=value;
    previous->next=inserted;
    inserted->next=current;
    list->size++;

}
void delete_node(struct LinkedList* list, int index){
    if(index>list->size-1 || index<0){
        printf("There's no such index!\n");
        return;
    }
    struct Node* current = list->start;
    struct Node* previous = NULL;
    for(int i=0;i<index;i++){
        previous=current;
        current = current->next;
    }

    struct Node* next = current->next;
    free(current);
    previous->next=next;
    list->size--;

}
int main(){
    int n;
    scanf("%d",&n);
    struct LinkedList list;
    list.size=n;
    struct Node* current = NULL;
    struct Node* previous = NULL;
    for(int i=0;i<n;i++){
        current = (struct Node*) malloc(sizeof(struct Node));
        if(previous!=NULL)
            previous->next=current;
        if(i==0)
            list.start=current;
        scanf("%d", &current->data);
        previous=current;
    }
    print_list(&list);
    insert_node(0,&list,n-2);
    print_list(&list);
    insert_node(10,&list,n+1);
    print_list(&list);
    delete_node(&list,2);
    print_list(&list);


    return 0;
}


