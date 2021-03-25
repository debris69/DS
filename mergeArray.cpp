#include <stdio.h>

void printArray(int arr[], int n){
  int i;
  for(i = 0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n" );
}

int main(){
  int a[] = {10, 21, 34, 45, 52};
  int b[] = {1, 20, 35, 41, 55};
  int asize = 5, bsize = 5;
  int i=0, j=0, k=0;
  int c[asize+bsize];

  printf("A: " );
  printArray(a, asize);
  printf("B: " );
  printArray(b, bsize);

  while(i<asize && j<bsize){
    if(a[i]<=b[j]){
      c[k] = a[i];
      k++; i++;
    }
    else{
      c[k] = b[j];
      k++; j++;
    }
  }
  while(i<asize){
    c[k] = a[i];
    k++; i++;
  }
  while(j<bsize){
    c[k] = b[j];
    k++; j++;
  }

  printf("C: " );
  printArray(c,k);
  return 0;
}
