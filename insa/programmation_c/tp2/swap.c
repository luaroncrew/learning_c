//
// Created by Kirill on 9/26/23.
//
#include "stdio.h"

void swap(int * a, int * b) {
    int swap;
    swap = *a;
    *a = *b;
    *b = swap;
}

int main() {
    int a_main = 12;
    int b_main = 4;
    printf("%d %d \n", a_main, b_main);
    swap(&a_main, &b_main);
    printf("%d %d \n", a_main, b_main);
    return 0;
}
