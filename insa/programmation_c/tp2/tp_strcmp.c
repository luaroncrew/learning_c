//
// Created by Kirill on 9/26/23.
//
#include "stdio.h"
#include "strings.h"
#define TRUE_RETURN 0
#define FIRST_STRING_BIGGER_RETURN 1
#define SECOND_STRING_BIGGER_RETURN -1


int compareStrings(char * string1, char * string2) {
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    int leastLength;
    if (length1 > length2) {
        leastLength = length2;
    } else {
        leastLength = length1;
    }
    for (int k = 0; k < leastLength; k++) {
        if (string1[k] > string2[k]) {
            return FIRST_STRING_BIGGER_RETURN;
        }
        if (string1[k] < string2[k]) {
            return SECOND_STRING_BIGGER_RETURN;
        }
    }
    return TRUE_RETURN;
}



int main() {
    char inputString1[] = "Kirill";
    char inputString2[] = "Kirall";

    printf("%d", compareStrings(inputString1, inputString2));

    return 0;
}


