#include <stdio.h>  
#include <time.h>
#include <stdlib.h>

int minIndex(int a[], int i, int j)
{
    if (i == j)
        return i;
  
    int k = minIndex(a, i + 1, j);
  
    return (a[i] < a[k])? i : k;
}
  

void selectionSort(int a[], int n, int index)
{
    if (index == n)
       return;
  
    int k = minIndex(a, index, n-1);
  
    if (k != index)
    {
        int temp=a[k];
        a[k]=a[index];
        a[index]=temp;
    }
  
    selectionSort(a, n, index + 1);
}
  

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
  

int main()
{
	int n;
	clock_t start, end;
    double cpu_time_used;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
    int arr[n];
    printf("The elements of the array:\n");
    for(int i=0;i<n;i++)
    arr[i]=rand()%1000;
    printArray(arr, n);
    printf("\n");
    start = clock();
    selectionSort(arr, n,0);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("\n");
    printf("TIME FOR FUNCTION EXECUTION is %f", cpu_time_used);
    return 0;
}
