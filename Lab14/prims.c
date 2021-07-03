#include<stdio.h>
#include<conio.h>
#include <limits.h>
#include <time.h>
int a[20][20];
void printMST(int parent[],int n)
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i, a[i][parent[i]]);
}
int findMinVertex(int visited[],int weight[],int n)
{
    int minVertex = -1; // Initialized to -1 means there is no vertex till now
     for (int i = 0; i < n; i++) 
     {
       if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])) 
       {
       minVertex = i;
       }
     }
     return minVertex;
}

void prim(int n)
{
    int parent[n];
    int weight[n];
    int visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        weight[i]=INT_MAX;
    }
    weight[0]=0;
    parent[0]=-1;
    for(int count=0;count<n-1;count++)
    {
        int minVertex=findMinVertex(visited,weight,n);
        visited[minVertex]=1;
            for (int j = 0; j < n; j++) 
            {
                if(a[minVertex][j] != 0 && !visited[j]) 
                {
                     if(a[minVertex][j] < weight[j]) 
                     {
                     // updating weight array and parent array
                     weight[j] = a[minVertex][j];
                     parent[j] = minVertex;
                     }
                }
            }
    }
    printMST(parent,n);
}

void main() {
    int i,j,n;
    clock_t start, end;
    double cpu_time_used;
    printf("\n Enter number of vertices:");
    scanf("%d",&n);
    
    printf("\n Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
        scanf("%d",&a[i][j]);
        }
    }
    
    start = clock();
    prim(n);
    end = clock();
    
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("TIME FOR FUNCTION EXECUTION is %f\n", cpu_time_used);
    getch();
}
