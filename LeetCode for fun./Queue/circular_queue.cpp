#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef struct CircularQueue {
    int head, tail;
    int a[MAX];
} CircularQueue;

void init(CircularQueue *q) {
    q->head = q->tail = -1;
}

int isFull(CircularQueue *q) {
    if ((q->tail + 1) % MAX == q->head) {
        return 1;
    }
    return 0;
}

int isEmpty(CircularQueue *q) {
    if (q->head == -1) return 1;
    return 0;
}

void put(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Circular queue is full.\n");
        return;
    }
    if (q->head == -1) ++(q->head);
    q->tail = (q->tail + 1) % MAX;
    q->a[q->tail] = value;
}

int get(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Circular queue is empty.\n");
        return -1;
    }
    int result = q->a[q->head];
    if (q->head == q->tail) {
        q->head = q->tail = -1;
    }
    else {
        q->head = (q->head + 1) % MAX;
    }
    return result;
}

void displayCircularQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        return;
    }
    int i = q->head;
    while(i != q->tail) {
        printf("%d ", q->a[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->a[q->tail]);
}

int main() {
    CircularQueue q;
    init(&q);
    int num[MAX] = {-5, 2, 4, -3, 1, 0, 9};
    int num2[3] = {8, 4, -3};   
    printf("MAX = %d\n\n", MAX);
    printf("Queue is empty at the beginning."); 
    // push
    printf("PUSH\n");
    for (int i = 0; i < MAX; i++) {
        printf("put %d: \n", num[i]);
        if(!isFull(&q)) {
            put(&q, num[i]);
            displayCircularQueue(&q);
        }
        else
            printf("Queue is full. \n\n");
    }  
    // get
    printf("\nGET\n");
    for(int i = 0; i < 5; i++) {
        printf("get %d: %d\n", i, get(&q));
        displayCircularQueue(&q);
    }
    // push
    printf("\nPUSH\n");
    for (int i = 0; i < 3; i++) {
        printf("put %d: \n", num2[i]);
        if(!isFull(&q)) {
            put(&q, num2[i]);
            displayCircularQueue(&q);
        }
        else
            printf("Queue is full. \n\n");
    }
    // get
    printf("\nGET\n");
    for(int i = 0; i < 3; i++) {
        printf("get %d: %d\n", i, get(&q));
        displayCircularQueue(&q);
    }
    return 0;
}

