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
Node * create_node();

int main()
{
create_node();
create_node();
create_node();
create_node();
create_node();

}


Node *create_node()
{

Node *nptr;
int item;
nptr = (Node *)malloc(sizeof(Node));
if (nptr = NULL)
{
    printf("\n Overflow: Memory not allocated");
}


printf("\n Enter the value to be inserted: ");
scanf("%d",&item);
nptr->info = item;
nptr->next=NULL;
return(nptr);
printf("%d",nptr->info);
}



