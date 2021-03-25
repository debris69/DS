#include<stdio.h>

void printArray(int arr[], int n){
  int i;
  for(i=0; i<n; i++){
    printf("%d\t",arr[i] );
  }
  printf("\n");
}

void selectionSort(int arr[], int n){
  int i, j, min, temp;

  for(i=0; i<n-1; i++){
    min = i;
    for(j=i+1; j<n; j++){
      if(arr[j]<arr[min])
        min =  j;
    }
    temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
    printArray(arr, n);
  }
}

int main(){
  int arr[] = {20, 30, 10, 14, 56};
  int n = 5;
  printf("Unsorted array: ");
  printArray(arr,n);
  selectionSort(arr,n);
  printf("Sorted array: " );
  printArray(arr,n);
  return 0;
}
