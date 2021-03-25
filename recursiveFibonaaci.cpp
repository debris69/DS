#include <stdio.h>

int fibonaaci(int n){
  if(n == 0){
    return 0;
  }
  else if(n == 1){
    return 1;
  }
  else{
      return (fibonaaci(n-1) + fibonaaci(n-2));
  }
}

int main(){
  int n;
  printf("Enter n:" );
  scanf("%d",&n );

  for(int i=0; i<n; i++){
      printf("%d \t",fibonaaci(i) );
  }
  return 0;
}
