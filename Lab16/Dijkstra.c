#include<stdio.h>
#include<conio.h>
#include <limits.h>
#include <time.h>
int a[20][20];
void printSolution(int dist[],int n)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
int findMinVertex(int visited[],int dist[],int n)
{
    int minVertex = -1;
     for (int i = 0; i < n; i++) 
     {
       if (!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex])) 
       {
          minVertex = i;
       }
     }
     return minVertex;
}

void dijsktra(int n,int src)
{
    int visited[n];
    int dist[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    for(int i=0;i<n-1;i++)
    {
        int minVertex=findMinVertex(visited,dist,n);
        visited[minVertex]=1;
        for(int j=0;j<n;j++)
        {
            if(a[minVertex][j]!=0 && !visited[j])
            {
                if(a[minVertex][j]+dist[minVertex]<dist[j])
                {
                    dist[j]=a[minVertex][j]+dist[minVertex];
                }
            }
        }
    }
    printSolution(dist,n);
}

  
void main() {
    int i,j,n;
    clock_t start, end;
    double cpu_time_used;
    int src;
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
    printf("Enter the source vertex\n:");
    scanf("%d",&src);
    start = clock();
    dijsktra(n,src);
    end = clock();
    
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("TIME FOR FUNCTION EXECUTION is %f\n", cpu_time_used);
    getch();
}
