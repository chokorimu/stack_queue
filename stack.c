#include "stack.h"

void createStack(Stack *s, int size) {
    s->data = malloc(size*sizeof(int));
    if (s->data == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = size;
    printf("Stack berhasil dibuat dengan kapasitas %d\n", size);
}

void destroyStack(Stack *s) {
    free(s->data); 
    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
}

bool isEmptyStack(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == s->capacity - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! %d Tidak bisa push.\n", value);
    } else {
        s->data[++(s->top)] = value;
        printf("Push %d berhasil\n", value);
    }
}

int pop(Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack underflow! Tidak bisa pop\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack kosong\n");
        return -1;
    }
    return s->data[s->top];
}
