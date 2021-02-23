#ifndef STACKLK_H
#define STACKLK_H

typedef struct StackNode StackNode_t;
typedef struct Stack Stack_t;

StackNode_t* stackNode_create(int value);
Stack_t* stack_create();
int stack_empty(Stack_t* stack);
void stack_push(Stack_t* stack, int value);
int stack_pop(Stack_t* stack);
int stack_peek(Stack_t* stack);
int stack_count(Stack_t* stack);
void stack_free(Stack_t* stack);

#endif