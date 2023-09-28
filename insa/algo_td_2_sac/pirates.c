//
// Created by Kirill on 9/27/23.
//
//
// Created by Kirill on 9/27/23.
//
#include "stdio.h"
int main() {
    int capacity;
    int objects_count_1;
    int objects_count = 0;
    int objects[100];
    int k;
    int i;
    int maxWeightSolution = 0;

    scanf("%d", &capacity);
    scanf("%d", &objects_count_1);
    objects_count += objects_count_1;
    scanf("%d", &objects_count_1);
    objects_count += objects_count_1;


    int objectsCounter = 0;
    int object;
    while (1) {
        if (objectsCounter == objects_count) {
            break;
        }
        else {
            scanf("%d", &object);
            if (object < 50) {
                objects[objectsCounter] = object;
                objectsCounter += 1;
            }
            else {
                objects_count -= 1;
            }
        }
    }

    int solutions[100][10000];
    int currentSolution;
    int newObjectWeight;

    // base cases
    for (k = 0; k < 100; k++) {
        solutions[k][0] = 1;
    }

    for (k = 1; k < 10000; k++) {
        solutions[0][k] = 0;
    }

    // k - capacities; i - weights
    for (k = 1; k < capacity + 1; k++) {
        for (i = 1; i < objectsCounter + 1; i++) {
            newObjectWeight = objects[i-1];
            currentSolution = solutions[i-1][k];
            if ((k - newObjectWeight) >= 0) {
                currentSolution += solutions[i-1][k-newObjectWeight];
            }
            if (currentSolution > 0) {
                currentSolution = 1;
                if (maxWeightSolution < k) {
                    maxWeightSolution = k;
                }
            }
            solutions[i][k] = currentSolution;
        }
    }
    printf("%d\r\n", maxWeightSolution);
    return 0;
}
