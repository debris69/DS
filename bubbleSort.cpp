#include <stdio.h>
#include <string.h>
#define MAX 100

int count = 0;
int countchr = 0;

void printArray(int arr[], int n){
  int i;
  for(i=0; i<n; i++){
    printf("%d\t",arr[i] );
  }
  printf("\n");
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

void bubbleSortChar(char arr[], int n){
  int i, j;
  char temp;
  int flag;
  for(i=0; i<n-1; i++){
    flag = 0;
    for(j=0; j<n-i-1; j++){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        countchr++;
        flag=1;
      }
    }
    if(flag==1) printf("%s\n",arr );
  }
}

void bubblesortStrings(char arr[][MAX], int n){
  char temp[MAX];
  int flag;
  for(int i=0; i<n-1; i++){
    flag=0;
    for(int j=0; j<n-i-1; j++){
      if(strcmp(arr[j],arr[j+1]) > 0){
        strcpy(temp,arr[j]);
        strcpy(arr[j], arr[j+1]);
        strcpy(arr[j+1],temp);
        flag=1;
      }
    }
    if(flag==1){
      for(int z=0; z<n; z++){
        printf("%s  ", arr[z]);
      }
      printf("\n" );
    }
  }
}

int main(){
  int arr[] = {21, 4, 16, 14, 9, 2};
  char string[] = "bcafed";
  int n1 = strlen(string);
  int n = 6;
  char array[][MAX] = {"Kolkata","Delhi","Karnataka","Mumbai","Patna"};
  int n2 = 5;

  printf("Unsorted array: ");
  printArray(arr,n);
  bubbleSort(arr,n);
  printf("Sorted array: " );
  printArray(arr,n);
  printf("Total interchanges: %d\n\n", count);

  printf("Unsorted char array: ");
  printf("%s\n",string );
  bubbleSortChar(string,n1);
  printf("Sorted array: " );
  printf("%s\n",string );
  printf("Total interchanges: %d\n\n", countchr);

  printf("Unsorted string array: ");
  for(int i=0; i<n; i++){
    printf("%s  ", array[i]);
  }
  printf("\n");
  bubblesortStrings(array,n2);
  printf("Sorted array: " );
  for(int i=0; i<n; i++){
    printf("%s  ", array[i]);
  }
  return 0;
}
