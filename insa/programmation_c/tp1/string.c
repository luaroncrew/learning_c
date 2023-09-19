#include <stdio.h>
#include <string.h>

int main(){
    char name[15] = "John Smith";
    if (strncmp(name, "John", 4) == 0) {
        printf("Hello, John!\n");
    } else {
        printf("You are not John.\n");
    }
}
