//
// Created by Kirill on 10/2/23.
//
#include "stdio.h"
#include "biblio.h"
#include "stdlib.h"

int main () {
    int length;
    scanf("%d", &length);
    int * tab = (int *) malloc(sizeof(int) * length);
    int element;
    for (int k = 0; k < length; k++) {
        scanf("%d", &element);
        tab[k] = element;
    }
    printf("Sum: %d\n", sum(tab, length));
    printf("Product: %d\n", product(tab, length));
    printf("Average: %.2f\n", average(tab, length));
}

