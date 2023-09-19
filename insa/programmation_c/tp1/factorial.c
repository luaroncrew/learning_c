#include <stdio.h>

int len_int(int* objects[], int* prototype) {
    int result = (sizeof(*objects) / sizeof(*prototype));
    return result;
}

int main() {
    int tab[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr_length = len_int(&tab, &tab[0]);
    int factorial = 1;
    for (int i = 1; i < arr_length; i++) {
        factorial = factorial * tab[i];
    }
    printf("%d\r\n", factorial);
    return 0;
}