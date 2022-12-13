#include <stdio.h>
#include <conio.h>

#define MAX 20

void quick_sort(int [],int, int,int);
int splitarray(int [],int, int);

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
quick_sort(ARR,size,0,size-1);
printf("\n The sorted Array is :");
for (int i = 0; i < size; i++)
{
    printf("%d,",ARR[i]);
}

    
getch();
}


void quick_sort(int ARR[],int size, int lb, int ub)
{

int pivot, k;
static int i=0;
if(lb<ub)
{
  pivot = splitarray(ARR,lb,ub);
  printf("\n Array after pass %d:",i+1);
  for ( k = 0; k < size; k++)
{
    printf("%d,",ARR[k]);
     i++;
}
 quick_sort(ARR,size,lb,pivot-1);
 quick_sort(ARR,size,pivot+1,ub);
 

}
else if (ub==(size-1))
{
    /* code */
    printf("No. of passes : %d",i);
}


} 

int splitarray(int ARR[],int lb, int ub)
{
    int pivot,beg,end,temp,flag=0;
    beg=pivot=lb;
    end =ub;
    while(!flag)
    {
        while((ARR[pivot]<=ARR[end]) &&  (pivot != end))
                      {
                           end--;
                      }
       if (pivot==end)
       {
        flag=1;
       }
       else
       {
        temp = ARR[pivot];
        ARR[pivot] = ARR[end];
        ARR[end] = temp;
        pivot= end;
       }
     
    if (!flag)
    {
    
     while((ARR[pivot]>=ARR[beg]) &&  (pivot!=beg))
     {
       beg++;
     }

       if (pivot==beg)
       {
        flag=1;
       }
       else
       {
        temp = ARR[pivot];
        ARR[pivot] = ARR[beg];
        ARR[beg] = temp;
        pivot= beg;
       }
    }

     }   
     return pivot;
     
     
         }
