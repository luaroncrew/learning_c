//
// Created by Kirill on 10/2/23.
//
#include "stdio.h"
#include "strings.h"
#include "stdlib.h"

typedef struct Person {
    char phoneNumber[11];
    char * name;
} Person;


int main() {
    int PEOPLE_COUNT = 3;
    int k;
    Person repertory[PEOPLE_COUNT];
    for (k = 0; k < PEOPLE_COUNT; k++) {
        Person currentPerson;
        scanf("%s", currentPerson.phoneNumber);

        char name[1000];
        scanf("%s", name);
        int i;
        currentPerson.name = malloc(sizeof (char) * strlen(name) + 1);
        for (i = 0; i < strlen(name) + 1; i++) {
            currentPerson.name[i] = name[i];
        }
        printf("person: %s \nphone number: %s \n", currentPerson.name, currentPerson.phoneNumber);
        repertory[k] = currentPerson;
    }
}