//
// Created by Kirill on 10/2/23.
//

#include "stdio.h"

typedef struct Complexe {
    float real;
    float imaginary;
} Complexe;


void affiche(Complexe z) {
    printf("%f", z.real);
    if (z.imaginary >= 0.0) {
        printf(" + %f i \n", z.imaginary);
    }
    else {
        printf(" - %f i \n", z.imaginary);
    }
}

int main() {
    float real;
    float img;

    scanf("%f", &real);
    scanf("%f", &img);

    Complexe complexNumber;
    complexNumber.imaginary = img;
    complexNumber.real = real;

    affiche(complexNumber);
}


