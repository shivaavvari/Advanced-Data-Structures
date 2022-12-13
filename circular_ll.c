#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define True 1
#define False 0
typedef struct  node
{
    int info;
    struct node *next;

}Node;


Node* create_node();
int isempty( Node*);
void display(Node*);
int count_node(Node*);
void insert_beg(Node**);
void insert_end(Node**);
void delete_beg(Node **);
void delete_end(Node **);
int  main()
{
int item,ch,ch1;
Node *Start = NULL;
do
{
   printf("\n1. insert");
   printf("\n2. delete");
   printf("\n3. display");
   printf("\n4. Exit\n");
   printf("\n Enter your choice :");
   scanf("%d",&ch);

   switch(ch)
   {
    case 1: printf("\n Insert at the beginning");
            printf("\n Insert at the end");
            printf("\n Insert at the specified");
            printf("\nBack to main menu ");
            printf("\nEnter your choice");
            scanf("%d",&ch1);
            switch(ch1)
            {
                case 1: insert_beg(&Start);
                                break;
                case 2: insert_end(&Start);
                                break;
                
                default: printf("\n invalid choice!");
            }
            break;

    case 2: printf("\n Delete at the beginning");
            printf("\n Delete at the end");
            printf("\n Delete at the specified");
            printf("\nBack to main menu ");
            printf("\nEnter your choice");
            scanf("%d",&ch1);
            switch(ch1)
            {
                case 1: delete_beg(&Start);
                break;
                case 2: delete_end(&Start);
                break;
                default: printf("\n invalid choice!");
            }
            break;
    case 3: display(Start);
             break;
    case 4:
             exit(0);         

    default: printf("\n invalid choice ");
    }
    getch();
}  while(True);
}

Node * create_node()
{

Node *nptr;
int item;
nptr = (Node *)malloc(sizeof(Node));
if (nptr== NULL)
{
    printf("\n Overflow: Memory not allocated");
    exit(0);    

}
printf("\n Enter the value to be inserted: ");
scanf("%d",&item);
nptr->info = item;
nptr->next=NULL;
return(nptr);
printf("%d",nptr->info);
}

int isempty(Node *Start)
{
  if (Start ==NULL)
   return True;
  else
   return False;
}


void display(Node *Start)
{
  Node * temp = Start;
  if (isempty(temp))
  {
    printf("\n List is empty!!");
    return;
  }
    printf("\n The linked list is: ");
   do
     {
       printf("%d,", temp->info);
       temp = temp-> next;
    }while (temp != Start);   
    printf("\nlist printed");
       

}

int count_node(Node *Start)
{
 Node *temp = Start;
  int count= 0 ;
  while( temp->next != NULL)
{
  count++;
  temp = temp->next;
}
return(count);
}


void insert_beg(Node **Start)
{
 Node  *nptr = create_node();
 Node *temp = *Start ;
 if (isempty(*Start))
{
  *Start = nptr;
  (*Start)->next =*Start;
  }
  else
  {
    while(temp->next !=*Start)
    {
        temp = temp->next;
    }
    nptr->next =*Start;
    *Start= nptr;
    temp->next=*Start;
  }
 printf(" \n Node inserted");

}


void insert_end(Node **Start)
{
    Node *temp = *Start;
    Node *nptr = create_node();
    if (isempty(temp))
    {
        *Start = nptr;
        (*Start)->next =*Start;
    }
    else
    {
        while ((temp->next) != *Start)
        {
            temp = temp->next;
        }
        temp->next = nptr;
        nptr->next = *Start;
    }
    printf("\n Node inserted");
}
void delete_beg(Node **Start)
{

    Node *temp = *Start;
    Node *ptr = temp;
    if (isempty(temp))
    {
        printf("\n Underfow: List is empty");
        return;
    }
    while(ptr->next != *Start)
    {
        ptr=ptr->next;
    }
    *Start = (*Start)->next;
     ptr->next = *Start;
    free(temp);
    printf("\n Node deleted");

}

void delete_end(Node **Start)
{
    Node *temp =  *Start;
    Node *save;
    if (isempty(temp))
    {
        printf("\n Underfow: List is empty");
        return;
    }
    if (temp-> next == *Start)
    {
        *Start=NULL;
        
    } 
    else{
        while (temp->next != *Start)
        {
            save =temp;
            temp = temp->next;

        }
        save ->next =NULL;
        
    }
    free(temp);
    printf("\n line deleted");
    
}
