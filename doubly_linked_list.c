#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define True 1
#define False 0
typedef struct node
{
    int info;
    struct node *next;
    struct node *prev;

}Node;

Node* create_node();
int isempty(Node*);
void display(Node*);
int count_node(Node*);
void insert_beg(Node**);
void insert_end(Node**);
void insert_pos(Node**);
void delete_beg(Node**);
void delete_end(Node**);
void delete_pos(Node**);



int  main()
{
int item,ch,ch1;
Node *Start = NULL;
do
{
   printf("\n\n Main Menu");
   printf("\n1. insert");
   printf("\n2. delete");
   printf("\n3. display");
   printf("\n4. Exit\n");
   printf("\n Enter your choice :");
   scanf("%d",&ch);

   switch(ch)
   {
    case 1: printf("\n 1.Insert at the beginning");
            printf("\n 2.Insert at the end");
            printf("\n 3.Insert at the specified");
            printf("\n 4.Back to main menu ");
            printf("\n 5.Enter your choice");
            scanf("%d",&ch1);
        switch(ch1)
        {
            case 1: insert_beg(&Start);
                              break;
            case 2: insert_end(&Start);
                              break;
            case 3: insert_pos(&Start);
                              break;
            case 4: break;
        
            default: printf("\n invalid choice!");
        }
        break;

        case 2: printf("\n 1.Delete at the beginning");
                printf("\n 2.Delete at the end");
                printf("\n 3.Delete at the specified");
                printf("\n 4.Back to main menu ");
                printf("\n Enter your choice");
               scanf("%d",&ch1);
        switch(ch1)
        {
            case 1: delete_beg(&Start);
            break;
            case 2: delete_end(&Start);
            break;
            case 3: delete_pos(&Start);
            break;
            case 4: break;
            default: printf("\n invalid choice!");
        }
        break;
        case 3: display(Start);

                        break;
        case 4: exit(1);                

        default: printf("\n invalid choice ");
        }
    getch();
}
while(1);
}


Node * create_node()
{

Node *nptr;
int item;
nptr = (Node *)malloc(sizeof(Node));
if (nptr == NULL)
{
    printf("\n Overflow: Memory not allocated");
    exit(1);

}
printf("\n Enter the value to be inserted: ");
scanf("%d",&item);
nptr->info = item;
nptr->next=NULL;
nptr->prev=NULL;
return(nptr);
}

int isempty(Node *Start)
{
  if (Start==NULL)
   return True;
  else
   return False;
}


void display(Node *Start)
{
  Node* temp = Start;
  if (temp==NULL)
  {printf("\n List is empty"); } 
  else  
   {
    printf("\n The linked list is: ");
   
    do
     {
       printf("%d,", temp->info);
       temp = temp-> next;
             
     }while (temp != NULL);

   }
}
int count_node(Node *Start)
{
 Node *temp = Start;
  int count= 0 ;
  while( temp!= NULL)
{
  count++;
  temp = temp->next;
}
return(count);
}

void insert_beg(Node **Start)
{
 Node  *nptr = create_node();
if (*Start!=NULL)
{
 nptr -> next = *Start;
 (*Start)->prev =nptr;
 
}
*Start =nptr;
printf(" \n Node inserted");
}




void insert_end(Node **Start)
{
    Node *temp ;
    Node *nptr = create_node();
    if (*Start==NULL)
    {
        *Start = nptr;
    }
    else
    {
        temp =*Start;
        while (temp->next != NULL)
        {
         temp = temp->next;
         temp->next =nptr;
         nptr->prev=temp;
         
         
        }
        

    } 
    printf("\n Node inserted");
}

void insert_pos( Node  **Start)
{
    int i, pos,count;
    Node *nptr = create_node();
    Node *temp =*Start,*ptr;
    printf("\n enter the position at which you want to insert:");
    scanf("%d",&pos);
    count = count_node(temp);
    if(pos>count+1 || pos==0)
    {
        printf("\n invalid position ");
        return;
    }

    if(pos==1)
    {
        nptr->next = *Start;
         *Start = nptr;

    }
    else{

        for (i=1;i<pos-1;i++)
        {
             temp =temp->next;
             ptr =temp->next;
             ptr->prev = nptr;
             nptr->next = ptr;
             nptr->prev=temp;
             temp->next =nptr;
        }
    
    }
    printf("\n Node inserted");

}

void delete_beg(Node **Start)
{

    Node *temp = *Start;
    *Start = (*Start)->next;
    (*Start)->prev= NULL;    
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
    if (temp-> next == NULL)
    {
        *Start=NULL;
        
    } 
    else{
        while (temp->next != NULL)
        {
            save =temp;
            temp = temp->next;

        }
        save ->next =NULL;
        
    }
    free(temp);
    printf("\n line deleted");
    
}


void delete_pos(Node **Start)
{
  Node *temp = *Start, *save,*ptr;
  int i , pos, count;


    printf("\n enter the position at which you want to delete:");
    scanf("%d",&pos);
    count = count_node(temp);
    if(pos>count)
    {
        printf("\n invalid position ");
        return;
    }
    if (pos==1)
    {
        *Start  =temp->next;
     (*Start)->prev =NULL;
    }
        else
        {
          for (i=1;i<pos;i++)
          {
            save =temp;
            temp = temp->next;

          }

          ptr = temp->next;

          save->next = ptr;
          ptr->prev=save;
        }
        free(temp);
        printf("\n node Deleted");

        }   
    
