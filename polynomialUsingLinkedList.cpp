#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node{
   int coeff;
   int pow;
   struct Node *next;
}Node;

void createPoly(int x, int y, Node **temp){
   Node *r, *z;
   z = *temp;
   if(z == NULL){
      r =(Node*)malloc(sizeof(Node));
      r->coeff = x;
      r->pow = y;
      *temp = r;
      r->next = (Node*)malloc(sizeof(Node));
      r = r->next;
      r->next = NULL;
   }
   else {
      r->coeff = x;
      r->pow = y;
      r->next = (Node*)malloc(sizeof(Node));
      r = r->next;
      r->next = NULL;
   }
}

void addPolynomial(Node *p1, Node *p2, Node *result){
   while(p1->next && p2->next){
      if(p1->pow > p2->pow){
         result->pow = p1->pow;
         result->coeff = p1->coeff;
         p1 = p1->next;
      }
      else if(p1->pow < p2->pow){
         result->pow = p2->pow;
         result->coeff = p2->coeff;
         p2 = p2->next;
      }
      else {
         result->pow = p1->pow;
         result->coeff = p1->coeff+p2->coeff;
         p1 = p1->next;
         p2 = p2->next;
      }
      result->next = (Node *)malloc(sizeof(Node));
      result = result->next;
      result->next = NULL;
   }
   while(p1->next || p2->next){
      if(p1->next){
         result->pow = p1->pow;
         result->coeff = p1->coeff;
         p1 = p1->next;
      }
      if(p2->next){
         result->pow = p2->pow;
         result->coeff = p2->coeff;
         p2 = p2->next;
      }
      result->next = (Node *)malloc(sizeof(Node));
      result = result->next;
      result->next = NULL;
   }
}

void printpoly(Node *node){
   while(node->next != NULL){
      printf("(%dx^%d)", node->coeff, node->pow);
      node = node->next;
      if(node->next != NULL)
         printf(" + ");
   }
}

int main(){
   Node *p1 = NULL, *p2 = NULL, *result = NULL;

   //polynomial 1-> 40x^7 + -12x^5 + -8x^2 + 38x^0
   createPoly(40,7,&p1);
   createPoly(-12,5,&p1);
   createPoly(-8,2,&p1);
   createPoly(38,0,&p1);

   //polynomial 2 -> 2x^6 + 14x^5 + 5x^2 + -21x^0
   createPoly(2,6,&p2);
   createPoly(14,5,&p2);
   createPoly(5,2,&p2);
   createPoly(-21,0,&p2);

   printf("p1-> ");
   printpoly(p1);
   printf("\np2-> ");
   printpoly(p2);


   result = (Node *)malloc(sizeof(struct Node));
   addPolynomial(p1, p2, result);
   printf("\np1+p2->  ");
   printpoly(result);
   return 0;
}
