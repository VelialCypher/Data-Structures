#pragma once
#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue Queue_t;

Queue_t* queue_create(int capacity);
int queue_empty(Queue_t* queue);
int queue_full(Queue_t* queue);
int queue_dequeue(Queue_t* queue);
void queue_enqueue(Queue_t* queue, int item);
int queue_peek(Queue_t* queue);
int queue_count(Queue_t* queue);
void queue_free(Queue_t* queue);

#endif