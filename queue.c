#include "queue.h"

int head(struct node** head) {
    if(*head == NULL) {
        return -1;
    }
    return (*head)->value;
}

int tail(struct node** head) {
    if(*head == NULL) {
        return -1;
    }
    struct node* cursor = *head;
    while(cursor->next != NULL) {
        cursor = cursor->next;
    }
    return cursor->value;
}

void enqueue(struct node** head, int newValue) {
    struct node* newNode = malloc(sizeof(*newNode));
    newNode->value = newValue;
    newNode->next = NULL;

    if(*head == NULL) {
        (*head) = newNode;
        return;
    }
    struct node* cursor = *head;
    while(cursor->next != NULL) {
        cursor = cursor->next;
    }
    cursor->next = newNode;
}

int dequeue(struct node** head) {
    if(*head == NULL) {
        return -1;
    }
    struct node* temp = *head;
    int retval = temp->value;
    
    *head = (*head)->next;
    free(temp);
    return retval;
}

void iterate(struct node** head) {
    struct node* cursor = *head;
    while(cursor != NULL) {
        printf("%d\n", cursor->value);
        cursor=cursor->next;
    }
}

bool isEmpty(struct node** head) {
    return *head == NULL;
}
