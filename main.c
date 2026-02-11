#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    bool isHead;
    bool isNodeEmpty;
    struct node* next;
};

void enqueue(struct node** front, int newValue) {
    if(*front == NULL) {
        *front = malloc(sizeof(**front));
        (*front)->value = newValue;
        (*front)->isHead = true;
        (*front)->isNodeEmpty = false;
        (*front)->next = NULL;
        return;
    }

    struct node* cursor = *front;
    while(cursor->next != NULL) {
        cursor=cursor->next;
    }

    struct node* newNode;
    newNode = malloc(sizeof(**front));
    newNode->value = newValue;
    newNode->isHead = false;
    newNode->isNodeEmpty = false;
    newNode->next = NULL;
    cursor->next = newNode;
    }

void dequeue(struct node** front) {
    if(*front == NULL) {
        return;
    }
    
    if((*front)->next == NULL) {
        free(*front);
        return;
    }
    
    struct node* cursor = *front;
    while(cursor->isHead != true) {
        cursor=cursor->next;
    }
    
    if(cursor->next == NULL) {
        (*front)->isHead = true;
        cursor->isNodeEmpty = true;
        cursor->isHead = false;
        return;
    }
    cursor->isHead = false;
    cursor->isNodeEmpty = true;
    cursor->next->isHead = true;
}

void iterate(struct node** front) {
    if(*front == NULL) {
        return;
    }
    if((*front)->next == NULL) {
        printf("%d\n", (*front)->value);
        return;
    }
    
    struct node* cursor = *front;
    while(cursor != NULL) {
        if(cursor->isHead == true) {
            printf("%d --> head\n", cursor->value);
            
        }

        else if(cursor->isNodeEmpty == false && (cursor->next == NULL || cursor->next->isHead == true || cursor->next->isNodeEmpty == true)) {
            printf("%d --> tail\n", cursor->value);
            
        }

        else if(cursor->isNodeEmpty == false) {
            printf("%d\n", cursor->value);
        }
        
        else {
            printf("%d (empty)\n", cursor->value);
        }
        cursor=cursor->next;
    }
}

bool isFull(struct node** front) {
    struct node* cursor = *front;
    while(cursor->next != )
    return()
}

bool isEmpty(struct node** front) {
    return(*front == NULL);
}

int main() {
    struct node* front = NULL;

    enqueue(&front, 10);
    enqueue(&front, 5);
    enqueue(&front, 3);
    enqueue(&front, 2);
    dequeue(&front);
    dequeue(&front);
    dequeue(&front);
    iterate(&front);
    return 0;
}