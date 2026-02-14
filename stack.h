#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void createStack(Stack *s);
bool isEmpty(Stack *s);
bool isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);

#endif