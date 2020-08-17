// 배열로 Queue 만들기 (정확하게는 원형큐)

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int front;
    int rear;
    int size;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    if(!queue){
        printf("failed to create queue\n");
        exit(1);
    }
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity-1;
    queue->array = (int *)malloc(sizeof(int)*queue->capacity);
    if(!(queue->array))
        exit(1);
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("queue is full. can't enqueue\n");
        return;
    }
    queue->size++;
    queue->rear = (++queue->rear)%(queue->capacity);
    queue->array[queue->rear] = item;
    printf("%d enqueued to queue\n", item);
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("queue is empty. can't dequeue\n");
        return;
    }
    queue->size--;
    printf("%d dequeued from queue\n", queue->array[queue->front]);
    queue->front = (++queue->front)%(queue->capacity);
}


int main() {
    Queue* queue = createQueue(4);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 40);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 40);

    dequeue(queue);
    dequeue(queue);
    return 0;
}
