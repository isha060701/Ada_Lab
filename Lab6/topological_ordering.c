#include<stdio.h>
#include<conio.h>
#include <time.h>
int a[20][20],visited[20],n,stack[20],top=-1;
void dfs_helper(int v)
{
     int i;
     visited[v]=1;
     for(i=1;i<=n;i++)
     {
         if(a[v][i] && !visited[i])
        {
           dfs_helper(i);
        }
     }
     stack[++top]=v;
}
void dfs()
{
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs_helper(i);
        }
    }
    while(top>=0)
    {
        printf("%d ",stack[top--]);
    }
}
void main()
{
int i,j,count=0;
clock_t start, end;
double cpu_time_used;
printf("\n Enter number of vertices:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
visited[i]=0;
for(j=1;j<=n;j++)
a[i][j]=0;
}
printf("\n Enter the adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
start = clock();
dfs();
end = clock();
printf("\n");
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("TIME FOR FUNCTION EXECUTION is %f\n", cpu_time_used);
getch();
}
}
