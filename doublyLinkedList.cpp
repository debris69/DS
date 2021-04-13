#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
}Node;

Node *head = NULL;

void insertFront(int x){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->data = x;
  if(head == NULL){
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
  }
  else{
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
}

void insertEnd(int x){
  Node *p, *temp;
  temp = (Node*)malloc(sizeof(Node));
  temp->data = x;
  if(head == NULL){
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
  }
  else{
    p = head;
    while(p->next != NULL)
      p = p->next;
    p->next = temp;
    temp->prev = p;
    temp->next = NULL;
  }
}


void deleteFront(){
  Node *temp;
  if(head == NULL)
    printf("UnderFlow..\n" );
  else if(head->next == NULL){
    printf("Deleted-> %d\n",head->data );
    head = NULL;
    free(head);
  }
  else{
    temp = head;
    head = head->next;
    head->prev = NULL;
    printf("Deleted-> %d\n",temp->data );
    free(temp);
  }
}

void deleteEnd(){
  Node *temp;
  if(head == NULL)
    printf("UnderFlow..\n" );
  else if(head->next == NULL){
    printf("Deleted-> %d\n",head->data );
    head = NULL;
    free(head);
  }
  else{
    temp = head;
    while(temp->next != NULL)
      temp = temp->next;
    printf("Deleted-> %d\n",temp->data );
    temp->prev->next = NULL;
    free(temp);
  }
}

void display(){
  Node *temp = head;
  if(temp == NULL) printf("UnderFlow..\n" );
  else{
    while(temp != NULL){
      printf("%d -> ",temp->data );
      temp = temp->next;
    }
    printf("\n" );
  }
}

int search(int x){
  Node *temp = head;
  int pos = 0;
  if(temp == NULL) return -1;
  else{
    while(temp != NULL){
      if(temp->data == x) return pos+1;
      pos++;
      temp = temp->next;
    }
    return -1;
  }
}

int main(){
  int sw, x, pos;
  while(1){
    system("cls");

    printf("Menu.....\n" );
    printf("1. Insert Front....\n" );
    printf("2. Insert End....\n" );
    printf("3. Delete Front....\n" );
    printf("4. Delete End....\n" );
    printf("5. Search....\n" );
    printf("6. Display.....\n" );
    printf("7. Exit.....\n" );
    printf("Enter choice: " );
    scanf("%d", &sw );

    switch (sw) {
      case 1:
        printf("Enter value: " );
        scanf("%d", &x );
        insertFront(x);
      break;

      case 2:
        printf("Enter value: " );
        scanf("%d", &x );
        insertEnd(x);
      break;

      case 3:
        deleteFront();
      break;

      case 4:
        deleteEnd();
      break;

      case 5:
        printf("Enter value to search: " );
        scanf("%d", &x );
        pos = search(x);
        if(pos == -1) printf("Item not Found...\n" );
        else printf("Position of %d in List: %d\n",x, pos );
      break;

      case 6:
        display();
      break;

      case 7:
        exit(1);
      break;
    }
    printf("press any key to continue ... :3\n" );
    _getch();
  }
  return 0;
}
