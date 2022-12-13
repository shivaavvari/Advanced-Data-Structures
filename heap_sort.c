#include <stdio.h>
#include <conio.h>

#define MAX 20

void make_heap(int [], int);
void heap_sort(int[], int);
void restore(int[], int);

int main()
{
int ARR[MAX], i , size;
do
{
    /* code */

    printf("Enter the size of the array max (%d):",MAX);
    scanf("%d",&size);

    
} while (size > MAX);
printf("\n Enter the elements in the array");
for (i=0; i<size;i++)
{
    scanf("%d",&ARR[i]);
}
heap_sort(ARR,size);
printf("\n The sorted array is :");
for (int i = 0; i < size; i++)
{
    printf("%d,",ARR[i]);
}


getch();
}
void make_heap(int ARR[], int size) 
{
int i, k , parent, child;
for ( i = 1; i <size; i++)
{
    child = ARR[i];
    k=i;
    parent = (k-1)/2;
    while(k>0 && ARR[parent]<child)
    {

        ARR[k] = ARR[parent];
        k =parent;
        parent = (k-1)/2;
    }
    ARR[k] = child;
}
}

void restore(int ARR[], int size)
{
    int i=0, lchild, rchild, temp;
    do
    {
        /* code */
        lchild = (2*i+1);
        rchild = (2*i+2);

        if (rchild >= size)
        {
            if( lchild <size && ARR[i]<ARR[lchild])
            {
                temp = ARR[i];
                ARR[i] = ARR[lchild];
                ARR[lchild] = temp;

            }
            break;

        }
            else if(ARR[i] < ARR[lchild]  || ARR[i] < ARR[rchild])
            {
            if(ARR[lchild] > ARR[rchild])
            {
              temp = ARR[i];
                ARR[i] = ARR[lchild];
                ARR[lchild] = temp;
                i = lchild;
            }
            else
            {
              temp = ARR[i];
                ARR[i] = ARR[rchild];
                ARR[rchild] = temp;
                i = rchild;
                
            }
            }
            else
            {
                break;
            }

        } while(1);


}


void heap_sort(int ARR[], int size)
{
    int i, j=1,k, temp;
    make_heap(ARR,size);
    printf("\n initial heap:");
    for ( i = 0; i < size; i++)
    {
        /* code */
        printf("%d,",ARR[i]);

    }
    for ( i = size-1; i > 0; i--)
    {
        /* code */
        temp = ARR[i];
        ARR[i]= ARR[0];
        ARR[0] = temp;
        restore(ARR,i);
        for ( k = 0; k < size; k++)

        {
            /* code */

            printf("%d,",ARR[k]);
            j++;

        }
        printf("\n number of passes %d \n",j-1);
    }

    
    
}