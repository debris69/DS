#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack{
  int top;
  int arr[MAX];
}Stack;

Stack* createStack(){
  Stack *st;
  st = (Stack*)malloc(sizeof(Stack));
  st->top = -1;
  return st;
}

int isEmpty(Stack* st){
  return st->top == -1;
}

//peek the top value
char peek(Stack* st){
  return st->arr[st->top];
}

char pop(Stack* st){
  if(!isEmpty(st))
    return st->arr[st->top--];
  return '$';
}

void push(Stack* st, char op){
  st->arr[++st->top] = op;
}

//check operand
int isOperand(char ch){
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

//check precedence
int prec(char ch){
  switch(ch){
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
  }
  return -1;
}

//accept infix -> convert infix -> print postfix
void infixToPostfix(char *exp){
  int i, k;
  Stack *st = createStack();

  for(i=0, k=-1; exp[i]; ++i){
    //if scanned char is operand
    if(isOperand(exp[i]))
      exp[++k] = exp[i];
    //if scanned char is (
    else if(exp[i] == '(')
      push(st, exp[i]);
    //if scanned char is ) , pop and output untill ( is found
    else if(exp[i] == ')'){
      while(!isEmpty(st) && peek(st) != '(')
        exp[++k] = pop(st);
      if(!isEmpty(st) && peek(st) != '('){
        printf("Invalid Expression\n" );
        return;
      }
      else{
        pop(st);
      }
    }
    //an operator is found
    else{
      while(!isEmpty(st) && prec(exp[i]) <= prec(peek(st)))
        exp[++k] = pop(st);
      push(st, exp[i]);
    }
  }

  //pop all elements
  while(!isEmpty(st))
    exp[++k] = pop(st);
  exp[++k] = '\0';
  printf("Postfix Expression: %s\n",exp );

}

int main(){
  char expression[100];
  printf("Enter infix expression: " );
  scanf("%[^\n]%*c", expression );
  infixToPostfix(expression);
  return 0;
}
