#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//define a struct RealType -> int left, int right
typedef struct RealType{
  int left;
  int right;
}RealType;

//function 1: input string, get RealType
void getRealType(RealType *r){
  printf("Enter left: ");
  scanf("%d", &r->left);
  printf("Enter right: ");
  scanf("%d", &r->right);
}

//function 2: show realtype in format
void showRealType(RealType *r){
  printf("Real Number: %d.%d\n",r->left,r->right );
}

//get length
int getLength(int num){
  int i=0;
  while(num >= 1){
    num = num/10;
    i++;
  }
  return i;
}

//get Length in tens
int getLengthInTen(int num){
  int i=1;
  while(num>=1){
    i = i*10;
    num = num/10;
  }
  return i;
}

//sum function
RealType addRealType(RealType *a, RealType *b){
  RealType out;

  int aLength = getLength(a->right);
  int bLength = getLength(b->right);

  if(aLength > bLength){
    int i = 0;
    while (i < (aLength-bLength)) {
      b->right = b->right * 10;
      i++;
    }
  }
  else if(bLength > aLength){
    int i = 0;
    while (i < (bLength-aLength)) {
      a->right = a->right * 10;
      i++;
    }
  }

  out.left = a->left + b->left;
  if(a->left<0 || b->left<0){
    out.right = a->right - b->right;
  }
  else{
    out.right = a->right + b->right;
  }


  if(out.right<0){
    out.right = getLengthInTen(-out.right) + out.right;
    out.left += 1;
  }
  return out;
}

//sum function
RealType subRealType(RealType *a, RealType *b){
  RealType out;

  int aLength = getLength(a->right);
  int bLength = getLength(b->right);

  if(aLength > bLength){
    int i = 0;
    while (i < (aLength-bLength)) {
      b->right = b->right * 10;
      i++;
    }
  }
  else if(bLength > aLength){
    int i = 0;
    while (i < (bLength-aLength)) {
      a->right = a->right * 10;
      i++;
    }
  }

  out.left = a->left - b->left;
  out.right = a->right - b->right;


  if(out.right<0){
    out.right = getLengthInTen(-out.right) + out.right;
    out.left -= 1;
  }
  return out;
}

RealType mulRealType(RealType *a, RealType *b){
  RealType out;
  int val = (b->right*a->right)+(10*b->right*a->left) + 10*((b->left*a->right)+(10*b->left*a->left));
  out.left = val/100;
  out.right = val%100;
  return out;
}

int main(){

  RealType a, b, c;
  int sw;

  printf("   A \n");
  getRealType(&a);
  showRealType(&a);

  printf("\n   B \n");
  getRealType(&b);
  showRealType(&b);

  printf("Menu: \n");
  printf("1. Add \n");
  printf("2. Sub \n");
  printf("3. Mul \n");
  printf("Enter Choice: ");
  scanf("%d", &sw);

  switch (sw) {
    case 1:
    printf("\n   C=A+B \n");
    c = addRealType(&a,&b);
    showRealType(&c);
    break;

    case 2:
    printf("\n   C=A-B \n");
    c = subRealType(&a,&b);
    showRealType(&c);
    break;

    case 3:
    printf("\n   C=A*B \n");
    c = mulRealType(&a,&b);
    showRealType(&c);
    break;

    default:
    printf("Wrong Choice! \n");
    break;
  }


  return 0;
}
