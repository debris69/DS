#include <stdio.h>
#include <conio.h>

#define MAX 5

typedef struct Dequeue{
  int left, right;
  int items[MAX];
}Dequeue;

int isFull(Dequeue *q){
  if((q->left == q->right+1) ||
  (q->left == 0 && q->right == MAX -1))
    return 1;
  return 0;
}

int isEmpty(Dequeue *q){
  if(q->left == -1)
    return 1;
  return 0;
}

void insertLeft(Dequeue *q, int x){
  if(isFull(q)){
    printf("Overflow\n");
    return;
  }
  if(q->left==-1)
    q->left = q->right = 0;
  else if(q->left==0)
    q->left = MAX-1;
  else
    q->left--;

  q->items[q->left] = x;

  printf("Inserted: %d\n",q->items[q->left] );

}

void insertRight(Dequeue *q, int x){
  if(isFull(q)){
    printf("Overflow\n");
    return;
  }
  if(q->left == -1)
    q->left = q->right = 0;
  else if(q->right == MAX-1)
    q->right = 0;
  else
    q->right++;
  q->items[q->right] = x;

  printf("Inserted: %d\n",q->items[q->right] );
}

void deleteLeft(Dequeue *q){
  if(isEmpty(q)){
    printf("Underflow\n");
    return;
  }
  if(q->left==q->right){
    printf("Removed: %d\n",q->items[q->left] );
    q->left = q->right = -1;
  }
  else{
    if(q->left==MAX-1){
      printf("Removed: %d\n",q->items[q->left] );
      q->left = 0;
    }
    else{
      printf("Removed: %d\n",q->items[q->left] );
      q->left++;
    }
  }
}

void deleteRight(Dequeue *q){
  if(isEmpty(q)){
    printf("Underflow\n");
    return;
  }
  if(q->left == q->right){
    printf("Removed: %d\n",q->items[q->right] );
    q->left = q->right = -1;
  }
  else if(q->right == 0){
    printf("Removed: %d\n",q->items[q->right] );
    q->right = MAX-1;
  }
  else{
    printf("Removed: %d\n",q->items[q->right--] );
  }
}

void queueStatus(Dequeue *q){
  printf("left-> %d , right-> %d\n",
  q->items[q->left], q->items[q->right] );
}

void display(Dequeue *q){
  int i;
  if(isEmpty(q))
    printf("Queue Underflow\n" );
  else{
    for(i = q->left; i != q->right; i = (i+1) % MAX){
      printf("%d \t",q->items[i] );
    }
    printf("%d \t\n",q->items[i] );
  }
}

int main(){
  Dequeue q;
  q.left = -1;
  q.right = 0;

  int x;
  int sw = 0;

  while(sw!=6){
    printf("Menu:\n1.Insert left\n2.Insert right\n3.Delete left\n4.Delete right\n5.Display\n6.Exit\n\nEnter your choice:" );
    scanf("%d",&sw );
    switch(sw){
      case 1:
        printf("Enter value: " );
        scanf("%d",&x);
        insertLeft(&q,x);
        queueStatus(&q);
      break;
      case 2:
        printf("Enter value: " );
        scanf("%d",&x);
        insertRight(&q,x);
        queueStatus(&q);
      break;
      case 3:
        deleteLeft(&q);
        queueStatus(&q);
      break;
      case 4:
        deleteRight(&q);
        queueStatus(&q);
      break;
      case 5:
        display(&q);
      break;
    }
  }

  return 0;
}
