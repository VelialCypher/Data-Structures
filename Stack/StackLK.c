#include <stdlib.h>
#include <stdio.h>

#include "StackLK.h"

typedef struct StackNode {
	int value;
	struct StackNode* next;
} StackNode_t;


typedef struct Stack {
	int length;
	StackNode_t* top;
} Stack_t;

StackNode_t* stackNode_create(int value) {
	StackNode_t* node = (StackNode_t*)malloc(sizeof(StackNode_t));
	node -> value = value;
	node -> next = NULL;
	return node;
}

Stack_t* stack_create() {
	Stack_t* stack	= (Stack_t*)malloc(sizeof(Stack_t));
	stack -> length = 0;
	stack -> top = NULL;
	return stack;
}

int stack_empty(Stack_t* stack) {
	return stack -> length <= 0;
}

void stack_push(Stack_t* stack, int value) {
	StackNode_t* node = stackNode_create(value);

	if (stack -> length > 0)
		node -> next = stack -> top;

	stack -> top = node;

	stack -> length++;
}

int stack_pop(Stack_t* stack) {
	if (stack_empty(stack)) {
		printf("Stack underflow\n");
		exit(1);
	}

	StackNode_t* temp = stack -> top;
	int poped = stack -> top -> value;
	stack -> top = stack -> top -> next;
	free(temp);
	stack -> length--;
	return poped;
}

int stack_peek(Stack_t* stack) {
	if (stack_empty(stack)) {
		printf("Stack underflow\n");
		exit(1);
	}
	return stack -> top -> value;
}

int stack_count(Stack_t* stack) {
	return stack -> length;
}

void stack_free(Stack_t* stack) {
	StackNode_t* temp;

	while (stack -> top) {
		temp = stack -> top;
		stack -> top = stack -> top -> next;
		free(temp);
	}

	free(stack -> top);
	free(stack);
}