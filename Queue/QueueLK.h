#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct QueueNode QueueNode_t;
typedef struct Queue Queue_t;

QueueNode_t* queueNode_create(int value);
Queue_t* queue_create();
int queue_empty(Queue_t* queue);
void queue_enqueue(Queue_t* queue, int item);
int queue_count(Queue_t* queue);
int queue_dequeue(Queue_t* queue);
void queue_free(Queue_t* queue);

#endif