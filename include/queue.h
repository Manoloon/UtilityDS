#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

/*
    Simple Queue
*/

typedef struct qnode_s qnode_t;
typedef struct queue_s queue_t;

queue_t* create_queue();

bool queue_is_empty(queue_t* q);

bool enqueue(queue_t* q, const void* item);

void* dequeue(queue_t* q);

void* peek(queue_t* q);

#endif
