#include <stdio.h>
#include <stdlib.h>

int n = 8;
int M = 50;
int p[] = {100, 120, 200, 150, 80, 170, 180, 90};
int w[] = {10, 15, 16, 8, 5, 20, 25, 12};

void fillKnapsack(){
  int currentW = M;
  float total;
  int i, max;
  int used[10] = {0};

  printf("Total Space: %dKg\n",M );

  while(currentW > 0){
    max = -1;
    for(i=0; i<n; ++i){
      if((used[i]==0) && ((max == -1) || ((float)p[i]/w[i] > (float)p[max]/w[max])))
        max = i;
    }
    used[max] = 1;
    currentW -= w[max];
    total += p[max];
    if(currentW >= 0)
      printf("Added obj %d (Rs %d, %dKg) completely in the bag. Space left: %d\n", max+1, p[max], w[max], currentW );
    else{
      printf("Added %d%% (Rs %d, %dKg) of object %d in the bag.\n",(int)((1+ (float)currentW/w[max])*100), p[max], w[max], max+1  );
      total -= p[max];
      total += (1 + (float)currentW/w[max]) * p[max];
    }
  }

  printf("Bag Filled. Total worth: Rs. %.2f\n", total);
}

int main(){
  fillKnapsack();
  return 0;
}
