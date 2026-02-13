#include "stack.h"
#include "queue.h"

int main() {
    // Stack
    Stack s;
    createStack(&s, 3);
    
    printf("Stack kosong? %s\n", isEmptyStack(&s) ? "Ya" : "Tidak");
    printf("Stack penuh? %s\n", isFull(&s) ? "Ya" : "Tidak");
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    
    printf("Peek: %d\n", peek(&s));
    
    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));
    
    destroyStack(&s);
    
    // Queue
    struct node* Queue = NULL;
    
    printf("Queue kosong? %s\n", isEmpty(&Queue) ? "Ya" : "Tidak");
    
    enqueue(&Queue, 5);
    enqueue(&Queue, 10);
    enqueue(&Queue, 15);
    
    printf("Head: %d\n", head(&Queue));
    printf("Tail: %d\n", tail(&Queue));
    
    printf("Dequeue: %d\n", dequeue(&Queue));
    printf("Dequeue: %d\n", dequeue(&Queue));
    
    printf("Isi queue:\n");
    iterate(&Queue);
    
    printf("Queue kosong? %s\n", isEmpty(&Queue) ? "Ya" : "Tidak");
    return 0;
}
