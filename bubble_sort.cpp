#include <stdio.h>
#include <conio.h>

int count=0;

void printArray(int arr[], int size){
  int i;
  for(i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
    printf("\n\n");
}

void bubbleSort(int arr[], int n){
  int i, j;
  int flag;
  int temp;
  for(i=0; i<n-1; i++){
    flag=0;
    for(j=0; j<n-i-1; j++){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        count++;
        flag=1;
      }
    }
    if(flag==1) printArray(arr, n);
  }
}

int main(){
  int arr[] = {21, 4, 16, 14, 9, 2};
  int n = 6;
  printf("Original array : ");
  printArray(arr, n);
  bubbleSort(arr, n);
  printf("Sorted array : ");
  printArray(arr, n);
  printf("Total interchanges: %d\n\n", count);
  return 0;
}
