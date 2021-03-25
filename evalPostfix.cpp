#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>

typedef struct Stack{
  int top;
  unsigned capacity;
  float* values;
}Stack;

Stack* createStack(unsigned capacity){
  Stack *st;
  st = (Stack*)malloc(sizeof(Stack));
  st->top = -1;
  st->capacity = capacity;
  st->values = (float*)malloc(st->capacity*sizeof(float));
  return st;
}

float pop(Stack* st){
  if(st->top!=-1)
    return st->values[st->top--];
  return '$';
}

void push(Stack* st, float op){
  st->values[++st->top] = op;
}

float evalPostfix(char *exp){
  Stack *st = createStack(strlen(exp));

  for(int i=0; exp[i]; ++i){
    if(isdigit(exp[i]))
      push(st, (float)(exp[i] - '0'));
    else{
      float value1 = pop(st);
      float value2 = pop(st);
      switch(exp[i]){
        case '+':
          push(st, value2 + value1);
        break;
        case '-':
          push(st, value2 - value1);
        break;
        case '*':
          push(st, value2 * value1);
        break;
        case '/':
          push(st, value2 / value1);
        break;
      }
    }
  }

  return pop(st);
}

int main(){
  char expression[100];
  printf("Enter post-fix expression: " );
  scanf("%[^\n]%*c", expression );
  printf("Eval: %f\n",evalPostfix(expression) );
  return 0;
}
