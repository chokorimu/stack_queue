#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    struct node* next;
};

int head(struct node** head);
int tail(struct node** head);
void enqueue(struct node** head, int newValue);
int dequeue(struct node** head);
void iterate(struct node** head);
bool isEmpty(struct node** head);
