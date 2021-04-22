#include <stdio.h>  
#include <time.h>
#include <stdlib.h>

int Binary_search(int arr[], int l,int r,int e)
{
	int p;
    if(r<l)
    return -1;
    p=(l+r)/2;
    if(arr[p]==e)
    return p;
    if(arr[p]<e)
    return Binary_search(arr,p+1,r,e);
    if(arr[p]>e)
    return Binary_search(arr,l,r-1,e); 
}
 

 void Sort(int arr[], int n)
{
    int i,j,a;
     for (i = 0; i < n; ++i) 
        {
 
            for (j = i + 1; j < n; ++j)
            {
 
                if (arr[i] > arr[j]) 
                {
 
                    a =  arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;
 
                }
 
            }
 
        }
}
 
 int Linear_search(int arr[], int l,int r,int e)
{
		if(l>r)
		return -1;
		if(arr[l]==e)
		return l;
		return Linear_search(arr,l+1,r,e);
}  
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 int main(void)
{
    int choice;
    int n,ele,f;
	  clock_t start, end;
    double cpu_time_used;
    printf("1.Linear Search\n2.Binary Search\n3.Exit\n");
    scanf("%d",&choice);
    while(choice<=2)
    {
        switch(choice)
       {
        case 1:
        {
         	printf("Enter the size of the array\n");
         	scanf("%d",&n);
            int arr[n];
            printf("The elements of the array:\n");
            for(int i=0;i<n;i++)
               arr[i]=rand();
            printArray(arr, n);
            printf("Enter the element to be searched\n");
            scanf("%d",&ele);
            start = clock();
            f=Linear_search(arr,0, n-1,ele);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            if(f==-1)
            printf("Search unsuccessful.\n");
            else
            printf("Search successful. Element found at index %d\n",f);
            printf("TIME FOR FUNCTION EXECUTION is %f\n", cpu_time_used);
            break;
        }
        case 2:
        {
	        printf("Enter the size of the array\n");
        	scanf("%d",&n);
            int arr[n];
            printf("The elements of the array:\n");
            for(int i=0;i<n;i++)
            arr[i]=rand();
            Sort(arr, n);
            printf("Sorted array: \n");
            printArray(arr, n);
            printf("Enter the element to be searched\n");
            scanf("%d",&ele);
            start = clock();
            f=Binary_search(arr,0, n-1,ele);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            if(f==-1)
            printf("Search unsuccessful.\n");
            else
            printf("Search successful. Element found at index %d\n",f);
            printf("TIME FOR FUNCTION EXECUTION is %f\n", cpu_time_used);
            break;
        }
       }
        printf("1.Linear Search\n2.Binary Search\n3.Exit\n");
        scanf("%d",&choice);
    }
return 0;
}
