#include <stdio.h>

int main() {
    int numbers[1000];
    
    int next_number = 0;
    int numbers_position = 0;

    while (1) {
        scanf("%d", &next_number);
        if (next_number == -1) {
            break;
        }
        numbers[numbers_position] = next_number;
        numbers_position += 1;
    }
    
    numbers_position -= 1;
    for (
        int verification_index = numbers_position;
        verification_index >= 0;
        verification_index--
        ) {
            if (numbers[verification_index] != numbers[numbers_position - verification_index]){
                printf("%d\r\n", 0);
                return 0;
            }
    }
    
    if (numbers_position == -1) {
        printf("%d\r\n", 0);
        return 0;
    }
    
    printf("%d\r\n", 1);
    return 0;
}
