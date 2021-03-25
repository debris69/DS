#include <stdlib.h>
#include <stdio.h>
#define MAX 100

typedef struct File{
  char fname[MAX];
  int size;
}File;

typedef struct Queue{
  int front, rear;
  File arr[MAX];
}Queue;

void insert(Queue *q, File f){
  if(q->rear == MAX-1){
    printf("Queue Overflow\n");
    return;
  }
  if(q->front == 1 && q->rear == 0){
    q->front = 0;
    q->arr[q->front] = f;
  }
  else{
    q->arr[++q->rear] = f;
  }
}

File getSmallest(Queue *q){
  int pos, i;
  File f;

  f.size = -1;
  sprintf(f.fname, "NULL");

  if(q->front > q->rear){
    return f;
  }
  else{
    pos = q->front;
    for(i = q->front+1; i <= q->rear; i++){
      if(q->arr[i].size < q->arr[pos].size){
        pos = i;
      }
    }
    f = q->arr[pos];
    i = pos;

    while(i != q->rear){
      q->arr[i] = q->arr[i+1];
      i++;
    }
    q->rear--;
    return f;
  }
}

void showQueue(Queue *q){
  for(int i = q->front; i <= q->rear; i++){
    printf("%s -> %d \n",q->arr[i].fname, q->arr[i].size );
  }
}

void optimalMerge(File files[], int n){
  Queue q;
  int i, opr, nf_count;
  File f1, f2, nf;

  q.front = 0;
  q.rear = -1;
  nf_count = 0;

  for(i=0; i<n; i++){
    insert(&q, files[i]);
  }

  printf("Given Files: \n" );
  showQueue(&q);
  opr = 0;

  while(1){
    f1 = getSmallest(&q);
    f2 = getSmallest(&q);


    if(f1.size == -1 || f2.size == -1) break;

    printf("\nMerging files -: %s and %s -: \n%d + %d = %d",f1.fname, f2.fname, f1.size, f2.size, f1.size+f2.size );
    sprintf(nf.fname, "New File %d", ++nf_count);
    nf.size = f1.size + f2.size;
    opr += f1.size+f2.size;
    insert(&q, nf);
    printf("\nFile created after merging -: Name: %s  || Size: %d \n",nf.fname, nf.size );
  }
  printf("\ntotal cost: %d", opr);
}

int main(){
  File files[MAX];
  int n;

  printf("Enter no. of files(MAX %d): ",MAX );
  scanf("%d",&n );

  for(int i=0; i<n; i++){
    printf("Enter size of File %d: ",i+1 );
    scanf("%d", &files[i].size );
    sprintf(files[i].fname, "File %d", i+1);
  }

  optimalMerge(files,n);
  return 0;
}
