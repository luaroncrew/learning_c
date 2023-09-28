//
// Created by Kirill on 9/27/23.
//
#include "stdio.h"
int main() {
    int capacity;
    int objects[100];
    int k;
    int i;

    scanf("%d", &capacity);

    int objectsCounter = 0;
    int object;
    while (1) {
        scanf("%d", &object);
        if (object == -1) {
            break;
        }
        else {
            objects[objectsCounter] = object;
            objectsCounter += 1;
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
            }
            solutions[i][k] = currentSolution;
        }
    }
    if (solutions[objectsCounter][capacity] == 1) {
        printf("OUI\r\n");
    } else {
        printf("NON\r\n");
    }
    return 0;
}
