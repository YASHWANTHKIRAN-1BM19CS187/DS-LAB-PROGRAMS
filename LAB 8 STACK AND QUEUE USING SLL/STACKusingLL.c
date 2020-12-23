#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *link;
}node;

node *top=NULL;



void push()
{
 node *temp;
temp=(node *)malloc(sizeof(node));
 printf("Enter node element\n");
 scanf("%d",&temp->data);
 temp->link=NULL;

 if(top==NULL)
 {
     top=temp;
 }
 else
 {
  temp->link=top;
  top=temp;
 }
}

void pop()
{

node *temp;

if(top==NULL)
{
  printf("Stack is empty\n");
}

else
{
 temp=top;
top=temp->link;
temp->link=NULL;
free(temp);
}

}


void display()
{
 node *temp=top;
 if(temp==NULL)
 {
   printf("Stack is empty\n");
 }
 else
 {
   while(temp!=NULL)
   {
     printf("%d\n",temp->data);
     temp=temp->link;
   }
 }
}

int main()
{
 
 int op,len;
 while(1)
{ printf("Enter the operation\n1.Push\n");
  printf("2.Pop\n3.Display\n4.Exit\n");
  scanf("%d",&op);
  switch (op)
  {
  case 1:push();
    break;
  case 2: pop();
    break;
  case 3: display();
    break;
  case 4: exit(0);
     break;
  default: printf("No such operation\n");
  }
 }
return 0;
}