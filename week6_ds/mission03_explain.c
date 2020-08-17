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
    // 메모리 할당 잘 되었는지 확인
    if(!queue){
        printf("failed to create queue\n");
        exit(1);
    }
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity-1; //  queue가 공백인 경우와 1개 든 경우에 모두 front=rear이므로 이 두 경우를 구분해주기 위해서.
    //empty인 상황에서 값을 enqueue 하나를 하게 되면 front=rear=0이 된다.
    queue->array = (int *)malloc(sizeof(int)*queue->capacity);
    // 메모리 할당 잘 되었는지 확인
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
    if (isFull(queue)) {    //큐가 꽉 찬 경우 enqueue를 못하므로 종료
        printf("queue is full. can't enqueue\n");
        return;
    }
    queue->size++;  //사이즈를 키워줌
    queue->rear = (++queue->rear)%(queue->capacity);    //0~(capacity-1) 값을 순환함. capacity가 10인 경우 0~9 10개의 값을 순환하게 된다.
    queue->array[queue->rear] = item;   //큐의 rear에 item값을 저장함
    printf("%d enqueued to queue\n", item);
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {   //큐가 빈 경우 dequeue를 못하므로 종료
        printf("queue is empty. can't dequeue\n");
        return;
    }
    queue->size--;  //사이즈를 줄여줌
    printf("%d dequeued from queue\n", queue->array[queue->front]); //삭제한다고 먼저 printf한 후 삭제시켜줌
    queue->front = (++queue->front)%(queue->capacity);  //front+1하고 capacity로 나눠줌. 이렇게하면 위와 똑같이 front 또한 0~(capacity-1)값을 순환함
}


int main() {
    Queue* queue = createQueue(1000);

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
    return 0;
}
