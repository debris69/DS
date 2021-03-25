#include <stdio.h>

int count = 0;

void towerOfHanoi(int n, char beg, char aux, char end){
  count++;
  if(n==1){
    printf("Move disk 1 from peg %c to %c\n",beg,end );
    return;
  }
  towerOfHanoi(n-1, beg, end, aux);
  printf("Move disk %d from peg %c to %c\n",n,beg,end );
  towerOfHanoi(n-1, aux, beg, end);
}

int main(){
  int n;
  printf("Enter n: ");
  scanf("%d",&n );
  towerOfHanoi(n,'A','B','C');
  printf("Total Moves: %d\n", count);
  return 0;
}
