#include <stdio.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *q;
};

//Pass queue address as parameter
void enqueue(struct Queue *queue, int value){
    if(queue->rear == queue->size-1){
        printf("Queue is already full!\n");
    }else{
        queue->rear++;
        queue->q[queue->rear] = value;
    }
}

//Pass queue address as parameter
int dequeue(struct Queue *queue){
    if(queue->front == queue->rear){
        printf("Queue is already empty!\n");
        return -1;
    }else{
        queue->front++;
        int x = queue->q[queue->rear];
        printf("Dequeued value %d\n", x);
        queue->q[queue->rear] = 0;
        return x;
    }
}

int main() {
    struct Queue qu;
    qu.front = qu.rear = -1;
    printf("Enter size of queue: \n");
    scanf("%d", &qu.size);
    qu.q = (int *)malloc(qu.size * sizeof(int));
    enqueue(&qu, 5);
    enqueue(&qu, 7);
    dequeue(&qu);

    return 0;
}
