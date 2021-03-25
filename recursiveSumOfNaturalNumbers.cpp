#include <stdio.h>

int sumOfNaturalNumber(int n){
  if(n!=0){
    return n + sumOfNaturalNumber(n-1);
  }
  else{
    return n;
  }
}

int main(){
  int n;
  printf("Enter n: ");
  scanf("%d",&n );
  printf("Sum of %d natural numbers: %d\n",n, sumOfNaturalNumber(n) );
  return 0;
}
