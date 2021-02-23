#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack_t;

Stack_t* stack_create(int capacity);
int stack_empty(Stack_t* stack);
int stack_full(Stack_t* stack);
void stack_push(Stack_t* stack, int data);
int stack_pop(Stack_t* stack);
void stack_free(Stack_t* stack);
int stack_peek(Stack_t* stack);

#endif