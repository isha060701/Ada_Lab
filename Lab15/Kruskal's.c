#include<stdio.h>
#include<conio.h>
#include <limits.h>
#include <time.h>
int src[20];
int dest[20];
int wt[20];
int parent[20];
void sort(int wt[],int n)
{
    int i, j;
   for (i = 0; i < n-1; i++)     
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (wt[j] > wt[j+1])
            {
                int temp=wt[j];
        wt[j]=wt[j+1];
        wt[j+1]=temp;
        
        temp=src[j];
        src[j]=src[j+1];
        src[j+1]=temp;
        
        temp=dest[j];
        dest[j]=dest[j+1];
        dest[j+1]=temp;
            }
        }
    }
                
}
int findParent(int v,int parent[])
{
    if(parent[v]==v)
    {
        return v;
    }
    findParent(parent[v],parent);
}
void kruskal(int n,int e)
{
    int output[n-1];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int count=0;
    int i=0;
    printf("\nEdge Weight");
    while(count!=n-1)
    {
        int srcParent=findParent(src[i],parent);
        int destParent=findParent(dest[i],parent);
        if(srcParent!=destParent)
        {
            output[count]=wt[i];
            printf("\n%d-%d=%d",src[i],dest[i],output[count]);
            count++;
            parent[srcParent]=destParent;
        }
        i++;
    }
}
void main() {
    int i,j,n,e;
    clock_t start, end;
    double cpu_time_used;
    printf("\n Enter number of vertices:");
    scanf("%d",&n);
    printf("\n Enter number of edges:");
    scanf("%d",&e);
    int x=0;
    printf("\n Enter the source,destination,weight of edge respectively:\n");
    for(i=0;i<e;i++)
    {
        scanf("%d%d%d",&src[i],&dest[i],&wt[i]);
    }
    
    start = clock();
    sort(wt,e);
    kruskal(n,e);
    end = clock();
    
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTIME FOR FUNCTION EXECUTION is %f\n", cpu_time_used);
    getch();
}
