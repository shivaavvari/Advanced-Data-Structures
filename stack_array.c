#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define True 1
#define False 0
#define MAX 10
typedef struct stack{

   int item[MAX];
   int Top;


}stk;

void createstack(stk*);
void push(stk*,int);
int pop(stk*);
int isempty(stk*);
int isfull(stk*);
int main()
{
  int choice;
  int value;
  stk s;
  createstack(&s);
  do
  {

   printf("\n\n Main Menu");
   printf("\n1. Push");
   printf("\n2. Pop");
   
   printf("\n4. Exit\n");
   printf("\n Enter your choice :");
   scanf("%d",&choice);
   switch (choice)
   {
    case 1:
    /* code */
     printf("\n Enter the value to be inserted:");
     scanf("%d",&value);
     push(&s,value);
     getch();
    break;
    case 2:
     value =pop(&s);
     if (value==0)
     {
        printf("\n underflow: stack is empty");

     }
     else
     {
        printf("\nPopped element is :%d",value);

     }
    getch();
    break;
    case 4: exit(0);

    
   default: printf("\n invalid choice !");
    
   }


  } while (1);
}


void createstack(stk* s)
{
    s->Top=-1;
}
void push(stk* s,int element)
{
    if (isfull(s))
    {
        printf("\noverflow : stack is full!");
        return;
       }
       s->Top++;
       s->item[s->Top]=element;
       printf("\n Value is pushed on to the stack");

       
}

int pop(stk * s)
{
    int popped;
    if (isempty(s))
    {
        return 0;
    }
    popped = s->item[s->Top];
    s->Top--;
    return popped;
}

int isempty(stk* s)
{
    if(s->Top==-1)
    {
        return True;
    }
    else
    {
        return False;       
    }

}

int isfull(stk *s)
{
    if (s->Top==MAX-1)
    {
        return True;

    }
    else
    {
        return False;
    }
}