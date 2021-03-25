#include <stdio.h>

void reverse(char *c){
  if(*c){
    reverse(c+1);
    printf("%c",*c );
  }
}

int main(){
  char str[] = "Hello World";
  reverse(str);
  return 0;
}
