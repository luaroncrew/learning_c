#include <stdio.h>

int main() {
    int val = 10001;
    /* Completer le code */
    switch (val) {
        case 100 ... 1000:
            printf("too small");
            break;
        case 1001 ... 10000:
            printf("too big");
            break;
        case 10001:
            printf("perfect");
            break;
        default:
            printf("sorry not sorry");
    }
}