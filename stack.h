#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;   
    int capacity;
} Stack;

void createStack(Stack *s, int size); 
void destroyStack(Stack *s);
bool isEmptyStack(Stack *s);
bool isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int top(Stack *s);

#endif
