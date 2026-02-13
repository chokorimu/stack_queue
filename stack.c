#include "stack.h"

void createStack(Stack *s) {
    s->top = -1;
}

bool isEmptyStack(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Tidak bisa push %d\n", value);
    } else {
        s->top++;
        s->data[s->top] = value;
        printf("Push %d berhasil\n", value);
    }
}

int pop(Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack underflow! Tidak bisa pop\n");
        return -1;
    } else {
        int value = s->data[s->top];
        s->top--;
        return value;
    }
}

int peek(Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack kosong\n");
        return -1;
    } else {
        return s->data[s->top];
    }
}
