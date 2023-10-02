//
// Created by Kirill on 10/2/23.
//
#include "stdio.h"
#include "biblio.h"
#include "stdlib.h"

int main () {
    int * numbers = (int *) malloc(sizeof(int));
    int length = 0;
    while(1)
    {
        int number;
        int nbtokens = scanf("%d", &number);
        if (nbtokens != 1 || feof(stdin))
            break;
        if (length > 1) {
            numbers = realloc(numbers, sizeof(int) * length);
        }
        numbers[length] = number;
        length += 1;
    }
    printf("Sum: %d\n", sum(numbers, length));
    printf("Product: %d\n", product(numbers, length));
    printf("Average: %.2f\n", average(numbers, length));
    free(numbers);
    return 0;

}
