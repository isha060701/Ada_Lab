#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int arr[], int p, int q, int r) 
{

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
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
    arr[i]= rand()%1000;
    printArray(arr, n);
    printf("\n");
    start = clock();
    mergeSort(arr, 0, n-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("\n");
    printf("TIME FOR FUNCTION EXECUTION is %f", cpu_time_used);
    return 0;
}
