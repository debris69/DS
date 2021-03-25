#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define MAX 20

typedef struct Garage {
    int cars[MAX];
    int front;
    int rear;
} Garage;

void insert(Garage *g, int c) {
    if (g->rear == MAX-1) {
        printf("GARAGE FULL\n");
    }
    if (g->front == 1 && g->rear == 0) {
        g->front = 0;
        g->cars[g->front] = c;
    }
    else {
        g->cars[++g->rear] = c;
    }
}

int delete(Garage *g) {
    if (g->front > g->rear) {
        printf("GARAGE EMPTY\n");
        exit(0);
    }
    else {
        return g->cars[g->front++];
    }
}

void reverseInsert(Garage *g, int c) {
    g->cars[--g->front] = c;
}

int reverseDelete(Garage *g) {
    return g->cars[g->rear--];
}

void arrangeGarage(Garage *g) {
    if (g->front != 0 && g->front <= g->rear) {
        int i = 0;

        while (i != g->rear - g->front) {
            g->cars[i] = g->cars[g->front+i];
            i++;
        }

        g->cars[i] = g->cars[g->front+i];
        g->front = 0;
        g->rear = i;
    }
}

void showGarage(Garage *g) {
    int i;

    for (i = g->front; i <= g->rear; i++) {
        printf("%d | ", g->cars[i]);
    }

    printf("\nSpots Remaining: %d\n", MAX-(g->rear)-1);
}

int verify(char c[]){
    int i;

    if (!(c[0] == 'A' || c[0] == 'D')) {
        return 0;
    }

    if (c[1] != ' ') {
        return 0;
    }

    for (i = 2; i < strlen(c); i++) {
        if (!isdigit(c[i])) {
            return 0;
        }
    }

    return 1;
}

int isCarInGarage(Garage *g, int c){
    int i;

    if (g->rear == -1){
        printf("Garage Empty\n");
        return -1;
    }

    for (i = g->front; i < g->rear; i++) {
        if (g->cars[i] == c) {
            return i;
        }
    }

    return -1;
}

void main(){
    int nc, i, j, k, car_no, pos;
    char input[20][10], mode;
    Garage parkingLane, taxiLane;

    parkingLane.front = 0;
    taxiLane.front = 0;
    parkingLane.rear = -1;
    taxiLane.rear = -1;
    printf("Number Of Input Lines(MAX 20): ");
    scanf("%d", &nc);
    fflush(stdin);
    printf("Enter Input Lines: \n");

    for (i = 0; i < nc; i++) {
        gets(input[i]);
    }

    system("cls");
    printf("Your input Lines\n");

    for (i = 0; i < nc; i++) {
        puts(input[i]);
    }

    printf("Garage State:\n");
    showGarage(&parkingLane);

    for (i = 0; i < nc; i++) {
        if (!verify(input[i])) {
            continue;
            /* Move On To Next Input Line */
        }

        mode = input[i][0];
        car_no = 0;

        for (j = strlen(input[i])-1, k = 1; j >= 2; j--) {
            car_no += ((int)input[i][j]-48)*k;
            k *= 10;
        }

        printf("\nMode: %c   Car No: %d\n", mode, car_no);

        switch (mode) {
            case 'A':
                pos = isCarInGarage(&parkingLane, car_no);

                if (pos != -1) {
                    printf("Car Already In Garage\n");
                }
                else {
                    insert(&parkingLane, car_no);
                    printf("Car %d Parked Inside Garage\n", car_no);
                    printf("Garage State:\n");
                    showGarage(&parkingLane);
                }
            break;

            case 'D':
                pos = isCarInGarage(&parkingLane, car_no);

                if (pos == -1) {
                    printf("Car Not In Garage\n");
                }
                else {
                    while (parkingLane.front != pos) {
                        insert(&taxiLane, delete(&parkingLane));
                    }

                    printf("Car %d Has Exited The Garage\n", delete(&parkingLane));

                    while (taxiLane.rear != -1) {
                        reverseInsert(&parkingLane, reverseDelete(&taxiLane));
                    }

                    arrangeGarage(&parkingLane);
                    printf("Garage State:\n");
                    showGarage(&parkingLane);
                }
            break;

            default: break;
                /* Do Nothing */
        }

        printf("\nPress Any Key To Process Next Input Line...\n");
        getch();
    }

    printf("END\n");
}
