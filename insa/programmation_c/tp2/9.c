//
// Created by Kirill on 9/26/23.
//
#include "stdio.h"

int main() {
    double matrix[2][10];
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 10; i++) {
            printf("%lu \n", (unsigned long) (&matrix[k][i]));
        }
    }
}