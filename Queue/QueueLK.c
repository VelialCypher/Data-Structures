#include <stdlib.h>
#include <stdio.h>

#include "QueueLK.h"

typedef struct QueueNode {
	int value;
	struct QueueNode* next;
} QueueNode_t;

typedef struct Queue {
	int length;
	QueueNode_t* head;
	QueueNode_t* tail;
} Queue_t;

QueueNode_t* queueNode_create(int value) {
	QueueNode_t* node = (QueueNode_t*)malloc(sizeof(QueueNode_t));
	node -> next = NULL;
	node -> value = value;
	return node;
}

Queue_t* queue_create() {
	Queue_t* queue = (Queue_t*)malloc(sizeof(Queue_t));
	queue -> length = 0;
	queue -> head = NULL;
	queue -> tail = NULL;
	return queue;
}

int queue_empty(Queue_t* queue) {
	return queue -> length <= 0;
}

void queue_enqueue(Queue_t* queue, int item) {
	QueueNode_t* node = queueNode_create(item);

	if (queue -> length == 0) {
		queue -> head = queue -> tail = node;
	} else {
		queue -> tail -> next = node;
		queue -> tail = node;
	}

	queue -> length++;
}

int queue_count(Queue_t* queue) {
	return queue -> length;
}

int queue_dequeue(Queue_t* queue) {
	if (queue_empty(queue)) {
		printf("Queue empty\n");
		exit(1);
	}
	int dequeued = queue -> head -> value;
	queue -> head = queue -> head -> next;
	queue -> length--;
	return dequeued;
}

void queue_free(Queue_t* queue) {
	QueueNode_t* temp;

	while (queue -> head) {
		temp = queue -> head;
		queue -> head = queue -> head -> next;
		free(temp);
	}

	free(queue -> head);
	free(queue -> tail);
	free(queue);
}