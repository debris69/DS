#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Stack{
  int items[MAX];
  int top;
}Stack;

void push(Stack *s, int item){
  if(s->top == MAX-1){
    printf("Stack is full.. \n");
  }
  else{
    s->top++;
    s->items[s->top] = item;
    printf("pushed -> %d\n",s->items[s->top] );
  }
}

int pop(Stack *s){
  if(s->top == -1){
    printf("Stack is empty.. \n");
    exit(0);
  }
  else
    return s->items[s->top--];
}

void display(Stack *s){
  printf("Stack: ");
  for(int i = 0; i <= s->top; i++){
    printf("%d ", s->items[i]);
  }
  printf("\n");
}

int main(){
  int ch;
  int x;
  Stack s;
  s.top = -1;
  while(ch!=4){
    printf("1. push \n");
    printf("2. pop \n");
    printf("3. display \n");
    printf("4. exit \n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch){
      case 1:
      printf("Enter element: ");
      scanf("%d",&x );
      push(&s, x);
      break;

      case 2:
      printf("popped-> %d\n",pop(&s));
      break;

      case 3:
      display(&s);
      break;

      case 4:
      exit(1);
      break;

      default:
      printf("Wrong choice!! \n");
    }
  }
}
