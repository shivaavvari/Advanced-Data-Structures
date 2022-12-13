#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define True 1
#define False 0
typedef struct node
{
    int info;
    struct node *next;
    union general_llist
    {
        int info;
        struct node * downptr
    };
    

}GNode;