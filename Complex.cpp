#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//define a struct Complex -> int real, int img
typedef struct Complex{
  int real;
  int img;
}COMPLEX;

//function 1: input value
COMPLEX * getComplex(){
  COMPLEX *o;
  o = (COMPLEX *)malloc(sizeof(COMPLEX));
  printf("Enter real part: ");
  scanf("%d", &o->real);
  printf("Enter img part: ");
  scanf("%d", &o->img);
  return o;
}

//function 1.5: complex * as parameter
void getComplex(COMPLEX *o){
  printf("Enter real part: ");
  scanf("%d", &o->real);
  printf("Enter img part: ");
  scanf("%d", &o->img);
}

//function 2: show value
void showComplex(COMPLEX *cp){
  printf("%d + %di\n", cp->real,cp->img);
}

//function 3: add two complex
COMPLEX * addComplex(COMPLEX *a, COMPLEX *b){
  COMPLEX *o;
  o = (COMPLEX *)malloc(sizeof(COMPLEX));
  o->real = a->real + b->real;
  o->img = a->img + b->img;
  return o;
}

int main(){

  COMPLEX a,b;
  COMPLEX *c;

  printf("Get A:\n");
  getComplex(&a);
  printf("A:  ");
  showComplex(&a);

  printf("Get B:\n");
  getComplex(&b);
  printf("B:  ");
  showComplex(&b);

  printf("C = A+B: ");
  c = addComplex(&a,&b);
  showComplex(c);

  getch();
  return 0;
}
