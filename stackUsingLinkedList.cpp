#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node;

Node *top = NULL;

void display(){
  Node *temp;
  if(top == NULL) printf("List is empty\n");
  else{
    temp = top;
    printf("----------\n" );
    while(temp != NULL){
      printf("%d \n",temp->data );
      temp = temp->next;
    }
    printf("----------\n" );
  }
}

void push(int x){
  Node *temp;
  temp = (Node*)malloc(sizeof(Node));
  temp->data = x;
  temp->next = top;
  top = temp;
}

void pop(){
  Node *temp;
  if(top == NULL) printf("List is empty\n" );
  else{
    temp = top;
    top = top->next;
    printf("Deleted-> %d\n",temp->data );
    free(temp);
  }
}

int main(){
  int ch, x;
  ch = 1;
  while(ch!=4){
    printf("Menu\n" );
    printf("1. Push\n" );
    printf("2. Pop\n" );
    printf("3. Display\n" );
    printf("4. Exit\n" );
    printf("Enter choice -> " );
    scanf("%d",&ch );

    switch (ch) {
      case 1:
        printf("Enter value to push: " );
        scanf("%d",&x );
        push(x);
      break;

      case 2:
        pop();
      break;

      case 3:
        display();
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
