//
// Created by Kirill on 10/3/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_MAX_LENGTH 100

typedef struct {
    int lastElementIndex;
    int firstElementIndex;
    int * array;
} Queue;

void Insert(Queue * queue, int value);
int Dequeue(Queue * queue, int * returnValue);

int main(void)
{
    char lecture[100];
    int val;
    int arr[100];
    Queue q = (Queue) {.firstElementIndex = 0, .lastElementIndex = 0, .array = arr};
    Queue * queue = &q;
    fscanf(stdin,"%99s",lecture);
    while (strcmp(lecture,"bye")!=0) {
        if (strcmp(lecture,"queue")==0) {
            fscanf(stdin,"%99s",lecture);
            val = strtol(lecture,NULL,10);
            Insert(queue,val);
        } else if (strcmp(lecture,"dequeue")==0) {
            int result = Dequeue(queue, &val);
            if (result)
            {
                printf("%d\r\n",val);
            }
        }
        fscanf(stdin,"%99s",lecture);
    }
    return 0;
}


void Insert(Queue * queue, int value) {
    int insertIndex = queue->lastElementIndex;
    queue->array[insertIndex] = value;
    if (insertIndex == QUEUE_MAX_LENGTH) {
        insertIndex = 0;
    } else {
        insertIndex += 1;
    }
    queue->lastElementIndex = insertIndex;
}

int Dequeue(Queue * queue, int * returnValue) {
    if (queue->lastElementIndex == queue->firstElementIndex) {
        return 0;
    }
    int extractIndex = queue->firstElementIndex;
    *returnValue = queue->array[extractIndex];
    if (extractIndex == QUEUE_MAX_LENGTH) {
        extractIndex = 0;
    } else {
        extractIndex += 1;
    }
    queue->firstElementIndex = extractIndex;
    return -1;
}