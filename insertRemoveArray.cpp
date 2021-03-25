#include <stdio.h>
#include <conio.h>
#define MAX 100

void printArray(int arr[], int n){
  int i;
  for(i = 0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n" );
}

int searchElement(int arr[], int el, int n){
  int i;
  for(i=0; i<n; i++){
    if(arr[i]==el){
      return i;
    }
  }
  return -1;
}

void insertElement(int arr[], int value, int aval, int n){
  for(int i=n-1; i>=aval; i--){
    arr[i] = arr[i-1];
  }
  arr[aval-1] = value;
}

void removeElement(int arr[], int value, int n){
  for(int i=value-1; i<n; i++){
    arr[i] = arr[i+1];
  }
}

int main(){
  int arr[MAX] = {0};
  int size, nval, pos, i, rval;
  int apos, rpos;
  int ch=1;
  size = 5;
  for(i = 0; i<size; i++){
    arr[i] = i+1;
  }
  printArray(arr,size);


  while(ch!=3){
    printf("Menu: \n1. Insert Element \n2. Remove Element \n3. Exit\nEnter choice: ");
    scanf("%d", &ch);
    switch(ch){
      case 1:
        if(size == MAX){
          printf("Maxed out array\n" );
          break;
        }
        printf("Enter new value to insert: " );
        scanf("%d",&nval );
        printf("insert %d after: ",nval);
        scanf("%d",&pos);
        apos = searchElement(arr,pos,size);
        if(apos!=-1){
          size++;
          insertElement(arr,nval,apos+2,size);
          printArray(arr,size);
        }
        else{
          printf("%d not found in array\n",pos );
        }
      break;

      case 2:
        if(size==0){
          printf("Empty array\n" );
          break;
        }
        printf("Enter value to remove: ");
        scanf("%d",&rval);
        rpos = searchElement(arr, rval, size);
        if(rpos!=-1){
          removeElement(arr, rpos+1, size);
          size--;
          printArray(arr,size);
        }
        else{
          printf("%d not found in array\n",rval );
        }
      break;

      case 3:

      break;

      default:
        printf("Invalid input\n" );
      break;
    }
  }

  return 0;

}
