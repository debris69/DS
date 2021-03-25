#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 5

typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;

int menu(){
    int ch;

    printf("CIRCULAR QUEUE OPERATIONS\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Show Queue\n");
    printf("4. Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d", &ch);

    return ch;
}

void insert(Queue *q, int e) {
    int temp;
    if (q->front == MAX-1 && q->rear == MAX-1) {
        q->front = 0;
        q->rear = 0;
        q->arr[q->rear] = e;
        return;
    }
    if (q->rear == MAX-1) {
        temp = 0;
    }
    else {
        temp = q->rear+1;
    }
    if (q->front == temp) {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    q->rear = temp;
    q->arr[q->rear] = e;
    return;
}

int delete(Queue *q) {
    int ele;
    if (q->front == q->rear) {
        printf("QUEUE UNDERFLOW\n");
        exit(0);
    }
    if (q->front == MAX-1) {
        ele = q->arr[q->front];
        q->front = 0;
    }
    else {
        ele =  q->arr[q->front];
        q->front++;
    }

    return ele;
}

void showQueueStatus(Queue *q) {
    printf("\nFront=%d   rear=%d\n", q->front, q->rear);
}

void main(){
    Queue q;
    int ele;

    q.front = MAX-1;
    q.rear = MAX-1;

    do {
        system("cls");

        switch (menu()) {
            case 1:
                printf("Enter Value To Insert Into Queue: ");
                scanf("%d", &ele);
                insert(&q, ele);
                printf("The Queue: ");
                showQueueStatus(&q);
            break;

            case 2:
                ele = delete(&q);
                printf("Deleted Value: %d\n", ele);
                printf("The Queue: ");
                showQueueStatus(&q);
            break;

            case 3:
                printf("The Queue: ");
                //showQueue(&q);
            break;

            case 4:
                exit(0);
            break;

            default:
                printf("Invalid Choice\n");
        }

        printf("\nPress Any Key To Return To Main Menu...\n");
        getch();
    } while(1);
}
