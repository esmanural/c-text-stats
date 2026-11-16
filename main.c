#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void analyze_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    int characters = 0;
    int words = 0;
    int lines = 0;
    int in_word = 0;

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        characters++;

        if (ch == '\n') {
            lines++;
        }

        if (isspace(ch)) {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            words++;
        }
    }

    fclose(file);

    printf("--- C Text Statistics ---\n");
    printf("File: %s\n", filename);
    printf("Lines: %d\n", lines + (characters > 0 ? 1 : 0));
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);
}

int main(int argc, char *argv[]) {
    // If a filename is passed as an argument, use it. Otherwise, use a default sample file.
    const char *filename = (argc > 1) ? argv[1] : "sample.txt";
    
    // For demonstration, let's analyze the file
    analyze_file(filename);

    return 0;
}
