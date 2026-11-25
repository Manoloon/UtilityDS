#include "queue.h"
#include<stdio.h>
#include <stdlib.h>

typedef struct qnode_s
{
    void* data;
    struct qnode_s* next;
}qnode_t;

typedef struct queue_s
{
    qnode_t* front;
    qnode_t* back;
}queue_t;

queue_t *create_queue()
{
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    if(q == NULL)
    {
        fprintf(stderr,"Create queue : failed to malloc\n");
        return NULL;
    }
    q->front = NULL;
    q->back = NULL;
    return q;
}

bool queue_is_empty(queue_t *q)
{
    if(q == NULL)
    {
        return false;
    }
    return q->front == NULL;
}

bool enqueue(queue_t *q,const void* item)
{
    if(q == NULL)
    {
        return false;
    }
    qnode_t* node = (qnode_t*)malloc(sizeof(qnode_t));
    if(node == NULL)
    {
        printf("enqueue : cannot malloc for node\n");
        return false;
    }
    node->data = item;
    node->next = NULL;
    if(queue_is_empty(q))
    {
        q->back = node;
        q->front = node;
    }
    else
    {
        q->back->next = node;
        q->back = node;
    }
    return true;
}

void* dequeue(queue_t *q)
{
    if(q == NULL) return NULL;
    if(queue_is_empty(q)) return NULL;
    qnode_t* temp = q->front;
    void* result = temp->data;
    q->front = q->front->next;
    if(queue_is_empty(q))
    {
        q->back = NULL;
    }
    free(temp);
    return result;
}

void* peek(queue_t *q)
{
    if(q == NULL || queue_is_empty(q)) return NULL;
    return q->front->data;
}
