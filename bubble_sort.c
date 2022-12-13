#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10

void bubble_sort(int [], int);
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
   
    bubble_sort(ARR,size);
    printf("\n the sorted array is :");
    for (i=0; i<size;i++)
    {
        printf("%d,",ARR[i]);
        

    }
    getch();

  }

void bubble_sort(int ARR[], int size)
{
int i, j , k , temp, flag=1;
i=0;
while(i<size-1 && flag ==1)
{
flag=0;
for (int j=0; j<size-i-1;j++)
{
  if (ARR[j] > ARR[j+1])
  {
    flag=1;
    temp = ARR[j];
    ARR[j] = ARR[j+1];
    ARR[j+1] = temp;

  }

}
printf("\n Arrray after pass %d:",i+1);
for (k=0; k<size;k++)
{
    printf("%d,",ARR[k]);

}
i++;
}
printf("\n No of passes: %d",i);
}