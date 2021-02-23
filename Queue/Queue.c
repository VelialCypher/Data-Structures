#include <stdlib.h>
#include <stdio.h>

#include "Queue.h"

typedef struct Queue {
	int size;
	int capacity;
	int* data;
} Queue_t;

Queue_t* queue_create(int capacity) {
	Queue_t* queue = (Queue_t*)malloc(sizeof(Queue_t));
	queue -> data = (int*)malloc(sizeof(int) * capacity);
	queue -> capacity = capacity;
	queue -> size = 0;
	return queue;
}

int queue_empty(Queue_t* queue) {
	return queue -> size <= 0;
}

int queue_full(Queue_t* queue) {
	return queue -> size > queue -> capacity;
}

int queue_dequeue(Queue_t* queue) {
	if (queue_empty(queue)) {
		printf("Queue underflow\n");
		exit(1);
	}

	int dequeued = queue -> data[0];

	for (size_t i = 1; i < queue -> size; i++) {
		queue -> data[i - 1] = queue -> data[i];
	}
	queue -> size--;
	return dequeued;
}

void queue_enqueue(Queue_t* queue, int item) {
	if (queue_full(queue)) {
		printf("Queue overflow\n");
		exit(1);
	}

	queue -> data[queue -> size++] = item;
}

int queue_peek(Queue_t* queue) {
	if (queue_empty(queue)) {
		printf("Queue empty\n");
		exit(1);
	}
	return queue -> data[0];
}

int queue_count(Queue_t* queue) {
	return queue -> size;
}

void queue_free(Queue_t* queue) {
	free(queue -> data);
	free(queue);
}

int main() {
	Queue_t* queue = queue_create(8);

	queue_enqueue(queue, 5);
	queue_enqueue(queue, 10);
	queue_enqueue(queue, 15);
	queue_enqueue(queue, 20);
	queue_enqueue(queue, 30);

	queue_dequeue(queue);
	queue_dequeue(queue);
	queue_dequeue(queue);
	queue_dequeue(queue);
	printf("Last: %d\n", queue_peek(queue));

	printf("Count: %d\n", queue_count(queue));
	queue_free(queue);
	return 0;
}