#include <stdio.h>
#include <stdlib.h>
void count();
void putBeg(int value);
void put(int pos, int value);
void putEnd(int value);

void delFirst();
void delLast();
void delPos();
void display();
void inputValue(int *add);
void inputPos(int *add);

void reverse();
void sort();

typedef struct node {
    int value;
   struct node* next;
}node;
void swap(node*, node*);
node* head = NULL;

void putBeg(int value)
{
    node* ptr = (node*) malloc((sizeof(node)));
    ptr -> value = value;
    ptr->next = head;
    head = ptr;
}
void put(int pos, int value)
{
    if(pos==0)
    {
        putBeg(value);
        return;
    }
    int i  = 0;
    node* tmp = head;
    while(i != pos-1 && tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    if(i != pos-1 || tmp == NULL)
    {
        printf("\n\nERROR\nEnter Correct Index\n\n");
        return;
    }
    node* ptr = (node*) malloc((sizeof(node)));
    ptr -> value = value;
    ptr->next = (tmp->next);
    tmp->next = ptr;
}

void putEnd(int value) {

    node* ptr = (node*) malloc((sizeof(node)));
    ptr -> value = value;
    ptr->next=NULL;
    if(head==NULL)
    {
        head=ptr;
        return;
    }
    node* tmp = head;
    for(;tmp->next!=NULL;tmp=tmp->next);
    tmp->next=ptr;
}
void display() {

    if(head==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    printf("\n\nLinked List Contains : ");
    for(node* tmp=head;tmp!=NULL;tmp = tmp->next)
        printf("%d  ", tmp->value);
    printf("\n\n");
}

void delFirst() {
    if(head==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    node *tmp = head->next;
    free(head);
    head = tmp;
}

void delLast() {
    if(head==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    if(head->next == NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    node* tmp = head;
    for(;(tmp->next)->next!=NULL;tmp=tmp->next);
    free(tmp->next);
    tmp->next = NULL;
}

void delPos(int pos){

    if(head==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    if(pos==0)
    {
        delFirst();
        return;
    }
    int i  = 0;
    node* tmp = head;
    while(i!=pos-1&&tmp!=NULL)
    {
        i++;
        tmp = tmp->next;
    }
    if(i!=pos-1||tmp->next==NULL)
    {
        printf("\n\nERROR\nEnter Correct Index\n\n");
        return;
    }
    node* tmp1 = tmp->next;
    tmp->next = (tmp->next)->next;
    free(tmp1);
}
void reverse() {
    if(head == NULL) {
        printf("\n\nLinked List is empty\n\n");
        return;
    }
    if(head -> next == NULL){
        printf("\n\nReversed\n\n");
        return;
    }
    node* tmp;
    node* current = head -> next;
    node* previous = head;
    while(current != NULL) {
        tmp = current->next;
        current -> next = previous;
        previous = current;
        current = tmp;
    }
    head->next=NULL;
    head = previous;
    printf("\n\nReversed\n\n");
    return;
}
void sort() 
{ 
    int flag, i; 
    node *ptr1; 
    node *ptr2 = NULL; 
  
    if (head == NULL) 
        return; 
  
    do
    { 
        flag = 0; 
        ptr1 = head; 
  
        while (ptr1->next != ptr2) 
        { 
            if (ptr1->value > ptr1->next->value) 
            {  
                swap(ptr1, ptr1->next); 
                flag = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        ptr2 = ptr1; 
    } 
    while (flag); 
    printf("\n\nSorted\n\n");
} 
void swap(node *a, node *b) 
{ 
    int temp = a->value; 
    a->value = b->value; 
    b->value = temp; 
} 
void inputValue(int *add)
{
    printf("Enter element to be added : ");
    scanf("%d", add);
}
void inputPos(int* add){
    printf("Enter index : ");
    scanf("%d", add);
}

void main() {
    int choice = 0, input, pos;
    while(1)
    {
        count();
        printf("Enter 1 to add at beginning\n");
        printf("Enter 2 to add at end\n");
        printf("Enter 3 to add at given index\n");
        printf("Enter 4 to delete first element\n");
        printf("Enter 5 to delete last element\n");
        printf("Enter 6 to delete element at given index\n");
        printf("Enter 7 to display\n");
        printf("Enter 8 to reverse\n");
        printf("Enter 9 to sort\n");
        printf("Enter -1 to quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice==-1)
            break;
        switch(choice)
        {
            case 1:
                inputValue(&input);
                putBeg(input);
                break;
            case 2:
                inputValue(&input);
                putEnd(input);
                break;
            case 3:
                inputValue(&input);
                inputPos(&pos);
                put(pos, input);
                break;
            case 4:
                delFirst();
                break;
            case 5:
                delLast();
                break;
            case 6:
                inputPos(&pos);
                delPos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                reverse();
                break;
            case 9:
                sort();
                break;
            default:
                printf("\n\nIncorrect Choice\n\n");
                break;
        }
    }
    printf("\n\n-----DONE-----\n\n");
}
void count() {
    int i = 0;
    node* tmp=head;
    while(tmp!=NULL) {
        i++;
        tmp = tmp->next;
    }
    printf("\n\nCount : %d\n\n", i);
}