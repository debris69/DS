#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define max(a,b) (((a)>(b))?(a):(b))

void knapsackByDP(int W[], int V[], int M, int n){
  int B[n+1][M+1];
  int i,j;
  printf("Total Space: %d\n\n",M );
  int totalSpace = M;

  for(i=0; i<=n; i++){
    for(j=0; j<=M; j++){
      if(i==0 || j==0)
        B[i][j] = 0;
      else if(W[i-1] <= j)
        B[i][j] = max(V[i-1]+B[i-1][j-W[i-1]], B[i-1][j]);
      else
        B[i][j] = B[i-1][j];
    }
  }

  for(i=0; i<=n; i++){
    for(j=0; j<=M; j++){
      printf("%d ", B[i][j] );
    }
    printf("\n" );
  }

  printf("Max Value: %d\n",B[n][M] );
  printf("Selected Objects: \n" );
  while(n != 0){
    if(B[n][M] != B[n-1][M]){
      printf("Package %d with W = %d, and Value = %d\n",n,W[n-1],V[n-1] );
      M = M - W[n-1];
    }
    n--;
  }
  printf("Filled: %d/%d\n",totalSpace-M, totalSpace );
}

int main(){
  int W[] = {2, 11, 22, 15};
  int V[] = {11, 21, 31, 33};
  int M = 40;
  int n = 4;
  knapsackByDP(W,V,M,n);
  //_getch();
  return 0;
}
