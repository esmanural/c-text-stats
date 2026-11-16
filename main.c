#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_BUFFER_SIZE 128

// Advanced function to read a line dynamically using malloc/realloc
char* read_line_dynamically(FILE *file) {
    size_t size = INITIAL_BUFFER_SIZE;
    size_t len = 0;
    char *buffer = malloc(size);

    if (buffer == NULL) {
        printf("Memory allocation error!\n");
        return NULL;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF && ch != '\n') {
        buffer[len++] = (char)ch;
        if (len >= size - 1) {
            size *= 2;
            char *temp = realloc(buffer, size);
            if (temp == NULL) {
                free(buffer);
                printf("Memory reallocation error!\n");
                return NULL;
            }
            buffer = temp;
        }
    }

    if (ch == EOF && len == 0) {
        free(buffer);
        return NULL;
    }

    buffer[len] = '\0';
    return buffer;
}

void analyze_file_advanced(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    int total_lines = 0;
    int total_words = 0;
    int total_chars = 0;

    char *line;
    // Read file line by line using dynamic allocation
    while ((line = read_line_dynamically(file)) != NULL) {
        total_lines++;
        total_chars += strlen(line) + 1; // +1 for newline character

        int in_word = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (isspace(line[i])) {
                in_word = 0;
            } else if (in_word == 0) {
                in_word = 1;
                total_words++;
            }
        }

        // Crucial: Free the dynamically allocated memory for each line to prevent memory leaks!
        free(line);
    }

    fclose(file);

    printf("--- Advanced C Text Statistics (Dynamic Memory) ---\n");
    printf("File: %s\n", filename);
    printf("Lines: %d\n", total_lines);
    printf("Words: %d\n", total_words);
    printf("Characters: %d\n", total_chars);
}

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : "sample.txt";
    analyze_file_advanced(filename);
    return 0;
}
