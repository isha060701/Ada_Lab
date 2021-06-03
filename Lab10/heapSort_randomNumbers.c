#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  void heapify(int arr[], int n, int i) 
  {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
    {
         heapify(arr, n, i);
    }
    printf("The max heap generated:\n");
    printArray(arr, n);
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      heapify(arr, i, 0);
    }
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
    arr[i]=rand()%100;
    printArray(arr, n);
    printf("\n");
    start = clock();
    heapSort(arr, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("\n");
    printf("TIME FOR FUNCTION EXECUTION is %f", cpu_time_used);
    return 0;
 
  }
