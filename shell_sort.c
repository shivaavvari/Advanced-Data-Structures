#include <stdio.h>
#include <conio.h>

#define MAX 20


void shell_sort(int[], int);

int main()
{
int ARR[MAX], i , size;
do
{
    /* code */

    printf("Enter the size of the Array max (%d):",MAX);
    scanf("%d",&size);

    
} while (size > MAX);
printf("\n Enter the elements in the Array");
for (i=0; i<size;i++)
{
    scanf("%d",&ARR[i]);
}
shell_sort(ARR, size);
printf("\n The sorted Array is :");
for (i = 0; i < size; i++)
{
    printf("%d,",ARR[i]);
}

    
getch();
}


void shell_sort(int ARR[],int size)
{
  int swap, temp,i,count=0,k;
  int d= size/2;
  do
  {
    do
    {
        /* code */
        swap =0;
        for ( i = 0; i < size-d; i++)
        {
            /* code */
            if (ARR[i] > ARR[i+d])
            {
                /* code */
                temp = ARR[i];
                ARR[i] = ARR[i+d];
                ARR[i+d] = temp;
                swap=1;


            }
            
        }
        
    } while (swap);
    
    /* code */
    count++;
    printf("\n Array after pass %d",count);
    for ( k = 0; i < size; k++)
    {
        /* code */
        printf("%d",ARR[k]);
    }
    

  } while (d=d/2);
   printf("\n number of passes: %d,",count); 



}