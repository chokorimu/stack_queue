#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    struct node* next;
};

int head(struct node** Queue);
int tail(struct node** Queue);
void enqueue(struct node** Queue, int element);
int dequeue(struct node** Queue);
void iterate(struct node** Queue);
bool isEmpty(struct node** Queue);

#endif
