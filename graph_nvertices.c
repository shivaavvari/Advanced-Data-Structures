#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    char vertex;
    struct  node *next;
    
}*gnode;

void create_graph(struct node* adj[], int no_of_nodes);
void display_graph(struct node* adj[], int no_of_nodes);
int main()
{
    struct node* Adj[10];
    int i, no_of_nodes;
    printf("enter the numbet of nodes in G: ");
    scanf("%d", &no_of_nodes);
    for (i=0;i<no_of_nodes;i++)
    {
        Adj[i] = NULL;

    }
    create_graph(Adj,no_of_nodes);
    display_graph(Adj,no_of_nodes);
    getch();
    return 0;
    
    }

void create_graph(struct node* Adj[], int no_of_nodes)
{
    struct node *new_node,*last;
    int i,j,n,val;
    for (i=0;i<no_of_nodes;i++)
    {
        last = NULL;
        printf("Enter the number of neighbors %d: ",i);
        scanf("%d",&n);
        for (j=1;j<=n;j++)
        {
            printf("\n Enter the neighnbor %d of %d",j,i);
            scanf("%d",&val);
            new_node = (struct node*) malloc(sizeof(struct node));
            new_node -> vertex = val;
            new_node -> next = NULL;
            if( Adj[i] == NULL)
               {
                Adj[i] = new_node;
               }
            else
            {
                last->next = new_node;
                

            }
            last = new_node;
        }    
    }

}


void display_graph(struct node* Adj[], int no_of_nodes)
{
  struct node *ptr;
  int i;
  for (i=0;i<no_of_nodes;i++)
  {
    ptr= Adj[i];
    printf("\n The neighbors of node %d :  are", i);
    while ( ptr != NULL)
    {
        printf("\t %d", ptr->vertex);
        ptr =ptr->next;

    }
  }

}