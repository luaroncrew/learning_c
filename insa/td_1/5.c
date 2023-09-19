// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    printf("%d\r\n", n);
    int previous_term = n;
    int next_term;
    
    while(1) {
        if (previous_term % 2 == 0) {
            next_term = previous_term / 2;
        }
        else {
            next_term = previous_term * 3 + 1;
        }
        printf("%d\r\n", next_term);
        if (next_term == 1) {
            return 0;
        }
        previous_term = next_term;
    }
    return 0;
}
