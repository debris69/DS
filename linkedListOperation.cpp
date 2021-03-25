#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node;

Node *head = NULL;
Node *head2 = NULL;

void display(int h){
  Node *temp;
  if(h==1) temp = head;
  else temp = head2;
  while(temp != NULL){
    printf("%d ",temp->data );
    temp = temp->next;
  }
  printf("\n" );

}

void initialize(int x, int h){
  Node *temp;
  temp = (Node*)malloc(sizeof(Node));
  temp->data = x;
  if(h==1){
    temp->next = head;
    head = temp;
  }
  else{
    temp->next = head2;
    head2 = temp;
  }
}

void appendAtEnd(int x){
  Node *temp, *h;
  temp = (Node*)malloc(sizeof(Node));
  temp->next = NULL;
  temp->data = x;
  h = head;
  while(h->next != NULL)
    h = h->next;
  h->next = temp;
}

void concatenate(){
  Node *h = head;
  while(h->next != NULL)
    h = h->next;
  h->next = head2;
}

void deleteList(){
  Node *curr = head;
  Node *temp;
  while(curr != NULL){
    temp = curr->next;
    free(curr);
    curr = temp;
  }
  head = NULL;
}

void reverse(){
  Node *t1, *t2, *temp;
  t1 = t2 = NULL;

  if(head == NULL) printf("List is empty\n" );
  else{
    while(head != NULL){
      t2 = head->next;
      head->next = t1;
      t1 = head;
      head = t2;
    }
    head = t1;
  }
}

void deleteLast(){
  Node *temp, *prev;
  if(head == NULL) printf("List is empty\n" );
  else{
    temp = head;
    while(temp->next != 0){
      prev = temp;
      temp = temp->next;
    }
    printf("Deleted-> %d\n",temp->data );
    free(temp);
    prev->next = 0;
  }
}

void deleteAtPosition(int pos){
  Node *temp, *position;
  int i=1;
  if(head == NULL) printf("List is empty\n" );
  else{
    position = (Node*)malloc(sizeof(Node));
    temp = head;

    while(i < pos-1){
      temp = temp->next;
      i++;
    }

    position = temp->next;
    temp->next = position->next;
    printf("Deleted-> %d\n",position->data );
    free(position);
  }
}

void sort(){
  Node *curr = head;
  Node *i = NULL;
  int temp;

  if(head==NULL) return;
  else{
    while(curr != NULL){
      i = curr->next;
      while(i != NULL){
        if(curr->data > i->data){
          temp = curr->data;
          curr->data = i->data;
          i->data = temp;
        }
        i = i->next;
      }
      curr = curr->next;
    }
  }
}



void makeOrderedList(int x){
  Node *temp;
  temp = (Node*)malloc(sizeof(Node));
  temp->data = x;
  temp->next = NULL;
  if(head == NULL){
    head = temp;
  }
  else{
    Node *h = head;
    Node *prev;
    while(h != NULL){
      if(x < h->data) break;
      prev = h;
      h = h->next;
    }
    temp->next = h;
    if(h == head) head = temp;
    else prev->next = temp;
  }
}

void concatSort(){
  Node *temp = head2;
  while(temp != NULL){
    makeOrderedList(temp->data);
    temp = temp->next;
  }
}

void insertAtPosition(int x, int pos){
  Node *temp, *n;
  int i=1;
  n = (Node*)malloc(sizeof(Node));
  temp = head;
  n->data = x;
  n->next = 0;
  while(i < pos){
    temp = temp->next;
    i++;
  }

  n->next = temp->next;
  temp->next = n;
}

int countNodes(){
  int count = 0;
  Node *temp = head;
  while(temp != NULL){
    count++;
    temp = temp->next;
  }
  return count;
}

int main(){
  int x, ch, pos;
  while (1) {
    system("cls");
    printf("Menu: \n" );
    printf("1. Initialize LL1(Insert Front)\n" );
    printf("2. Initialize LL2(Insert Front)\n" );
    printf("3. Append End in LL1\n" );
    printf("4. Concat LL1 and LL2\n" );
    printf("5. Delete LL1\n" );
    printf("6. Reverse LL1\n" );
    printf("7. Delete Last from LL1\n" );
    printf("8. Delete from position in LL1\n" );
    printf("9. Make ordered LL1\n" );
    printf("10. Concatenate and Sort LL1 and LL2\n" );
    printf("11. Insert After position in LL1\n" );
    printf("12. Count Nodes in LL1\n" );
    printf("13. Display LL1\n" );
    printf("14. Display LL2\n" );
    printf("15. Exit\n" );
    printf("Enter choice: " );
    scanf("%d",&ch );

    switch (ch) {
      case 1:
        printf("Enter value: " );
        scanf("%d",&x );
        initialize(x, 1);
      break;
      case 2:
        printf("Enter value: " );
        scanf("%d",&x );
        initialize(x, 2);
      break;
      case 3:
        printf("Enter value: " );
        scanf("%d",&x );
        appendAtEnd(x);
      break;
      case 4:
        concatenate();
      break;
      case 5:
        deleteList();
      break;
      case 6:
        reverse();
      break;
      case 7:
        deleteLast();
      break;
      case 8:
        printf("Enter position: ");
        scanf("%d",&pos);
        deleteAtPosition(pos);
      break;
      case 9:
        printf("Enter value: " );
        scanf("%d",&x );
        makeOrderedList(x);
      break;
      case 10:
        concatSort();
      break;
      case 11:
        printf("Enter value to insert: " );
        scanf("%d",&x );
        printf("Enter position: " );
        scanf("%d",&pos);
        insertAtPosition(x, pos);
      break;
      case 12:
        printf("Count LL1: %d\n",countNodes() );
      break;
      case 13:
        display(1);
      break;
      case 14:
        display(2);
      break;

      case 15:
        exit(1);
      break;

      default:
      break;
    }
    printf("Press any key to continue execution...\n" );
    _getch();
  }
  return 0;
}
