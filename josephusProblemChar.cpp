#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  char name;
  struct Node *next;
}Node;

Node* newNode(char name){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->name = name;
  temp->next = temp;
  return temp;
}

void getJosephusPosition(char n[], int c){
  int m;
  Node *head = newNode(n[0]);
  Node *prev = head;
  for(int i=1; i<c; i++){
    prev->next = newNode(n[i]);
    prev = prev->next;
  }
  prev->next = head;

  Node *temp = head;
  char s;
  int f;
  printf("Enter starting node: ");
  scanf("%c",&s );

  while(temp->name != s && temp->next != head){
    temp = temp->next;
  }

  Node *p1 = temp, *p2 = temp;
  while(p1->next != p1){
    int count = 1;
    printf("Enter m to kill mth node:" );
    scanf("%d", &m );
    while(count != m){
      p2 = p1;
      p1 = p1->next;
      count++;
    }
    p2->next = p1->next;
    free(p1);
    p1 = p2->next;
  }

  printf("Last person left standing is %c\n",p1->name );
}

int main(){
  char names[] = {'A','B','C','D','E'};
  getJosephusPosition(names, sizeof(names)/sizeof(names[0]));
  return 0;
}
