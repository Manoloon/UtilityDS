#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

/*
    Simple Queue
*/

typedef struct qnode_s qnode_t;
typedef struct queue_s queue_t;

queue_t* create_queue();

bool is_empty(queue_t* q);

bool enqueue(queue_t* q, int val);

int dequeue(queue_t* q);

int peek(queue_t* q);

void queue_test();

#endif
