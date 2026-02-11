#include "queue.h"

int head(struct node** Queue) {
    if(*Queue == NULL) {
        return -1;
    }
    return (*Queue)->value;
}

int tail(struct node** Queue) {
    if(*Queue == NULL) {
        return -1;
    }
    struct node* current = *Queue;
    while(current->next != NULL) {
        current = current->next;
    }
    return current->value;
}

void enqueue(struct node** Queue, int element) {
    struct node* newNode = malloc(sizeof(*newNode));
    newNode->value = element;
    newNode->next = NULL;

    if(*Queue == NULL) {
        (*Queue) = newNode;
        return;
    }
    struct node* current = *Queue;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int dequeue(struct node** Queue) {
    if(*Queue == NULL) {
        return -1;
    }
    struct node* temp = *Queue;
    int retval = temp->value;
    
    *Queue = (*Queue)->next;
    free(temp);
    return retval;
}

void iterate(struct node** Queue) {
    struct node* current = *Queue;
    while(current != NULL) {
        printf("%d\n", current->value);
        current=current->next;
    }
}

bool isEmpty(struct node** Queue) {
    return *Queue == NULL;
}
