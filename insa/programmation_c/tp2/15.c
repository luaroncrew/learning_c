//
// Created by Kirill on 9/26/23.
//
#include "stdio.h"

int main() {
    double matrix[20];
    for (int k = 0; k < 20; k++) {
        printf("%lu \n", (unsigned long) (&matrix[k]));
    }
}