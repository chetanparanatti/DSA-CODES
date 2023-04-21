#include <stdio.h>
#include <string.h>

// function to find pattern in a line
int findPattern(char *line, char *pattern) {
    int i, j, k, line_len, pat_len;
    line_len = strlen(line);
    pat_len = strlen(pattern);

    for (i = 0; i <= line_len - pat_len; i++) {
        j = 0;
        k = i;
        while (line[k] == pattern[j] && j < pat_len) {
            j++;
            k++;
        }
        if (j == pat_len) {
            return 1; // pattern found
        }
    }
    return 0; // pattern not found
}

// function to read lines from file and find pattern
void readFromFile(char *file_name, char *pattern) {
    FILE *file;
    char line[100];

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        if (findPattern(line, pattern)) {
            printf("%s", line);
        }
    }

    fclose(file);
}

// function to read lines from user input and find pattern
void readFromUser(char *pattern) {
    char line[100];
    int i;

    printf("Enter up to 10 lines:\n");
    for (i = 1; i <= 10; i++) {
        printf("Line %d: ", i);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }
        if (findPattern(line, pattern)) {
            printf("%s", line);
        }
    }
}

// main function
int main() {
    char pattern[20];
    int option;

    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    printf("Enter option:\n");
    printf("1. Read from user input\n");
    printf("2. Read from file\n");
    printf("Option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            readFromUser(pattern);
            break;
        case 2:
            readFromFile("input.txt", pattern);
            break;
        default:
            printf("Invalid option\n");
    }

    return 0;
}
