#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <time.h>
double inf=INFINITY;
int a[20][20];
int min(int,int);
void warshal(int p[20][20],int n) 
{
	int i,j,k;
	for (k=1;k<=n;k++)
	{
	  for (i=1;i<=n;i++)
	   {
	       for (j=1;j<=n;j++)
	      {
	        if(i==j)
              p[i][j]=0;
            else
              p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
	      }
	   }
	}
}
int min(int a,int b)
{
 if(a<b)
  return(a);
 else
  return(b);
}
void main() {
    int i,j,n;
    clock_t start, end;
    double cpu_time_used;
    printf("\n Enter number of vertices:");
    scanf("%d",&n);
    
    printf("\n Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
        scanf("%d",&a[i][j]);
        }
    }
    
    start = clock();
    warshal(a,n);
    end = clock();
    
	printf("\n Transitive closure: \n");
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++)
		   printf("%d\t",a[i][j]);
		printf("\n");
	}
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("TIME FOR FUNCTION EXECUTION is %f\n", cpu_time_used);
    getch();
}
