#include<stdio.h>
#include<conio.h>
#include <limits.h>
#include <time.h>
int w[20],x[20],m,flag=0;;

void sum_of_subsets(int s,int k,int r)
{
	x[k]=1;
	if(s+w[k]==m)
	{
		for(int i=0;i<=k;i++)
		{
			if(x[i]==1)
			printf("%d ",w[i]);
			flag=1;
		}
		printf("\n");
	}
	else if(s+w[k]+w[k+1]<=m)
	sum_of_subsets(s+w[k],k+1,r-w[k]);
	
	if((s+r-w[k]>=m)&&(s+w[k+1]<=m))
	{
		x[k]=0;
		sum_of_subsets(s,k+1,r-w[k]);
	}
}
		

int main()
{
	int i,n,r=0;
	clock_t start, end;
    double cpu_time_used;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements in ascending order\n");
	for(i=0;i<n;i++){
	scanf("%d",&w[i]);
	r=r+w[i];}
	printf("Enter the sum\n");
	scanf("%d",&m);
	printf("\n");
	start=clock();
	sum_of_subsets(0,0,r);
	end=clock();
	if(flag==0)
	printf("No solution\n");
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("TIME FOR FUNCTION EXECUTION is %f\n", cpu_time_used);
    getch();
	return 0;
}
