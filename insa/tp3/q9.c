//
// Created by Kirill on 10/2/23.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct _elem
{
    int value;
    struct _elem* next;
} Elem;

void afficher(Elem * node);
void ajouter_en_tete(Elem ** lastNode);


int main(void)
{
    Elem * firstNode;
    firstNode = (Elem *) malloc(sizeof(Elem));
    firstNode->next = NULL;

    while(1)
    {
        printf("menu:\n");
        printf("\t1: ajouter en tete\n");
        printf("\t2: afficher la liste\n");
        printf("\t0: quitter\n");
        int choix;
        scanf("%d", &choix);
        switch(choix)
        {
            case 0:
                goto fin;
            case 1:
                ajouter_en_tete(&firstNode);
                break;
            case 2:
                afficher(firstNode);
                break;
            default:
                printf("choix incorrect\n");
                continue ;
        }
    }
    fin:
    printf("au revoir\n");
    return 0;
}


void ajouter_en_tete(Elem ** node) {
    int element;
    printf("give your element \n");
    scanf("%d", &element);
    Elem * newNode = (Elem *) malloc(sizeof(Elem));
    newNode->value = element;
    newNode->next = *node;
    *node = newNode;
    printf("element placed \n");
}


void afficher(Elem * node) {
    Elem * currentNode = node;
    while(1) {
        if (currentNode->next != NULL) {
            printf("%d \n", currentNode->value);
            currentNode = currentNode->next;
        }
        else {
            break;
        }
    }
}