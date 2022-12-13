#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10

void selection_sort(int [], int);
int main()
{
  int ARR[MAX] , i , size;
  do
  {
    printf("\n enter the size of the array(max %d):",MAX);
    scanf("%d",&size);

  } while(size>MAX);
  printf("\n Enter the elements of the array: \n");
  for(i=0;i<size;i++)
  {
    scanf("%d",&ARR[i]);
  }
   
    selection_sort(ARR,size);
    printf("\n the sorted array is :");
    for (i=0; i<size;i++)
    {
        printf("%d,",ARR[i]);
        

    }
    getch();

  }

void selection_sort(int ARR[], int size)
{
int i, j , k , small,pos;
for ( i = 0; i < size-1; i++)
{
    small = ARR[i];
    pos=i;
    for (j = i+1; j < size; j++)
    {

      if (ARR[j] <small)
      {
        small = ARR[j];
        pos=j;
      }
        

    }
    ARR[pos] = ARR[i];
    ARR[i] = small;

for (k=0; k<size;k++)
{
    printf("%d,",ARR[k]);

}
printf("\n No of passes: %d",i);
}



}