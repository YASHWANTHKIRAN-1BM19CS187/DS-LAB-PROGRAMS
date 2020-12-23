#include <stdio.h>
#include <stdlib.h>
 
struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL, *temp = NULL, *t2, *t1;
 
void insert();
void inorder(struct btnode *t);
void create();
void search(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);
 
int flag = 1;
 
void main()
{
    int ch;
 
    while(1)
    {
        printf("\n**MENU**\n");
        printf("1 - Insert an element into tree\n");
        printf("2 - Inorder Traversal\n");
        printf("3 - Preorder Traversal\n");
        printf("4 - Postorder Traversal\n");
        printf("5 - Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:    
            insert();
            break;
        case 2:
            printf("\nINORDER TRAVERSAL:\n");
            inorder(root);
            break;
        case 3:  
            printf("\nPREORDER TRAVERSAL:\n");
            preorder(root);
            break;
        case 4:
            printf("\nPOSTORDER TRAVERSAL:\n");
            postorder(root);
            break;
        case 5:    
            exit(0);
        default :     
            printf("Invalid Choice!\n");
            break;    
        }
    }
}
 
void create()
{
    int data;
 
    printf("Enter data of node to be inserted : ");
    scanf("%d", &data);
    temp = (struct btnode*)malloc(1*sizeof(struct btnode));
    temp->value = data;
    temp->l = temp->r = NULL;
}
  

void insert()
{
    create();
    if (root == NULL) 
        root = temp;
    else    
        search(root);    
}
 
void search(struct btnode *t)
{
    if ((temp->value > t->value) && (t->r != NULL))      
        search(t->r);
    else if ((temp->value > t->value) && (t->r == NULL))
        t->r = temp;
    else if ((temp->value < t->value) && (t->l != NULL))    
        search(t->l);
    else if ((temp->value < t->value) && (t->l == NULL))
        t->l = temp;
} 
 

void inorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("No elements in the tree!\n");
        return;
    }
    if (t->l != NULL)    
        inorder(t->l);
    printf("%d -> ", t->value);
    if (t->r != NULL)    
        inorder(t->r);
}
 
 
void preorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("No elements in the tree!\n");
        return;
    }
    printf("%d -> ", t->value);
    if (t->l != NULL)    
        preorder(t->l);
    if (t->r != NULL)    
        preorder(t->r);
}
 
void postorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("No elements in the tree!\n");
        return;
    }
    if (t->l != NULL) 
        postorder(t->l);
    if (t->r != NULL) 
        postorder(t->r);
    printf("%d -> ", t->value);
}