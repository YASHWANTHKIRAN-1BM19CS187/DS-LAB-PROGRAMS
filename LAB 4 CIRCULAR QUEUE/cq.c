#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
int a[SIZE],t;
int front=-1;
int rear=-1;

int IsEmpty()
{
 if(rear==-1 && front==-1)
    return 1;
  else
    return 0;
}


int IsFull()
{
 if(front==(rear+1)%SIZE)
 return 1;
 else
return 0;   
}


void Enqueue(int x)
{
  if(IsFull())
   printf("The queue is full\n");
  else if(IsEmpty())
  {
    front=0;
    rear=0;
    a[rear]=x;
   }
   else
   {
       rear=(rear+1)%SIZE;
       a[rear]=x;
    }
}

int Dequeue()
{    int x;
    if(IsEmpty())
    printf("The queue is empty.\n");
    else if(front==rear)
    {
        x=a[front];
        front=-1;
        rear=-1;
         printf("The element was removed\n");
    }
    else
    {
        x=a[front];
        front=(front+1)%SIZE;
         printf("The element was removed\n");
    }
    return x;
}


void display()

{ 
    if (front == -1) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 
    printf("\nElements in Circular Queue are:\n"); 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            printf("%d\n",a[i]); 
    } 
    else
    { 
        for (int i = front; i < SIZE; i++) 
            printf("%d\n", a[i]); 
  
        for (int i = 0; i <= rear; i++) 
            printf("%d\n", a[i]); 
    } 
} 



int main()
{
 int n,a; 
 while(1)
  {
 printf("Enter the operation.\n1-Insert\n2-Delete\n3-Display\n4-Exit\n");
 scanf("%d",&n);
 switch(n)
 {
   case 1: printf("Enter the element\n");
             scanf("%d",&a);
             Enqueue(a);
              break;
              
  case 2 :   Dequeue();
           
             break;
  case 3:  display();
           break;
   case 4: exit(0);
    default :   printf("There is no such operation\n");
 }
 }
 return 0;
}