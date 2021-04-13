#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int n){
  int m[n][n];
  int i, j, k, l, q;

  //cost = 0, when multiplying one matrix
  for(i=1; i<n; i++)
    m[i][i] = 0;

  //l = chain length
  for(l=2; l<n; l++){
    for(i=1; i<n-l+1; i++){
      j = i+l-1;
      m[i][j] = INT_MAX;
      for (k=i; k<=j-1; k++){
        //q = cost/operations
        q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
        if(q<m[i][j])
          m[i][j] = q;
      }
    }
  }


  return m[1][n-1];
}

int main(){
  int arr[] = {10, 5, 8, 10, 10}; //
  printf("Minimum operation is %d\n",matrixChainOrder(arr, sizeof(arr)/sizeof(arr[0])) );
  return 0;
}
