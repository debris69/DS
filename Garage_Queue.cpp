#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define MAX 10

typedef struct Garage{
  int north, south; 
  int car[MAX];
}Garage;

void arrive(Garage *g, int x){
  if(g->south == MAX-1){
    printf("Garage Overflow\n");
  }
  if(g->north == 1 && g->south == 0){
    g->north = 0;
    g->car[g->north] = x;
  }
  else{
    g->car[++g->south] = x;
  }
}

int depart(Garage *g){
  if(g->north > g->south){
    printf("Garage Underflow\n");
    exit(0);
  }
  else
    return g->car[g->north++];
}

void reInsert(Garage *g, int x){
  g->car[--g->north] = x;
}

int reDelete(Garage *g){
  return g->car[g->south--];
}

void shiftGarage(Garage *g){
  int i;
  if(g->north != 0 && g->north <= g->south){
    i = 0;
    while(i != g->south - g->north){
      g->car[i] = g->car[g->north+i];
      i++;
    }
    g->car[i] = g->car[g->north+i];
    g->north = 0;
    g->south = i;
  }
}

void displayGarage(Garage *g){
  int i;
  for(i = g->north; i<= g->south; i++){
    printf("%d  ",g->car[i] );
  }
  printf("\nFree parking spots: %d/%d\n",MAX-(g->south)-1,MAX );
}

int verify(char c[]){
  int i;

  if(!(c[0] == 'A' || c[0] == 'D')) return 0;
  if(c[1] != ' ') return 0;

  for(i = 2; i<strlen(c); i++){
    if(!isdigit(c[i])) return 0;
  }

  return 1;
}

int searchCar(Garage *g, int x){
  int i;
  if(g->south == -1) return -1;
  for(i = g->north; i < g->south; i++)
    if(g->car[i] == x) return i;

  return -1;
}

int main(){
  int n, i, j, k, car, pos;
  char input[20][10], type;

  Garage g, temp;

  g.north = temp.north = 0;
  g.south = temp.south = -1;

  printf("Enter number of Input Lines (Max %d): ",MAX );
  scanf("%d",&n );
  fflush(stdin);

  printf("Enter %d input lines: \n" ,n);
  for(i=0; i<n; i++)
    gets(input[i]);

  printf("Current Garage Status: ");
  displayGarage(&g);

  for(i=0; i<n; i++){
    if(!verify(input[i]))
      continue;

    type = input[i][0];
    car = 0;

    for(j = strlen(input[i])-1, k = 1; j>=2; j--){
      car += ((int)input[i][j]-48)*k;
      k *=10;
    }

    printf("\n\nType: %c , License: %d\n",type, car );
    switch(type){
      case 'A':
        pos = searchCar(&g, car);
        if(pos != - 1) printf("Car already parked\n" );
        else{
          arrive(&g, car);
          printf("Parked->  %d \n", car);
          printf("Current Garage Status: ");
          displayGarage(&g);
        }
      break;

      case 'D':
        pos = searchCar(&g, car);
        if(pos == -1) printf("No such car parked\n");
        else{
          while(g.north != pos)
            arrive(&temp, depart(&g));
          printf("Departed-> %d\n", depart(&g));

          while(temp.south != -1)
            reInsert(&g, reDelete(&temp));

          shiftGarage(&g);
          printf("Current Garage Status: " );
          displayGarage(&g);
        }
      break;
    }
    printf("\nProcessing Next Input Line..\n-----------------------------\n\n" );
  }
  printf("End of Input Lines\n" );
  return 0;
}
