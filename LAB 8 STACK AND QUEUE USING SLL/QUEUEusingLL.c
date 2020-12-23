#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *link;
}node;

node *root=NULL;

void enqueue()
{                        
   node *temp;
   temp=(node *)malloc(sizeof(node));
   
   printf("Enter the node element\n");
   scanf("%d",&temp->data);
    temp->link=NULL;
   if(root==NULL)
  {
  root=temp;                       
  }
  else 
  {
    node *p=root;
    while(p->link!=NULL)
   {
    p=p->link;
   }
   p->link=temp;
  }
}


void dequeue()
{
node *temp;

if(root==NULL)              
{
  printf("Queue is empty\n");
}

else
{
 temp=root;
root=temp->link;
temp->link=NULL;
free(temp);
}
}


void display()
{
 node *temp=root;
 if(temp==NULL)
 {
   printf("Queue is empty\n");
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
{ printf("Enter the operation\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
  scanf("%d",&op);
  switch (op)
  {
  case 1:enqueue();
    break;
  case 2: dequeue();
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