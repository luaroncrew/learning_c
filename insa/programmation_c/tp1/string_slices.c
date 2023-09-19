#include <stdio.h>
#include <string.h>

int main(){
    char name[15] = "John Smith";
    char slice1[10];
    strncat(slice1, name, 9);
    printf("slice: %s\r\n", slice1);
    return 0;
}