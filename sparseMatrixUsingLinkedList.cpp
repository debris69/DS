#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int row, col, data;
  struct Node *next;
}Node;

int count;

Node *head = NULL;

void addNode(int x, int y, int z){
  count++;
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->row = x;
  temp->col = y;
  temp->data = z;
  temp->next = NULL;
  if(head == NULL){
    head = temp;
  }
  else{
    Node *h = head;
    while(h->next != NULL)
      h = h->next;
    h->next = temp;
  }
}

void display(){
  Node *temp = head;
  printf("\n" );
  while(temp != NULL){
    printf("Row: %d, Col: %d, Data: %d \n",temp->row, temp->col, temp->data );
    temp = temp->next;
  }
}



void printSparse(){
  int r = head->row;
  int c = head->col;
  Node *t = head->next;
  printf("\nSparse Matrix: \n" );
  int i=0 ,j=0;
  while(i<r){
    j=0;
    while(j<c){
      if(t!= NULL && t->row == i && t->col == j){
        printf("%d \t",t->data );
        t = t->next;
      }
      else{
        printf("0 \t" );
      }
      j++;
    }
    printf("\n" );
    i++;
  }
}


int main(){
  int row, col, data;
  printf("Enter order (row,col):" );
  scanf("%d,%d",&row,&col);
  addNode(row,col,0);

  for(int i=0; i<row; i++){
    for (int j=0; j<col; j++){
      printf("\nEnter element [%d,%d]: ",i,j );
      scanf("%d", &data );
      if(data != 0){
        addNode(i, j, data);
      }
    }
  }

  head->data = count-1;
  display();

  printSparse();

  return 0;
}
