#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <time.h>
int max(int a, int b) {
   if(a>b){
      return a;
   } else {
      return b;
   }
}
int knapsack(int W, int wt[], int val[], int n) {
   int i, w;
   int knap[n+1][W+1];
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= W; w++) {
         if (i==0 || w==0)
            knap[i][w] = 0;
         else if (wt[i-1] <= w)
            knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
         else
            knap[i][w] = knap[i-1][w];
      }
   }
   return knap[n][W];
}
int main() 
{
   int W;
   int n;
   clock_t start, end;
   double cpu_time_used;
   printf("Enter the number of items:");
   scanf("%d",&n);
   int val[n];
   int wt[n];
   printf("Enter the maximum capacity of the knapsack:");
   scanf("%d",&W);
   printf("Enter the values of items:");
   for(int i=0;i<n;i++)
   {
       scanf("%d",&val[i]);
   }
   printf("Enter the weights of items:");
   for(int i=0;i<n;i++)
   {
       scanf("%d",&wt[i]);
   }
   start = clock();
   int sol=knapsack(W, wt, val, n);
   end = clock();
   printf("The solution is : %d\n", sol);
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   printf("TIME FOR FUNCTION EXECUTION is %f\n", cpu_time_used);
   getch();
   return 0;
}
