#include <stdio.h>
#include <stdlib.h>


typedef enum{FALSE, TRUE}bool;

struct node {
    int val;  //value of the node.
    int balance; //balance factor at the node.
    struct node* left_child; // left_child of the node.
    struct node* right_child;  //right child of the node.
  //  bool ht_incr; 
};

struct node * search(struct node *ptr, int data) //search where data is at in the tree
{
  if(ptr != NULL)
  {
    if (data < ptr->val)
        ptr = search(ptr->left_child,data);
    else if (data >ptr->val)
        ptr = search(ptr->right_child,data);

    return(ptr);  //return the node ptr where the data is found

  }
}

  struct node *insert(int data, struct node *ptr, bool *ht_inc) // if a new node is inserted the height of it automatically incremented
  {
    
    
    struct node *aptr;  //  create two new node pointer
    struct node *bptr;
    
    
    if (ptr==NULL)      // the pointer val null, so it is allocated.
    {
        ptr =(struct node *)malloc(sizeof(struct node));
        ptr->val = data;
        ptr->left_child = NULL;
        ptr->right_child = NULL;
        ptr->balance =0; // balance factor for a new node is null
        *ht_inc = TRUE; // height increment is true
        return (ptr);
    }


    if (data < ptr->val)   /* if the pointer less than or greater than root - insert in appropriate subtree */ 
    
    {
       ptr->left_child = insert(data, ptr->left_child, ht_inc);
       
       if (*ht_inc == TRUE)
          {

        switch(ptr->balance)
        {
           case -1:
                ptr->balance = 0;
                *ht_inc = FALSE;
                break;
            case 0:
                ptr->balance =1;
                break;
            case 1:
                aptr = ptr->left_child;
                if (aptr->balance ==1)
                    {
                        printf("this is left to left rotation \n");
                        ptr ->left_child = aptr->right_child;  //step 1: LL rotations 
                        aptr ->right_child = ptr;  // ptr -lc- rc->rc- > ptr
                        aptr->balance =0;  // balance = 0
                        ptr->balance = 0;

                        ptr= aptr;    // ptr = aptr 

                    }

                else {
                      printf("This is left to right rotations \n");
                    bptr =  aptr->right_child;  // 2 stars aptr, bptr  assign bptr= aptr's right child
                    aptr->right_child = bptr->left_child;
                    bptr->left_child = aptr;
                    ptr->left_child = aptr->right_child;
                    if(bptr->balance==1)
                        {ptr->balance = -1;}
                        else
                        {
                            ptr->balance =0;

                        }
                    if(bptr->balance== -1)
                        {aptr->balance = 1;}
                        else
                        {
                            aptr->balance =0;
                            
                        }
                        bptr->balance =0;
                        ptr=bptr;

                }
                *ht_inc = FALSE;





                }   

        }

    }
        
if (data> ptr->val)
{
    ptr->right_child = insert(data, ptr->right_child, ht_inc);
    if(*ht_inc ==TRUE)
    {

        switch(ptr->balance)
        {
           case 1:
                ptr->balance = 0;
                *ht_inc = FALSE;
                break;
            case 0:
                ptr->balance =-1;
                break;
            case -1:
                aptr = ptr->right_child;
                if (aptr->balance ==-1)
                {
                  printf("right to right rotation \n");
                  ptr->right_child = aptr->left_child;
                  aptr->left_child = ptr;
                  ptr->balance =0;
                  aptr->balance =0;
                  ptr=aptr;
                }
                else
                {
                    printf("Right to left Rotation \n");
                    bptr = aptr->left_child;
                    bptr->right_child = aptr;
                    ptr->right_child = bptr->left_child;
                    bptr->left_child = ptr;
                    if(bptr->balance==-1)
                        {ptr->balance = 1;}
                        else

                        {
                            ptr->balance =0;

                        }
                    if(bptr->balance== 1)
                        {aptr->balance = -1;}
                        else
                        {
                            aptr->balance =0;
                            
                        }
                        bptr->balance =0;
                        ptr=bptr;

                }
                 *ht_inc = FALSE;

    }

}

}

return(ptr);
}
    
void display(struct node *ptr,int level)
{
    int i;
    if (ptr!= NULL)
    {
        display(ptr->right_child,level+1);
        printf("\n");
        for (i=0;i<level;i++)
        {
            printf("  ");

        }
        printf("%d",ptr->val);
        display(ptr->left_child,level+1);
    }
}
  

void inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {        
        inorder(ptr->left_child);

        printf(", %d ",ptr->val);
        inorder(ptr->right_child);
        

    }
}

int main()
{
    bool ht_inc;
    int data;
    int option;
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root =NULL;
    while(1)
    {
        printf("1. Insert \n");
        printf("2. Display \n");
        printf("3. quit \n");
        printf("Enter your option: ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
              printf("Please enter the value to be inserted \n");
              scanf("%d",&data);
              if( search(root,data)==NULL)
              {
                root = insert(data,root,&ht_inc);}
                else
              {  printf("Duplicate value ignored \n");
                break;
              }
         break;
         case 2:
             if(root==NULL)
             {
                printf("Tree is empty \n");
                continue;
             }

             printf("Tree is : \n");
             display(root,1);
             printf("\n\n");
             printf("Inorder traversal is :");
             inorder(root);
             printf("\n");
             break;
        case 3:
              exit(1);
        default:
            printf("Wrong option \n");
        }     
        

    }



}


