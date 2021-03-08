#include<stdio.h>

int a[20][20];
int q[20],visited[20],n,i,j,v;
int front=-1,rear=-1;
void bfs(int v)
{
for(i=0;i<n;i++)
{
if(a[v][i]!=0 && visited[i]==0)
{
rear=rear+1;
q[rear]=i;
visited[i]=1;
printf("%d\t",i);
}
}
front=front+1;
if(front<=rear)
{
bfs(q[front]);
}
}
int main()
{
printf("enter the no of vertices");
scanf("%d",&n);
for(i=0;i<n;i++)
{
visited[i]=0;
}
printf("enter the adjecancy matrix");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);

}
}
printf("enter the starting vertex");
scanf("%d",&v);
front=0;
rear=0;
q[rear]=v;
printf("BFS traversal is/n");
printf("%d\t",v);
bfs(v);
}

