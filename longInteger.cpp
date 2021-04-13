#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node;


void addNode(int x, Node **temp){
  Node *r, *z;
  z = *temp;
  if(z == NULL){
    r = (Node*)malloc(sizeof(Node));
    r->data = x;
    *temp = r;
    r->next = (Node*)malloc(sizeof(Node));
    r = r->next;
    r->next = NULL;
  }
  else{
    r->data = x;
    r->next = (Node*)malloc(sizeof(Node));
    r = r->next;
    r->next = NULL;
  }
}



void display(Node *h){
  while(h->next != NULL){
    printf("%d",h->data );
    h = h->next;
    if(h->next!=NULL){
      printf("-" );
    }
  }
  printf("\n" );
}


void addLong(Node *p1, Node *p2, Node *res){
  int carry = 0;
  while(p1->next && p2->next){
    res->data = p1->data + p2->data + carry;
    carry = 0;
    if(res->data > 9){
      carry = 1;
      res->data %= 10;
    }
    p1 = p1->next;
    p2 = p2->next;
    res->next = (Node*)malloc(sizeof(Node));
    res = res->next;
    res->next = NULL;
  }
  while(p1->next || p2->next){
    if(p1->next){
      res->data = p1->data + carry;
      carry = 0;
      if(p1->next!=NULL){
        if(res->data > 9){
          carry = 1;
          res->data %= 10;
        }
      }
      p1 = p1->next;
    }
    if(p2->next){
      res->data = p2->data + carry;
      carry = 0;
      if(p2->next!=NULL){
        if(res->data > 9){
          carry = 1;
          res->data %= 10;
        }
      }
      p2 = p2->next;
    }
    res->next = (Node*)malloc(sizeof(Node));
    res = res->next;
    res->next = NULL;
  }
}



int main(){
  Node *head = NULL;
  Node *head2 = NULL;
  Node *result = NULL;

  long long int x,y;

  printf("Enter large x: " );
  scanf("%lli", &x );
  printf("Enter large y: " );
  scanf("%lli", &y);

  printf("\n\n----------Input---------\n" );
  printf("Given number 1: %lli\n", x);
  printf("Given number 2: %lli\n", y);
  printf("Expected Sum: %lli\n",x+y );

  while(x!=0){
    addNode(x%10,&head);
    x = x/10;
  }

  while(y!=0){
    addNode(y%10,&head2);
    y = y/10;
  }

  printf("\n\n\n-----Output----------\n" );
  printf("Number 1: " );
  display(head);
  printf("Number 2: " );
  display(head2);

  result = (Node*)malloc(sizeof(Node));
  addLong(head, head2, result);
  printf("Sum: " );
  display(result);

  return 0;
}
