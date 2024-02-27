/**
 * @file util.h
 * @author João Ribeiro
 * @date 30-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains functions for get input and clean buffer.
 */

#include "design.h"
#include "functions.h"
#include "structs.h"

void cleanInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int getInt(int minValue, int maxValue, char *msg) {
    int value;
    printf(msg);
    while (scanf("%d", &value) != 1 || value < minValue || value > maxValue) {
        puts(ERROR_INVALID_VALUE);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return value;
}

void readString(char *string, unsigned int size, char *msg) {
    printf(msg);
    if (fgets(string, size, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            cleanInputBuffer();
        }
    }
}