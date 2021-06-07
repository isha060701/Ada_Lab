#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
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
    quickSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("\n");
    printf("TIME FOR FUNCTION EXECUTION is %f", cpu_time_used);
    return 0;
 
}
