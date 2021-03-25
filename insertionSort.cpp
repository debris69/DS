#include <stdio.h>
#include <conio.h>

void printArray(int arr[], int n){
  int i;
  for(i = 0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n" );
}

void insertionSort(int arr[], int n){
  int i, key, j;
  int count = 0;
  for(i = 1; i<n; i++){
    key = arr[i];
    j = i-1;

    while(j >= 0 && arr[j] > key){
      arr[j+1] = arr[j];
      j = j-1;
      count++;
    }

    arr[j+1] = key;
    printArray(arr, n);
  }
  printf("Total Interchanges: %d\n",count );
}


int main(){
  int arr[] = {10, 9, 12, 8, 11};
  int n = 5;
  printf("Original array: ");
  printArray(arr, n);
  insertionSort(arr, n);


  return 0;
}
