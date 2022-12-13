#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 20
void  merging(int[], int,int,int,int);
void Merge_sort(int[], int,int);





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
Merge_sort(ARR,0,size-1);
printf("\n The sorted array is :");
for (int i = 0; i < size; i++)
{
    printf("%d,",ARR[i]);
}

    
getch();
}
void Merge_sort(int ARR[], int low,int high)
{
int mid;
if(low<high)
{
mid = floor((low + high)/2);
Merge_sort(ARR,low,mid);

Merge_sort(ARR,mid+1,high);

merging(ARR,low,mid,mid+1,high);

}

}

void merging(int ARR[],int ll,int ul,int lr,int ur)
{
    int i,j,k,merged[MAX];
    i = ll;
    j=  ul;
    k=  ll;

    while( i<=lr && j<=ur)
    {
       if(ARR[i]<=ARR[j])
       {
          merged[k] = ARR[i];
          i++;
       }
       else{
        merged[k] = ARR[j];
          j++;
        
       }
        k++;
    }
    if (i<=lr)
    {
      while(i<= lr)
      {
        merged[k] = ARR[i];
          i++;
          k++;  
      }
    }
    if (j<=ur)
    {
      while(j<= ur)
      {
        merged[k] = ARR[j];
          j++;
          k++;  
      }
    }
    
    for (k=ll; k<=ur;k++)
    {
        ARR[k] = merged[k];
    }

}   



