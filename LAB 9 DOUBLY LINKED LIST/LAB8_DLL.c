#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
}node;

node* head = NULL;

void add_beg(int value) {
    node* ptr = (node*) malloc(sizeof(node));
    ptr->value = value;
    ptr->prev = NULL;
    ptr->next = head;
    if(head!=NULL) {
        head->prev = ptr;
    }
    head = ptr;
}

void add_key(int value, int key) {
    node* tmp = head;
    while(tmp!=NULL) {
        if(tmp->value == key) {
            break;
        }
        tmp = tmp->next;
    }
    if(tmp==NULL) {
        printf("\nNo Match\n");
        return;
    }
    if(tmp==head) {
        add_beg(value);
        return;
    }  
    node* ptr = (node*) malloc(sizeof(node));
    ptr->value = value;  
    ptr->prev = tmp->prev;
    ptr->next = tmp;
    (tmp->prev)->next = ptr;
    tmp->prev = ptr;
}
void del_key(int key) {
    if(head == NULL) {
        printf("\nList is Empty\n");
        return;
    }
    node* tmp = head;
    while(tmp != NULL) {
        if(tmp -> value == key) {
            break;
        }
        tmp = tmp->next;
    }
    if(tmp==head) {
        if(head->next==NULL)
        {
            free(head);
            head=NULL;
            return;
        }
        head = head->next;
        free(head->prev);
        head->prev = NULL;
        return;
    }
    if(tmp==NULL) {
        printf("\nNo Match\n");
        return;
    }
    if(tmp->next==NULL) {
        tmp->prev->next = NULL;
        free(tmp);
        return;
    }
    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;
    free(tmp);
}
void display() {
    if(head == NULL) {
        printf("\nList is Empty\n");
        return;
    }
    node* tmp = head;
    printf("\nLinked list contains : ");
    while(tmp!= NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}
void main() {
    int choice, value, key;
    while(1) {
        printf("Enter 1 to add at beginning\n");
        printf("Enter 2 to add at left of a node\n");
        printf("Enter 3 to delete a node\n");
        printf("Enter 4 to display\n");
        printf("Enter -1 to quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice==-1)
            break;
        switch(choice) {
            case 1:
                printf("\nEnter value to insert : ");
                scanf("%d", &value);
                add_beg(value);
                break;
            case 2:
                printf("\nEnter value to insert : ");
                scanf("%d", &value);
                printf("\nEnter value of key node : ");
                scanf("%d", &key);
                add_key(value, key);
                break;
            case 3:
                printf("\nEnter value of node to be deleted : ");
                scanf("%d", &key);
                del_key(key);
                break;
            case 4:
                display();
                break;
            default:
                printf("\n\nWrong Input\n\n");
        }
    }
    printf("\n\n-----DONE-----\n\n");
}