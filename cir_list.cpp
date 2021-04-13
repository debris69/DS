#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}NODE;

NODE *head = NULL;

void addNode(int x){
  NODE *p = (NODE*)malloc(sizeof(NODE));
  p->data = x;
  if(head==NULL){
    head = p;
    p->next = head;
  }
  else{
    NODE *temp = head;
    while(temp->next!=head)
      temp = temp->next;
    p->next = head;
    head = p;
    temp->next = head;
  }
}
void display(){
  NODE *temp = head;
  if(head==NULL){
    printf("List is empty...");
  }
  else{
  while(temp->next!=head){
    printf("%d \t", temp->data);
    temp = temp->next;
  }
  printf(" %d", temp->data);
  printf("\n");
}
}
int main(){
  int ch, a;
  while(ch!=4){
    printf("1. insert an element. \n");
    printf("2. delete an element \n");
    printf("3. display \n");
    printf("4. exit \n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    switch(ch){
      case 1:
      printf("enter an element : ");
      scanf("%d", &a);
      addNode(a);
      break;

      case 3:
      display();
      break;

      case 4:
      exit(1);
      break;
    }
  }
  return 0;
}
