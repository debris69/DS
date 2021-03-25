#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 200

typedef struct Stack{
  char arr[MAX][100];
  int top;
}Stack;

void push(Stack *s, char e[]){
  if(s->top == MAX-1)
    return;
  strcpy(s->arr[++s->top], e);
}

char* pop(Stack *s){
  if(s->top == -1){
    printf("STACK UNDERFLOW\n" );
    exit(0);
  }
  return s->arr[s->top--];
}

void display(Stack *s){
  int i;
  for(i = 0; i<= s->top; i++){
    printf("%s\t",s->arr[i]);
  }
}

void postfixToInfix(char exp[]){
  Stack infix;
  int i, len;
  char s[100], s1[100], s2[100];
  infix.top = -1;

  for(i=0; exp[i] != '\0'; i++){
    if(isalpha(exp[i])){
      s[0] = exp[i];
      s[1] = '\0';
      push(&infix, s);
    }
    else{
      strcpy(s1, pop(&infix));
      strcpy(s2, pop(&infix));
      s[0] = '(';
      s[1] = '\0';
      strcat(s, s2);
      len = strlen(s);
      s[len] = exp[i];
      s[len+1] = '\0';
      strcat(s, s1);
      strcat(s, ")");
      push(&infix, s);
    }
  }

  printf("Parenthesized Infix for %s : ", exp );
  display(&infix);
}

int main(){
  char exp[100];
  printf("Enter postfix expression: " );
  gets(exp);
  postfixToInfix(exp);
}
