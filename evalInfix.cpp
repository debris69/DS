#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

typedef struct Stack{
  float arr[MAX];
  int top;
}Stack;

void push(Stack *st, float f){
  if(st->top == MAX-1)
    return;
  st->arr[++st->top] = f;
}

float pop(Stack *st){
  if(st->top == -1){
    printf("STACK UNDERFLOW\n");
    exit(0);
  }
  return st->arr[st->top--];
}

int precedence(char op){
  if(op == '+' || op == '-')
    return 1;
  if(op == '*' || op == '/')
    return 2;
  if(op == '$')
    return 3;
  return 0;
}

void display(Stack *s){
  for(int i=0; i<=s->top; i++){
    printf("%f \t",s->arr[i] );
  }
}

float appOperation(float a, float b, char op){
  switch(op){
    case '+' : return a + b;
    case '-' : return a - b;
    case '*' : return a * b;
    case '/' : return a / b;
    case '$' : return pow(a,b);
  }
}

float evaluate(char exp[]){
  Stack values, ops;
  int i;

  values.top = -1;
  ops.top = -1;

  for(i = 0; exp[i] != '\0'; i++){
    if(exp[i] == '(')
      push(&ops, exp[i]);
    else if(isdigit(exp[i])){
      float v = 0;
      while(i < strlen(exp) && isdigit(exp[i])){
        v = (v*10) + (int)exp[i]-48;
        i++;
      }
      push(&values, v);
      i--;
    }
    else if(exp[i] == ')'){
      while(ops.top != -1 && ops.arr[ops.top] != '('){
        push(&values, appOperation(pop(&values), pop(&values), pop(&ops)));
      }
      ops.top--;
    }
    //operator
    else{
      while(ops.top != -1 && precedence(ops.arr[ops.top]) >= precedence(exp[i]))
        push(&values, appOperation(pop(&values), pop(&values), pop(&ops)));
      push(&ops, exp[i]);
    }
  }

  while(ops.top != -1)
    push(&values, appOperation(pop(&values), pop(&values), pop(&ops)));

  return pop(&values);
}

int main(){
  char exp[100];
  printf("Enter exp: ");
  gets(exp);
  printf("\nEval: %f\n",evaluate(exp));
}
