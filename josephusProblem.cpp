#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node;

Node* newNode(int d){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->data = d;
  temp->next = temp;
  return temp;
}

void getJosephusPosition(int m, int n){
  Node *head = newNode(1);
  Node *prev = head;
  for(int i = 2; i <= n; i++){
    prev->next = newNode(i);
    prev = prev->next;
  }
  prev->next = head;

  Node *p1 = head, *p2 = head;
  while (p1->next != p1) {
    int count = 1;
    while (count != m) {
      p2 = p1;
      p1 = p1->next;
      count++;
    }
    p2->next = p1->next;
    free(p1);
    p1 = p2->next;
  }

  printf("Last person standing is %d\n",p1->data );
}

int main(){
  getJosephusPosition(3,5);
  return 0;
}
