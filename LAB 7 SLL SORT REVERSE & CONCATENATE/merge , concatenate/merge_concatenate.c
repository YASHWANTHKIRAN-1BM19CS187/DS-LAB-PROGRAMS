#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int value;
    struct node* next;
}node;
void swap(node*, node*);
void add_beg(int, node**);
node* head3 = NULL;
node* head1 = NULL;
node* head2 = NULL;
node* head4 = NULL;
void del_beg(node** head) {
    if(*head==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    node *tmp = (*head)->next;
    free(*head);
    *head = tmp;
}
void del_end(node** head) {
    if(*head==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    if((*head)->next == NULL)
    {
        free(*head);
        *head=NULL;
        return;
    }
    node* tmp = *head;
    for(;(tmp->next)->next!=NULL;tmp=tmp->next);
    free(tmp->next);
    tmp->next = NULL;
}
void add_end(int value, node** head) {
    node* ptr = (node*) malloc(sizeof(node));
    ptr -> value = value;
    ptr->next=NULL;
    if(*head == NULL) {
        *head = ptr;
        return;
    }
    node* tmp = *head;
    while(tmp->next!=NULL) {
        tmp = tmp -> next;
    }
    tmp -> next = ptr;
}
void del_pos(int pos, node** head){

    if(*head==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    if(pos==0)
    {
        del_beg(head);
        return;
    }
    int i  = 0;
    node* tmp = *head;
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

void add_pos(int pos, int value, node** head)
{
    if(pos==0)
    {
        add_beg(value, head);
        return;
    }
    int i  = 0;
    node* tmp = *head;
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
void add_beg(int value, node** head) {
    node* ptr = (node*) malloc(sizeof(node));
    ptr -> value = value;
    ptr -> next = *head;
    *head = ptr;
}
void sort(node* start) 
{ 
    int flag, i; 
    node *ptr1; 
    node *ptr2 = NULL; 
  
    if (start == NULL) 
        return; 
    do
    { 
        flag = 0; 
        ptr1 = start; 
  
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
} 
void swap(node *a, node *b) 
{ 
    int temp = a->value; 
    a->value = b->value; 
    b->value = temp; 
} 


void merge(node* curr1, node* curr2, node* prev) {
    int flag1 = (curr1 == NULL);
    int flag3 = (curr2 == NULL);
    if(flag1 && flag3)
        return;
    node* newNode = (node*) malloc(sizeof(node));
    newNode -> next = NULL;
    if(prev==NULL) {
        sort(head1);
        sort(head2);
        head3 = newNode;
    }
    int flag2 = 1;
    if(!flag1 && !flag3){
        flag2 = curr1->value >= curr2->value;
    }
    else if(flag3)
        flag2 = 0;
    if(flag1 || flag2) {
        newNode->value = curr2->value;
        curr2 = curr2->next;
    }
    else {
        newNode->value = curr1->value;
        curr1 = curr1->next;
    }
    if(prev!=NULL)
        prev->next = newNode;
    prev = newNode;
    merge(curr1, curr2, prev); 
}
void concatenate() {
    if(head1==NULL&&head2==NULL)
        return;
    node* tmp = head1;
    if(head1!=NULL)
    {
        while(tmp->next!=NULL) {
            tmp = tmp->next;
        }
    }
    else {
        head1 = head2;
        return;
    }
    tmp->next = head2;
}
void display(node* head) {
    
    if(head == NULL) {
        printf("Empty\n");
        return;
    }
    node* tmp = head;
    
    while(tmp != NULL)
    {
        printf("%d  ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n\n");
}
void main() {
    int input, f, ch, pos;
    while(1) {
        printf("\nEnter 1 to add at beginning\n");
        printf("Enter 2 to add at end\n");
        printf("Enter 3 to add at any index\n");
        printf("Enter 4 to delete at beginning\n");
        printf("Enter 5 to delete at end\n");
        printf("Enter 6 to delete at any index\n");
        printf("Enter 7 to display\n");
        printf("Enter 8 to concatenate\n");
        printf("Enter -1 to merge\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        if(ch==-1 || ch==8)break;
        switch(ch) {
            case 1:
                printf("Enter 1 for first list 2 for second list : ");
                scanf("%d", &f);
                printf("Enter element to add : ");
                scanf("%d", &input);
                if(f==1)
                    add_beg(input,&head1);
                else if(f==2)
                    add_beg(input, &head2);
                else
                    printf("\n\nwrong input\n\n");
                break;
            case 2:
                printf("Enter 1 for first list 2 for second list : ");
                scanf("%d", &f);
                printf("Enter element to add : ");
                scanf("%d", &input);
                if(f==1)
                    add_end(input,&head1);
                else if(f==2)
                    add_end(input, &head2);
                else
                    printf("\n\nwrong input\n\n");
                break;
            case 3:
                printf("Enter 1 for first list 2 for second list : ");
                scanf("%d", &f);
                printf("Enter element to add : ");
                scanf("%d", &input);
                printf("Enter index : ");
                scanf("%d", &pos);
                if(f==1)
                    add_pos(pos, input,&head1);
                else if(f==2)
                    add_pos(pos, input, &head2);
                else
                    printf("\n\nwrong input\n\n");
                break;
            case 4:
                printf("Enter 1 for first list 2 for second list : ");
                scanf("%d", &f);
                if(f==1)
                    del_beg(&head1);
                else if(f==2)
                    del_beg(&head2);
                else
                    printf("\n\nwrong input\n\n");
                break;
            case 5:
                printf("Enter 1 for first list 2 for second list : ");
                scanf("%d", &f);
                if(f==1)
                    del_end(&head1);
                else if(f==2)
                    del_end(&head2);
                else
                    printf("\n\nwrong input\n\n");
                break;
            case 6:
                printf("Enter 1 for first list 2 for second list : ");
                scanf("%d", &f);
                printf("Enter index : ");
                scanf("%d", &pos);
                if(f==1)
                    del_pos(pos,&head1);
                else if(f==2)
                    del_pos(pos, &head2);
                else
                    printf("\n\nwrong input\n\n");
                break;
            case 7:
                printf("Enter 1 for first list 2 for second list : ");
                scanf("%d", &f);
                if(f==1){
                    printf("Linked List contains : ");
                    display(head1);
                }
                else if(f==2){
                    printf("Linked List contains : ");
                    display(head2);
                }
                else
                    printf("\n\nwrong input\n\n");
                break;
            default:
                printf("\n\nwrong input\n\n");
        }

    }
    if(ch==8) {
        concatenate();
        printf("\nConcatenated List ");
        display(head1);
        return;
    }
    merge(head1, head2, head3);
    printf("\nFirst List : ");
    display(head1);
    printf("\nSecond List : ");
    display(head2);
    printf("\nMerged Linked List : ");
    display(head3);
}