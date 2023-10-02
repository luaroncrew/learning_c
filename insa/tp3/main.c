//
// Created by Kirill on 10/2/23.
//
#include "stdlib.h"
#include "stdio.h"
#include "biblio.h"

int main() {
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    // Dynamically allocate memory for the array
    int *array = (int *)malloc(length * sizeof(int));


    printf("Enter %d elements of the array:\n", length);
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }

    // Call functions and print results
    printf("Sum: %d\n", sum(array, length));
    printf("Product: %d\n", product(array, length));
    printf("Average: %.2f\n", average(array, length));

    // Free dynamically allocated memory
    free(array);

    return 0;
}
