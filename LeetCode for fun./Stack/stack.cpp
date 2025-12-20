#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Stack_type {
    int a[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    ++(s->top);
    s->a[s->top] = value;
}

int pop(Stack *s) {
    int result = s->a[s->top];
    --(s->top);
    return result;
}

void display(Stack *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->a[i]);
    }
}

int main() {
    Stack s;
    init(&s);
    int num[6] = {1,-2,3,-4,5,-6};
    printf("MAX = %d\n\n", MAX);
    printf("PUSH\n");
    for (int i = 0; i < 6; i++) {
        printf("Push %d:\n", num[i]);
        if (!isFull(&s)) {
            push(&s, num[i]);
            display(&s);
            printf("\n");
        }
        else {
            printf("\nStack is full\n");
        }
    }
    printf("\nPOP\n");
    while(!isEmpty(&s)) {
        int result = pop(&s);
        printf("pop %d\n", result);
        display(&s);
        printf("\n");
    }
    if (isEmpty(&s)) printf("Stack is Empty\n");
    return 0;
}
