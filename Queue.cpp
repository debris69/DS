#include <stdio.h>
#include <conio.h>

#define MAX 10

typedef struct Queue{
  int front, rear;
  int items[MAX];
}Queue;

int isFull(Queue *q){
  if((q->front == q->rear+1) || (q->front == 0 && q->rear == MAX -1))
    return 1;
  return 0;
}

int isEmpty(Queue *q){
  if(q->front == -1)
    return 1;
  return 0;
}

void enQueue(Queue *q, int x){
  if(isFull(q))
    printf("Queue Overflow\n");
  else{
    if(q->front == -1)
      q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = x;
    printf("Inserted -> %d\n", q->items[q->rear]);
  }
}

void deQueue(Queue *q){
  if(isEmpty(q))
    printf("Queue Underflow\n" );
  else{
    int x = q->items[q->front];
    if(q->front == q->rear)
      q->front = q->rear = -1;
    else
      q->front = (q->front + 1) % MAX;
    printf("Deleted -> %d\n", x );
  }
}

void display(Queue *q){
  int i;
  if(isEmpty(q))
    printf("Queue Underflow\n" );
  else{
    for(i = q->front; i != q->rear; i = (i+1) % MAX){
      printf("%d \t",q->items[i] );
    }
    printf("%d \t\n",q->items[i] );
  }
}

int main(){
  Queue q;
  q.front = q.rear = -1;
  int x;
  int sw = 0;
  while(sw!=4){
    printf("Menu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
    scanf("%d",&sw );
    printf("-------------------------\n");
    switch(sw){
      case 1:
        printf("Enter value: ");
        scanf("%d",&x);
        enQueue(&q, x);
      break;
      case 2:
        deQueue(&q);
      break;
      case 3:
        display(&q);
      break;
      default:
      break;
    }
  }
  return 0;
}
