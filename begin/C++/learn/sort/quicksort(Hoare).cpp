#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

char** read_lines_from_file(const char* filename, int* numLines) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Initialize variables
    char** lines = NULL;
    char buffer[MAX_LINE_LENGTH];
    int count = 0;

    // Read lines from the file
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Remove newline character, if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // Allocate memory for the line
        char* line = strdup(buffer) ;
        if (line == NULL) {
            perror("Error allocating memory");
            exit(EXIT_FAILURE);
        }

        // Resize the array to hold the new line
        lines = realloc(lines, (count + 1) * sizeof(char*));
        if (lines == NULL) {
            perror("Error reallocating memory");
            exit(EXIT_FAILURE);
        }

        // Store the line in the array
        lines[count++] = line;
    }

    // Close the file
    fclose(file);

    // Set the number of lines
    *numLines = count;

    return lines;
}

void insert_number_to_file(const char* filename, double num, int new_line) {
    // Open the file in append mode
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        // If the file does not exist, create it
        file = fopen(filename, "w");
        if (file == NULL) {
            perror("Error opening file");
            return;
        }
    }

    // Append the integer to the file
    if (new_line) {
        fprintf(file, "\n%.2lf", num);    
    }
    else {
        fprintf(file, "%.2lf", num); 
    }

    // Close the file
    fclose(file);
}

void insert_text_to_file(const char* filename, const char* str) {
    // Open the file in append mode
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        // If the file does not exist, create it
        file = fopen(filename, "w");
        if (file == NULL) {
            perror("Error opening file");
            return;
        }
    }

    // Append the string to the file
    fprintf(file, "%s", str);

    // Close the file
    fclose(file);
}