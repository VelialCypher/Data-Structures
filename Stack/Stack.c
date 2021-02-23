#include <stdlib.h>
#include <stdio.h>

#include "Stack.h"

typedef struct Stack {
	int size;
	int capacity;
	int* data;
} Stack_t;

Stack_t* stack_create(int capacity) {
	Stack_t* stack = (Stack_t*)malloc(sizeof(Stack_t));
	stack -> data = (int*)malloc(sizeof(int) * capacity);
	stack -> capacity = capacity;
	stack -> size = 0;
	printf("Mem allocate: %ld bytes.\n", sizeof(int) * capacity);
	return stack;
}

int stack_empty(Stack_t* stack) {
	return stack -> size <= 0;
}

int stack_full(Stack_t* stack) {
	return stack -> size > stack -> capacity;
}

void stack_push(Stack_t* stack, int data) {
	if (stack_full(stack)) {
		printf("Stack overflow\n");
		exit(1);
	}
	stack -> data[stack -> size++] = data;
}

int stack_pop(Stack_t* stack) {
	if (stack_empty(stack)) {
		printf("Stack underflow\n");
		exit(1);
	}
	return stack -> data[--stack -> size];
}

void stack_free(Stack_t* stack) {
	free(stack -> data);
	free(stack);
}

int stack_peek(Stack_t* stack) {
	return stack -> data[stack -> size];
}