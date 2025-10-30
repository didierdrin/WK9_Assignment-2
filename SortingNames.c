#include <stdio.h>
#include <string.h>

#define MAX_NAMES 20
#define NAME_LENGTH 50

// Function to swap two strings
void swap(char *str1, char *str2) {
    char temp[NAME_LENGTH];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

// Function for ascending order sorting
void sortAscending(char names[][NAME_LENGTH], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                swap(names[j], names[j + 1]);
            }
        }
    }
}

// Function for descending order sorting
void sortDescending(char names[][NAME_LENGTH], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) < 0) {
                swap(names[j], names[j + 1]);
            }
        }
    }
}

