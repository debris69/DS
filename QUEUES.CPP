#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Queue{
  int items[MAX];
  int front, rear;
}Queue;

void enqueue(Queue *q, int x){
  int temp;
  //1st element check
  if(q->front == MAX-1 && q->rear == MAX-1){
    q->front = 0;
    q->rear = 0;
    q->items[q->rear] = x;
    return;
  }
  if(q->rear == MAX-1){
    temp = 0;
  }
  else{
    temp = q->rear+1;
  }
  if(q->front == temp){
    printf("Queue Overflow\n");
    return;
  }
  q->rear = temp;
  q->items[q->rear] = x;
  return;
}

int dequeue(Queue *q){
  int x;
  if(q->front == q->rear){
    printf("Queue Underflow\n" );
    exit(0);
  }
  if(q->front == MAX-1){
    x = q->items[q->front];
    q->front = 0;
  }
  else{
    x = q->items[q->front];
    q->front++;
  }
  return x;
}


void display(Queue *q){
  int i;
  for(i = q->front; i != q->rear; i = (i+1) % MAX){
    printf("%d \t",q->items[i] );
  }
  printf("%d \t\n",q->items[i] );
}

void queueStatus(Queue *q){
  printf("Front -> %d, Rear -> %d\n",
  q->items[q->front], q->items[q->rear] );
}

int main(){
  Queue q;
  q.front = MAX-1;
  q.rear = MAX-1;

  int ch=0;
  int x;

  while(ch!=4){
    printf("Menu:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
    scanf("%d",&ch );
    switch (ch) {
      case 1:
        printf("Enter element: " );
        scanf("%d",&x );
        enqueue(&q, x);
        queueStatus(&q);
      break;
      case 2:
        printf("Removed-> %d\n", dequeue(&q));
        queueStatus(&q);
      break;
      case 3:
        display(&q);
      break;
    }
  }

  return 0;
}
