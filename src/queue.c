#include "queue.h"
#include<stdio.h>
#include <stdlib.h>

typedef struct qnode_s
{
    int data;
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

bool is_empty(queue_t *q)
{
    if(q == NULL)
    {
        return false;
    }
    return q->front == NULL;
}

bool enqueue(queue_t *q, int val)
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
    node->data = val;
    node->next = NULL;
    if(is_empty(q))
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

int dequeue(queue_t *q)
{
    if(is_empty(q)) return -1;
    qnode_t* temp = q->front;
    int result = temp->data;
    q->front = q->front->next;
    if(is_empty(q))
    {
        q->back = NULL;
    }
    free(temp);
    return result;
}

int peek(queue_t *q)
{
    if(is_empty(q)) return -1;
    return q->front->data;
}

void queue_test()
{
    printf("Start Queue Test\n");
    queue_t* q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Queue : Front: %d\n", peek(q)); // 10

    printf("Queue : Dequeued: %d\n", dequeue(q)); // 10
    printf("Queue : Dequeued: %d\n", dequeue(q)); // 20

    enqueue(q, 40);

    printf("Queue : Front: %d\n", peek(q)); // 30

    while (!is_empty(q)) {
        printf("Queue : Dequeued: %d\n", dequeue(q));
    }
    free(q);
}
