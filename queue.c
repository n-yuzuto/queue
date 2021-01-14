#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


Queue *create_queue(int len){
    Queue *queue=(Queue*)malloc(sizeof(Queue));
    if(queue != NULL){
        queue -> buffer = malloc(sizeof(int)*len);
        queue -> front = 0;
        queue -> rear = 0;
        queue -> length = len;
        queue -> count = 0;
        if(queue -> buffer == NULL){
            free(queue);
            exit(EXIT_FAILURE);
        }
    }
    printf("Queue created!\n");
    return queue;
}


void enqueue(Queue *queue,int d){
    if(queue -> count == queue -> length){
        printf("Queue Overflow !!\n");
        
    }
    else{
        queue -> buffer[queue -> rear] = d;
        if(queue -> rear == queue -> length-1){
            queue -> rear = 0;
        }
        else{
            queue -> rear += 1;
        }
        queue -> count += 1;
    }
}


int dequeue(Queue *queue){
    int number;
    if(queue -> count == 0){
        printf("Queue Underflow!!");
        return EXIT_FAILURE;
    }
    else{
        number = queue -> buffer[queue -> front];
        if(queue -> front == queue -> length -1){
            queue -> front = 0;
        }
        else{
            queue -> front += 1;
        }
        queue -> count -= 1;
        return number;
    }
}
typedef struct queue {
  int *buffer;
  int length;
  int front;
  int rear;
  int count;
} Queue;

void display(Queue *queue) {
    if (queue -> count == 0) {
        printf("Empty queue!");
    }
    else if (queue -> rear > queue -> front) {
        int temp = queue -> front;
        while (temp != queue-> rear) {
            printf("%d ", queue -> buffer[temp]);
            temp += 1;
        }
    }
    else {
        int temp = queue -> front;
        while (temp != queue -> length) {
            printf("%d ", queue -> buffer[temp]);
            temp += 1;
        }
        temp = 0;
        while (temp != queue -> rear) {
            printf("%d ", queue -> buffer[temp]);
            temp += 1;
        }
    }
    printf("\n");
}

void delete_queue(Queue *queue){
    free(queue);
    printf("Queue deleted!\n");
}