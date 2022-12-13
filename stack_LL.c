#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define True 1
#define False 0
typedef struct node
{
    int info;
    struct node *next;

}Node;
void createstack(Node **);
int isempty(Node *);
void push(Node **,int);
int pop(Node **);
int main()
{
   int choice, value,temps;
   Node *Top;
   createstack(&Top);
   do{
      printf("\n\t Main Menu");
      printf("\n1. Push");
      printf("\n2. Pop");
      printf("\n3. Exit");

      printf("\n\t Enter your choice : ");
      scanf("%d",&choice);

      switch(choice)
      {
        case 1: printf("\n Enter the value to be inserted:");
                scanf("%d",&value);
                push(&Top, value);
                getch();
                break;

        case 2:  
                    value = pop(&Top);
                 if (value==0)
                 {
                    printf("Underflow");

                 }
                 else
                 {
                    printf("\n popped value is %d",value);
                 }
                 getch();
                 break;
        
        case 3: exit(0);
                default: printf("\n Invalid choice !");    
                     }     


   }while(1);

   
    return 0;
}

void push(Node **Top, int element)
{
    Node *nptr;
    nptr =(Node*)malloc(sizeof(Node));
    if (nptr==NULL)
    {
        printf("Memory not allcoated");
        return;
    }
    nptr->info = element;
    nptr->next =*Top;
    *Top = nptr;
    printf("\n Value is pushed onto stack...");
}

void createstack(Node **Top)
{
    *Top = NULL;
    printf("top is null");
}
int isempty(Node *Top )
{
if (Top == NULL)
{
    return True;
}
else
{
    return False;
}
   
}
int pop(Node **Top)
{
    
    int popped;
    Node * temp;
   if (isempty(*Top))
   {
    return 0;
   }
    popped = (*Top) ->info;
    temp = (*Top);
    *Top = (*Top)->next;
    free(temp);
    return popped;
    
}