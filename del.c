#include<stdio.h>
int main()
{
int i,pos,n,arr[100];

printf("enter the total no elements",n);
scanf("%d",&n); 

printf("enter %d the elements\n",n);
for(i=1;i<n;i++)
scanf("%d",&arr[i]);

printf("enter the position to be deleted");
scanf("%d",&pos);

if(pos>=n+1||pos<1)
printf("deletion not possible\n");

else
{
for(i=pos-1;i<n-1;i++)
arr[i]=arr[i+1];

printf("resultant array is\n");

for(i=0;i<n-1;i++)
printf("%d\n",arr[i]);
}

return 0;

}




