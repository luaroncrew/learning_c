//
// Created by Kirill on 10/2/23.
//

int sum(int * array, int length) {
    int counter = 0;
    int i;
    for (i = 0; i < length; i++) {
        counter += array[i];
    }
    return counter;
}


int product(int * array, int length) {
    int counter = 1;
    int i;
    for (i = 0; i < length; i++) {
        counter *= array[i];
    }
    return counter;
}

float average(int * array, int length) {
    float counter = 0.0;
    int i;
    for (i = 0; i < length; i++) {
        counter += (float) array[i];
    }
    return counter / (float) length;
}