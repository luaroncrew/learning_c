//
// Created by Kirill on 9/28/23.
//

#include "stdio.h"
#include "strings.h"

#define RIGHT 0
#define BOTTOM 1
#define LEFT 2
#define UP 3

int main() {
    char commands[101];
    unsigned long commandsLength;
    int x = 0;
    int y = 0;
    int k = 0;
    int direction = RIGHT;
    char command;


    scanf("%s", commands);
    commandsLength = strlen(commands);

    for (k = 0; k < commandsLength; k++) {
        command = commands[k];
        if (command == 'A') {
            switch (direction) {
                case RIGHT:
                    x += 1;
                    break;
                case LEFT:
                    x -= 1;
                    break;
                case UP:
                    y -= 1;
                    break;
                case BOTTOM:
                    y += 1;
            }
        }
        else {
            if (command == 'D') {
                direction += 1;
                if (direction == 4) {
                    direction = 0;
                }
            }
            if (command == 'G') {
                direction -= 1;
                if (direction == -1) {
                    direction = 3;
                }
            }
        }
    }
    printf("%d\r\n", x);
    printf("%d\r\n", y);
    return 0;
}