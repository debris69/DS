#include<stdio.h>
#include<conio.h>

#define MAX 10

typedef struct Stack{
  int top;
  int items[MAX];
}Stack;

void push(Stack *p, int value){
  if(p->top<MAX-1){
    p->items[p->top+1] = value;
    p->top += 1;
    printf("Pushed new value!! -> %d\n", p->items[p->top] );
    printf("Current stack capacity: %d/%d\n",p->top+1,MAX);
  }
  else{
    printf("Stack Overflow!!\n" );
    printf("Current stack capacity: %d/%d\n",p->top+1,MAX);
  }
}

void pop(Stack *p){
  if(p->top==-1){
    printf("Stack Underflow!!\n" );
    printf("Current stack capacity: %d/%d\n",p->top+1,MAX);
  }
  else{
    printf("Popped value!! -> %d\n", p->items[p->top] );
    p->top -= 1;
    printf("Current stack capacity: %d/%d\n",p->top+1,MAX);
  }
}

void view(Stack *p){
  printf("----------------------------------------\n");
  for(int i=0; i<=p->top; i++){
    printf("%d \t",p->items[i] );
  }
  printf("\nCurrent stack capacity: %d/%d\n",p->top+1,MAX);
  printf("----------------------------------------\n");
}

int main(){
  Stack s;
  s.top = -1;
  int value;
  int sw=0;
  while(sw!=4){
    printf("----------------------------------------\n");
    printf("Menu: \n");
    printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. Check Stack \n");
    printf("4. Exit \n");
    printf("Enter your choice: ");
    scanf("%d",&sw );
    printf("----------------------------------------\n");

    switch (sw) {
      case 1:
        printf("Enter value: ");
        scanf("%d",&value);
        if(value!=0){
          push(&s, value);
        }
        else{
          printf("can't be 0!!\n");
        }
      break;

      case 2:
        pop(&s);
      break;

      case 3:
        view(&s);
      break;

      default:

      break;
    }
  }


  return 0;
}
