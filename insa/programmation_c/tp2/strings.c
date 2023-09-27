//
// Created by Kirill on 9/26/23.
//
#include "stdio.h"
#include "strings.h"
int main() {
    char string[100] = "<-_->";
    int length = strlen(string);

    for (int k = 0; k < length; k++) {
        printf("%c.", string[k]);
    }
    return 0;
}
