#include <stdio.h>
int main() {
    float average;
    float grades[3];
    grades[0] = 80.0;
    grades[1] = 85.0;
    grades[2] = 90.0;
    average = (grades[0] + grades[1] + grades[2]) / 3;
    printf("The average of the 3 grades is: %f \r\n", average);
    return 0;
}