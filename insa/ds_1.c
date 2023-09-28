//
// Created by Kirill on 9/27/23.
//
#include "stdio.h"
int main() {
    int oddNumbersCount = 0;
    int evenNumbersCount = 0;
    int numbersCount;
    int counter = 0;
    int currentNumber;

    scanf("%d", &numbersCount);
    while (counter < numbersCount) {
        scanf("%d", &currentNumber);
        if ((currentNumber % 2) == 0) {
            evenNumbersCount += 1;
        } else {
            oddNumbersCount += 1;
        }
        counter += 1;
    }

    if (evenNumbersCount > oddNumbersCount) {
        printf("P\r\n");
    } else if (oddNumbersCount > evenNumbersCount) {
        printf("I\r\n");
    } else {
        printf("=\r\n");
    }
    return 0;
}
