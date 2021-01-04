#include<stdio.h>
#include<string.h>

#include<stdlib.h>
struct node
{
	char usn[30];
	char name[30];
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;


void insert_end()
{
	struct node *new_node,*temp;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the usn\n");
	 scanf("%s",new_node->usn);
	 printf("Enter the name\n");
	 scanf("%s",new_node->name);
	new_node->next=NULL;
	new_node->prev=NULL;
	if(head==NULL)
	{
		head=new_node;
	}
	else
	{
		 temp=head;
		 while(temp->next!=NULL)
		 temp=temp->next;
		 temp->next=new_node;
		 new_node->prev=temp;

	}

}

void del()
{
	struct node *temp;
	char ele[30];
    if(head==NULL)
    {
        printf("Empty List \n");
        return;
    }
	printf("Enter the usn to be deleted\n");
	scanf("%s",ele);
	temp=head;
	while(strcmp(temp->usn,ele)!=0)
	{
		temp=temp->next;
		if(temp==NULL)
		{
		 printf("Element is not in the list\n");
		 break;
		}
	 }
	 if(temp==head)
	 {
		 head=head->next;
	 }
	 else if(temp->next==NULL)
	 {
			temp=temp->prev;
			temp->next=NULL;
	 }

	 else
	 {
		 temp->prev->next=temp->next;
		 temp->next->prev=temp->prev;
	 }
}
void display()
{
	 struct node *temp;
	 temp=head;
	 while(temp!=NULL)
	 {
	 	printf("--------------------\n");
		 printf("usn:%s\n",temp->usn);
		 printf("name:%s\n",temp->name);
		 printf("--------------------\n");
		 temp=temp->next;
	 }
	 printf("\n");
}


int main()
{
	int choice;
	
	 while(1)
	 {
			printf(" 1. Insert  \n");
		
			
			printf(" 2. Delete \n");
			printf(" 3. Display\n");
			printf(" 4. Exit\n");
			printf("Enter your choice\n");
			scanf("%d",&choice);
			switch(choice)
			{
				 
				 case 1: insert_end();break;
			
				 case 2: del(); break;
				 case 3: display(); break;
				 case 4: exit(0);
			}
	 }
}