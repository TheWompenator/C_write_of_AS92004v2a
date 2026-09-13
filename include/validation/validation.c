//
// Created by isaiahe on 08/09/2026.
//

#include "validation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *end;

char getValidCharInput(char validChars[]) {
    for (;;) {
        char inputChar[100];
        fgets(inputChar, sizeof(inputChar), stdin);
        if (inputChar[0] != '\n' && strchr(validChars, inputChar[0]) != NULL) {
            return inputChar[0];
        }
        printf("Invalid input. Please try again.\n");
    }
}

long getValidLongInput(long lowerBound, long upperBound) {
    for (;;) {
        char input[100];
        fgets(input, sizeof(input), stdin);
        long returnValue = strtol(input, &end, 10);
        if (end != input) {
            if (returnValue >= lowerBound && returnValue <= upperBound) {
                return returnValue;
            }
        }
        printf("Invalid input. Please try again.\n");
    }
}