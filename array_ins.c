#include<stdio.h>
int main()
{
int arr[25],pos,n,val,i;
printf("enter the total number of elements in the array\n");
scanf("%d",&n);

printf("enter %d the elements of the array\n",n);

for(i=0;i<n;i++)
scanf("%d",&arr[i]);

printf("enter the position where you want to insert the number");
scanf("%d",&pos);
 
printf("enter the value to be inserted\n");
scanf("%d",&val);

for(i=n;i>=pos;i--)

arr[i]=arr[i-1];
arr[pos-1]=val;

printf("Resultant array is");

for(i=0;i<=n;i++)
printf("%d\n",arr[i]);

return 0;
}





