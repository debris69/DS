#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 10

typedef struct Garage{
  int top;
  int license[MAX];
}Garage;

void arrival(Garage *p, int newCar){
  if(p->top<MAX-1){
    p->license[++p->top] = newCar;
    printf("New Car Parked!! -> %d\n", p->license[p->top] );
    printf("Current garage capacity: %d/%d\n",p->top+1,MAX);
  }
  else{
    printf("Garage is full -> %d not parked\n",newCar );
    printf("Current garage capacity: %d/%d\n",p->top+1,MAX);
  }
}

void pushTempStack(Garage *t, int nvalue){
  if(t->top<MAX-1){
    t->license[++t->top] = nvalue;
  }
}

int pop(Garage *t){
  if(t->top==-1){
    printf("Stack Underflow!!\n" );
    return -1;
  }
  else{
    return t->license[t->top--];
  }
}

int searchCar(Garage *p, int car){
  for(int i=0; i<=p->top; i++){
    if(p->license[i]==car){
      return 1;
    }
  }
  return 0;
}

void departure(Garage *p, int existingCar){
  Garage t;
  t.top = -1;
  int k=0;
  if(p->top==-1){
    printf("Empty Garage -> %d not parked!!\n", existingCar );
    printf("Current stack capacity: %d/%d\n",p->top+1,MAX);
  }
  else{
    if(searchCar(p,existingCar)){
      while(k!=existingCar){ //4
        k = pop(p);
        if(k!=existingCar){
          pushTempStack(&t, k);
        }
      }
      for(int i=t.top; i>=0; i--){
        pushTempStack(p, t.license[i]);
      }
      printf("%d taken out from garage\n",existingCar );
    }
    else{
      printf("%d not parked\n",existingCar );
    }
  }
}

void printGarage(Garage *g){
  for(int i=0; i<=g->top; i++){
    printf("%d \t",g->license[i] );
  }
  printf("\n" );
}

int main(){
  Garage g;
  g.top = -1;
  int value;
  char s;
  char e = 'E';
  printf("\nPress (E 0) to exit\nPress (P 0) to view Garage\nPress (A License) to Arrive\nPress (D License) to Depart : ");
  while(strcmp(&s,&e)!=0){
    scanf("%c %d",&s,&value);

    switch(s){
      case 'A':
        arrival(&g, value);
      break;

      case 'D':
        departure(&g, value);
      break;

      case 'P':
        printGarage(&g);
      break;

      default:
      break;
    }
  }
  return 0;
}
