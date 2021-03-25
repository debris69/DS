#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node{
  int value;
  int priority;
  struct Node *next;
}Node;

Node* createNode(int v, int p){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->value = v;
  temp->priority = p;
  temp->next = NULL;
  return temp;
}


void remove(Node **head){
  if((*head)==NULL){
    printf("Empty List\n" );
    return;
  }
  Node *temp = *head;
  (*head) = (*head)->next;
  printf("%d [%d]->Removed\n",temp->value, temp->priority );
  free(temp);
}

void insert(Node **head, int v, int p){
  Node *h = (*head);
  Node *temp = createNode(v,p);

  if((*head)==NULL){
    (*head) = temp;
  }

  else if((*head)->priority > p){
    temp->next = *head;
    (*head) = temp;
  }

  else{
    while(h->next != NULL && h->next->priority < p ){
      h = h->next;
    }
    temp->next = h->next;
    h->next = temp;
  }
}

void display(Node **head){
  Node *temp = *head;
  printf("List(Value, [Priority]) ->" );
  while(temp != NULL){
    printf("%d[%d]   ",temp->value, temp->priority );
    temp = temp->next;
  }
  printf("\n" );
}


int main(){
  Node *head = NULL;

  int v, p, ch;

  while (1) {
    system("cls");
    printf("Menu\n" );
    printf("1. Insert\n" );
    printf("2. Remove\n" );
    printf("3. Display\n" );
    printf("4. Exit\n" );
    printf("Your choice -> " );
    scanf("%d",&ch );
    switch (ch) {
      case 1:
        printf("Enter value,priority: " );
        scanf("%d,%d",&v,&p );
        insert(&head, v,p);
      break;

      case 2:
        remove(&head);
      break;

      case 3:
        display(&head);
      break;

      case 4:
        exit(1);
      break;

      default:
      break;
    }
    printf("Press any key to continue execution... :3\n" );
    _getch();
  }


  return 0;
}
