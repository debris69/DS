#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node *next;
}NODE;

NODE *head = NULL;

void createList(){
  int x;
  NODE *p;
  while(1){
    printf("Enter the value for the new node[0 to exit] : ");
    scanf("%d", &x);
    if(x==0){
      break;
    }
    p = (NODE *)malloc(sizeof(NODE));
    p->value=x;
    p->next=NULL;
    if(head == NULL){
      head = p;
    }
    else{
      p->next=head;
      head = p;
    }
  }
}

void insertBeg(){
  NODE *p;
  int a;
  printf("enter the value to be inserted : ");
  scanf("%d", &a);
  p = (NODE *)malloc(sizeof(NODE));
  p->value=a;
  p->next=head;
  head=p;
}
void insertEnd(){
  NODE *p, *temp;
  int a;
  printf("enter the value to be inserted  : ");
  scanf("%d", &a);
  p = (NODE *)malloc(sizeof(NODE));
  p->value=a;
  p->next=NULL;
  temp = head;
  while(temp->next!=NULL){
    temp = temp->next;
  }
  temp->next=p;
}

void deleteBeg(){
  NODE *temp;
  temp = head;
  head = head->next;
  printf("%d -> deleted\n",temp->value);
  free(temp);
}

void display(){
  NODE *p;
  p = head;
  printf("Output :  ");
  while(p!=NULL){
    printf("%d  \t", p->value);
    p = p->next;
  }
  printf(" \n" );
}

int main(){
  int x, ch;
  createList();
  display();
  while(ch!=5){
    printf("1. Insert at beginning. \n");
    printf("2. Insert at end. \n");
    printf("3. Delete at beginning. \n");
    printf("4. Display. \n");
    printf("5. Exit. \n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    switch(ch){
      case 1:
      insertBeg();
      break;

      case 2:
      insertEnd();
      break;

      case 3:
      deleteBeg();
      break;

      case 4:
      display();
      break;

      case 5:
      exit(1);
      break;
    }
  }
  return 0;
}
