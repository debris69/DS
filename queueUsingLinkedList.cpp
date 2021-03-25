#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node;

typedef struct Queue{
  Node *front, *rear;
}Queue;


Node* createNode(int x){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->data = x;
  temp->next = NULL;
  return temp;
}

Queue* createQueue(){
  Queue *q = (Queue*)malloc(sizeof(Queue));
  q->front = q->rear = NULL;
  return q;
}

void enqueue(Queue *q, int x){
  Node* temp = createNode(x);
  if(q->rear==NULL){
    q->front = q->rear = temp;
    return;
  }
  q->rear->next = temp;
  q->rear = temp;
}

void dequeue(Queue *q){
  if(q->front == NULL){
    printf("Empty Queue\n" );
    return;
  }

  Node *temp = q->front;
  q->front = q->front->next;

  if(q->front == NULL) q->rear = NULL;
  printf("Deleted-> %d\n",temp->data );
  free(temp);
}

void display(Queue *q){
  if(q->front == NULL) printf("Empty Queue\n" );
  else{
    Node *temp = q->front;
    printf("--------------------------------\n" );
    while(temp != NULL){
      printf("%d ",temp->data );
      temp = temp->next;
    }
    printf("\n--------------------------------\n" );
  }
}



int main(){
  Queue *q = createQueue();
  int ch, x;
  ch = 1;
  while(ch!=4){
    printf("Menu\n" );
    printf("1. Enqueue\n" );
    printf("2. Dequeue\n" );
    printf("3. Display\n" );
    printf("4. Exit\n" );
    printf("Enter choice -> " );
    scanf("%d",&ch );

    switch (ch) {
      case 1:
        printf("Enter value to push: " );
        scanf("%d",&x );
        enqueue(q, x);
      break;

      case 2:
        dequeue(q);
      break;

      case 3:
        display(q);
      break;

      case 4:
        exit(1);
      break;

      default:
      break;
    }
  }
  return 0;
}
