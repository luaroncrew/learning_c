//
// Created by Kirill on 9/26/23.
//
#include "stdio.h"
int main() {
    int tab[10];
    printf("%d \n", sizeof(int));
    printf("%lu \n", (tab+4));
    printf("%lu \n", (tab+1));

    unsigned long tabplusfour = (unsigned long) (tab + 4);
    unsigned long tabplusone = (unsigned long) (tab + 1);
    unsigned long result = tabplusfour - tabplusone;

    printf("%d \n", result);
}