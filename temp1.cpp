#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define True 1
#define False 0
struct node
{
    int info;
    struct node *next;

};
typedef struct node Node;
Node * create_node()
{

Node *nptr;
int item;
nptr = (Node *)malloc(sizeof(Node));
if (nptr = NULL)
{
    printf("\n Overflow: Memory not allocated");
    exit(0);

}
printf("\n Enter the value to be inserted: ");
scanf("%d",&item);
nptr->info = item;
nptr->next=NULL;
return(nptr);
}

int isempty(Node *Start)
{
  if (Start =NULL)
   return True;
  else
   return False;
}
void display(Node *Start)
{
  Node *temp = Start;
  if (isempty(temp))
  {
    printf("\n List is empty!!");
    return;
  }
    printf("\n The linked list is: ");

while (temp != NULL)
    {
       printf("%d", temp->info);
       temp = temp-> next;

    }

}


int main()
{
Node * start = null;
create_node();

}