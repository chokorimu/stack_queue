#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    bool isHead;
    bool isTail;
    struct node* next;
};

void enqueue(struct node** front, int newValue) {
    struct node* newNode;
    newNode = malloc(sizeof(*newNode));
    newNode->value = newValue;
    newNode->isHead = false;
    newNode->isTail = true;
    newNode->next = NULL;

    if(*front == NULL) {
        (*front) = newNode;
        (*front)->isHead = true;
        (*front)->isTail = false;
        return;
    }
    
    if((*front)->next == NULL) {
        (*front)->next = newNode;
        return;
    }

    struct node* cursor = *front;
    while(cursor->isTail != true) {
        cursor=cursor->next;
    }

    if(cursor->next == NULL) {
        cursor->isTail = false;
        cursor->next = newNode;
        cursor->next->next = NULL;
        return;
    }
    
    if(cursor->next->isHead == true) {
        newNode->next = cursor->next;
        cursor->isTail = false;
        cursor->next = newNode;
        return;   
    }

    else {
        cursor->isTail = false;
        cursor->next->value = newValue;
        cursor->next->isTail = true;
        return;
    }
}

void dequeue(struct node** front) {
    if(*front == NULL) {
        return;
    }
   
    if((*front)->next == NULL) {
        free(*front);
        return;
    }

    bool doesTailExist;
    struct node* cursor = *front;
    while(cursor->isHead != true && cursor->next == NULL) {
        if(cursor->isTail == true) {
            doesTailExist = true;
        }
        cursor=cursor->next;
    }
    
    if(cursor->next == NULL) {
        if(doesTailExist == true) {
            (*front)->isHead = true;
            (*front)->isTail = false;
            cursor->isHead = false;
            return;
        }

        struct node* grimReaper = *front;
        while((*front)->next != NULL) {
            while(grimReaper->next != NULL) {
                grimReaper=grimReaper->next;
            }
            free(grimReaper->next);
            grimReaper->next = NULL;
            grimReaper=*front;
        }
        free(*front);
        return;
    }
    cursor->isHead = false;
    cursor->next->isHead = true;
    cursor->next->isTail = false;
}

void iterate(struct node** front) {
    if(*front == NULL) {
        return;
    }

    if((*front)->next == NULL) {
        printf("%d --> head\n", (*front)->value);
        return;
    }

    struct node* cursor = *front;
    while(cursor != NULL) {
        if(cursor->isHead == true) {
            printf("%d --> head\n", cursor->value);
            
        }

        else if(cursor->isTail == true) {
            printf("%d --> tail\n", cursor->value);
            
        }

        else {
            printf("%d\n", cursor->value);
        }
        cursor=cursor->next;
    }
}

bool isFull(struct node** front) {
    if(*front == NULL) {
        return false;
    }

    if((*front)->next == NULL) {
        return true;
    }

    struct node* cursor = *front;
    while(cursor->isTail != true) {
        cursor=cursor->next;
    }

    if(cursor->next == NULL || cursor->next->isHead == true) {
        return true;
    }
    return false;
}

bool isEmpty(struct node** front) {
    return(*front == NULL);
}

int main() {
    struct node* front = NULL;
    enqueue(&front, 10);
    enqueue(&front, 10);
    enqueue(&front, 10);
    enqueue(&front, 10);
    dequeue(&front);
    dequeue(&front);
    dequeue(&front);
    iterate(&front);
    return 0;
}