#include "stack.h"
#include "queue.h"

int main() {
    // Stack demonstration
    printf("=== STACK DEMONSTRATION ===\n");
    Stack s;
    createStack(&s);
    
    printf("Stack kosong? %s\n", isEmptyStack(&s) ? "Ya" : "Tidak");
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    
    printf("Peek: %d\n", peek(&s));
    
    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));
    
    printf("Stack kosong? %s\n", isEmptyStack(&s) ? "Ya" : "Tidak");
    printf("Stack penuh? %s\n", isFull(&s) ? "Ya" : "Tidak");
    
    printf("Peek setelah pop: %d\n", peek(&s));
    
    // Queue demonstration
    printf("\n=== QUEUE DEMONSTRATION ===\n");
    struct node* Queue = NULL;
    
    printf("Queue kosong? %s\n", isEmpty(&Queue) ? "Ya" : "Tidak");
    
    enqueue(&Queue, 10);
    enqueue(&Queue, 20);
    enqueue(&Queue, 30);
    enqueue(&Queue, 40);
    enqueue(&Queue, 50);
    
    printf("Head: %d\n", head(&Queue));
    printf("Tail: %d\n", tail(&Queue));
    
    printf("Dequeue: %d\n", dequeue(&Queue));
    printf("Dequeue: %d\n", dequeue(&Queue));
    
    printf("Isi queue sekarang:\n");
    iterate(&Queue);
    
    printf("Queue kosong? %s\n", isEmpty(&Queue) ? "Ya" : "Tidak");
    
    printf("Head: %d\n", head(&Queue));
    printf("Tail: %d\n", tail(&Queue));
    
    printf("Dequeue: %d\n", dequeue(&Queue));
    printf("Dequeue: %d\n", dequeue(&Queue));
    printf("Dequeue: %d\n", dequeue(&Queue));
    
    printf("Queue kosong? %s\n", isEmpty(&Queue) ? "Ya" : "Tidak");
    
    return 0;
}
