#include <stdio.h>
#include <stdlib.h>

int activity[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int start[] = {1, 2, 3, 4, 7, 8, 9, 9, 11, 12};
int finish[] = {3, 5, 4, 7, 10, 9, 11, 13, 12, 14};
int n = sizeof(activity)/sizeof(activity[0]);

void sortByFinish(){
  int temp, temp1, temp2;
  //sort arrays according to finish time:
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-i-1; j++){
      if(finish[j] > finish[j+1]){
        temp = finish[j], temp1 = start[j], temp2 = activity[j];
        finish[j] = finish[j+1], start[j] = start[j+1], activity[j] = activity[j+1];
        finish[j+1] = temp, start[j+1] = temp1, activity[j+1] = temp2;
      }
    }
  }
}

void printMaxActivities(){
  sortByFinish();

  printf("Following activities arr selected->  \n" );
  int i = 0;
  printf("A%d || Start-> %d || Finish-> %d\n",activity[i],start[i],finish[i] );

  for(int j = 1; j < n; j++){
    if(start[j] >= finish[i]){
      printf("A%d || Start-> %d || Finish-> %d\n",activity[j],start[j],finish[j]);
      i = j;
    }
  }

}

int main(){
  printMaxActivities();
  return 0;
}
