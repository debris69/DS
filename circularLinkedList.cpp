#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node;

Node *head = NULL;

void insertAtFront(int x){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->data = x;
  if(head == NULL){
    head = temp;
    temp->next = head;
  }
  else{
    Node *prev = head;
    while(prev->next != head)
      prev = prev->next;
    temp->next = head;
    head = temp;
    prev->next = head;
  }
}

void insertAtEnd(int x){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->data = x;
  if(head == NULL){
    head = temp;
    temp->next = head;
  }
  else{
    Node *prev = head;
    while(prev->next != head)
      prev = prev->next;
    prev->next = temp;
    temp->next = head;
  }
}

void deleteAtFront(){
  if(head == NULL)
    printf("Empty List\n" );
  else{
    Node *temp = head;
    if(temp->next == head){
      head = NULL;
      printf("Deleted -> %d\n",temp->data );
      free(temp);
    }
    else{
      head = head->next;
      printf("Deleted -> %d\n",temp->data );
      free(temp);
    }
  }
}

void deleteAtEnd(){
  if(head == NULL)
    printf("Empty List\n" );
  else{
    Node *temp = head, *prev;
    if(temp->next == head){
      head = NULL;
      printf("Deleted -> %d\n",temp->data );
      free(temp);
    }
    else{
      while(temp->next != head){
        prev = temp;
        temp = temp->next;
      }
      prev->next = head;
      printf("Deleted -> %d\n",temp->data );
      free(temp);
    }
  }
}

void display(){
  if(head == NULL)
    printf("Empty List\n" );
  else{
    Node *temp = head;
    printf("List:-> " );
    while (temp->next != head) {
      printf("%d  ",temp->data );
      temp = temp->next;
    }
    printf("%d\n", temp->data);
  }
}

int main(){
  int x, sw;

  while(1){
    system("cls");
    printf("Menu:\n" );
    printf("1. Insert Front\n" );
    printf("2. Insert End\n" );
    printf("3. delete Front\n" );
    printf("4. Delete end\n" );
    printf("5. Display\n" );
    printf("6. Exit\n" );
    printf("Enter choice: ");
    scanf("%d", &sw );

    switch (sw) {
      case 1:
        printf("enter value to insert: ");
        scanf("%d", &x );
        insertAtFront(x);
      break;

      case 2:
        printf("enter value to insert: ");
        scanf("%d", &x );
        insertAtEnd(x);
      break;

      case 3:
        deleteAtFront();
      break;

      case 4:
        deleteAtEnd();
      break;

      case 5:
        display();
      break;

      case 6:
        exit(1);
      break;

      default:
      break;
    }

    printf("press any key to continue execution .. :3\n");
    _getch();
  }

  return 0;
}
