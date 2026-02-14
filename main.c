#include <stdio.h>
#include "stack.h"

int main() {
    Stack s;

    createStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Elemen teratas: %d\n", peek(&s));

    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));

    printf("Elemen teratas sekarang: %d\n", peek(&s));

    return 0;
}
