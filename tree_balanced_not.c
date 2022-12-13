#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{

int data;
struct node * left;
struct node * right;
};

bool isBalanced(struct node *root);
int findHeight(struct node *root)
{

    int lefth=0, righth=0;
    if (root==NULL)
    {
        return 0;
    }
    lefth = findHeight(root->left);
    righth = findHeight(root->right);

    if(lefth >righth)
    {
        lefth += 1;

    }
    else
    {
        righth+=1;
    }
    
}

bool isBalanced(struct  node * root)
{
int left_height, right_height;
if( root==NULL)
{
    return true;
}

left_height = findHeight(root->left);
right_height = findHeight(root->right);
if ( abs(left_height-right_height) <=1 && isBalanced(root->left) && isBalanced(root->right))
    { return true;}

return false;
}

int main()
{
    struct node* root;
    root = (struct node *)malloc(sizeof(struct node));
    root->data =5;
    root->left = (struct node *)malloc(sizeof(struct node));
    root->left->data = 8;
    root->left->left = (struct node *)malloc(sizeof(struct node));
    root ->left->left->data =10;
    root->left->left->left = root->left->left->right =NULL;
    root->left->right = (struct node *)malloc(sizeof(struct node));
    root->left->right->data = 15;
    root->left->right->left = root->left->right->right =NULL;
    root->right = (struct node *)malloc(sizeof(struct node));
    root->right->data = 8;
    root->right->left = root->right->right=NULL;

    if(isBalanced(root))
    {
        printf("\n\n\n The given tree is balanced \n\n\n");
    }
    else{

        printf("\n\n\n The given tree  is not balanced \n\n\n");
    }
     return 0;
}