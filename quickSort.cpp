#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MODE, LENGTH;

void printArray(int arr[], int n){
  for(int i=0; i<n; i++)
    printf("%d ", arr[i]);
  printf("\n" );
}

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high){
  int i, j, pivot;

  if(MODE == 1){
    pivot = arr[low];
    i = low;

    for(j = low+1; j<= high; j++){
      if(arr[j] < pivot){
        i++;
        swap(&arr[i], &arr[j]);
      }
    }

    swap(&arr[i], &arr[low]);
    printf("->  " );
    printArray(arr, LENGTH);
    return i;
  }

  else if(MODE == 2){
    pivot = arr[high];
    i = low-1;

    for(j = low; j<high; j++){
      if(arr[j] < pivot){
        i++;
        swap(&arr[i], &arr[j]);
      }
    }

    swap(&arr[i+1], &arr[high]);
    printf("->  " );
    printArray(arr, LENGTH);
    return i+1;
  }

  else{
    int random;

    srand(time(NULL));
    random = low + rand()%(high-low);
    swap(&arr[random], &arr[low]);

    pivot = arr[low];
    i = low;

    for(j = low+1; j<high; j++){
      if(arr[j] < pivot){
        i++;
        swap(&arr[i], &arr[j]);
      }
    }

    swap(&arr[i], &arr[low]);
    printf("->  " );
    printArray(arr, LENGTH);
    return i;
  }
}

void quickSort(int arr[], int low, int high){
  if(low < high){
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }
}

int main(){
  int arr[] = {5, 4, 3, 2, 1};
  int n = 5;
  LENGTH = n;

  int ch;

  printf("Menu: \n" );
  printf("1. Pivot - First Element\n");
  printf("2. Pivot - Last Element\n");
  printf("3. Pivot - Random Element\n");
  printf("Choice: ");
  scanf("%d", &ch);
  MODE = ch;

  printf("Unsorted array->  ");
  printArray(arr, n);

  switch(ch){
    case 1:
      printf("Quick sort using Low: \n");
      quickSort(arr, 0, n-1);
    break;

    case 2:
      printf("Quick sort using High: \n");
      quickSort(arr, 0, n-1);
    break;

    case 3:
      printf("Quick sort using random: \n");
      quickSort(arr, 0, n-1);
    break;

    default:
      printf("invalid choice :(\n");
      return 0;
    break;
  }

  printf("Sorted array->  ");
  printArray(arr, n);

  return 0;
}
