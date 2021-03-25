#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

int length, mode;

void printArray(int arr[], int n){
  for(int i = 0; i < n; i++){
  printf("%d ",arr[i]);
}
printf("\n");
}

void quickSort(int arr[], int first, int last){
  int i, j, pivot, temp;
  if(first < last){
    if(mode == 1) pivot = first;
    else if(mode == 2) pivot = last;

    i = first;
    j = last;

    while(i < j){
      while(arr[i] <= arr[pivot] && i < last){
        i++;
      }
      while(arr[j] > arr[pivot]){
        j--;
      }
      if(i < j){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    printArray(arr, length);
    quickSort(arr, first, j-1);
    quickSort(arr, j+1, last);
  }
}
int main(){
  int s, arr[100];
  int ch;
  printf("number of elements to be entered in the array : ");
  scanf("%d", &s);
  length = s;
  printf("Enter %d elements : ", s);
  for(int i=0; i<s; i++){
    scanf("%d",&arr[i]);
  }
  printArray(arr, s);
  printf("Menu:\n1.Pivot -> First\n2.Pivot -> Last\nEnter choice: ");
  scanf("%d",&ch);
  mode = ch;
  switch(ch){
    case 1:
      printf("Pivot as First Element: \n");
      quickSort(arr, 0, s-1);
    break;

    case 2:
      printf("Pivot as Last Element: \n");
      quickSort(arr, 0, s-1);
    break;

    default:
      return 0;
    break;
  }

  printf("Order of sorted elements : ");
  printArray(arr, s);
  return 0;
}
