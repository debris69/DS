#include <stdio.h>
#include <stdlib.h>

int length;

void printArray(int arr[], int n){
  for(int i=0; i<n; i++)
    printf("%d ",arr[i] );
  printf("\n" );
}


void merge(int arr[], int l, int m, int r){
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for(int i=0; i<n1; i++)
    L[i] = arr[l + i];
  for(int j=0; j<n2; j++)
    R[j] = arr[m + 1 + j];

  int i =0;
  int j = 0;
  int k = l;

  while(i < n1 && j < n2){
    if(L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    }
    else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < n1){
    arr[k] = L[i];
    k++;
    i++;
  }

  while(j < n2){
    arr[k] = R[j];
    k++;
    j++;
  }

}

void mergeSort(int arr[], int l, int r){
  if(l>=r){
    return;
  }
  int m = (l+r)/2;
  mergeSort(arr,l,m);
  mergeSort(arr,m+1,r);
  merge(arr,l,m,r);
  printArray(arr,length);
}

int main(){
  int arr[] = {22, 134, 56, 1, 17};
  int n = 5;
  length = n;
  printf("Original Array: " );
  printArray(arr, n);
  mergeSort(arr, 0, n-1);
  printf("Sorted array: " );
  printArray(arr, n);
  return 0;
}
