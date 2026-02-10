#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    bool isHead;
    bool isTail;
    struct node* next;
};

void enqueue(struct node** front, int new_size) {
    for(int i=0; i<new_size; i++) {
        if(*front == NULL) {
            *front = malloc(sizeof(**front));
            (*front)->value = 0;
            (*front)->isHead = true;
            (*front)->isTail = false;
            (*front)->next = NULL;
            printf("%d\n", (*front)->value);
            continue;
        }

        struct node* cursor = *front;
        while(cursor->next != NULL) {
            cursor=cursor->next;
        }

        cursor = malloc(sizeof(**front));
        cursor->value = i;
        cursor->isHead = false;
        cursor->isTail = true;
        cursor->next = NULL;

        printf("%d\n", cursor->value);
    }
}

int main() {
    struct node* front = NULL;

    enqueue(&front, 10);
    enqueue(&front, 5);
    return 0;
}