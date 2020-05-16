#include <stdio.h>
#include <stdlib.h>

#include "colors.h"

char* readFile(const char* path) {
    FILE* file = fopen(path, "rb");

    if (file == NULL) {
        fprintf(stderr, ANSI_COLOR_RED "Could not open file \"%s\"." ANSI_COLOR_RESET "\n", path);
        exit(74);
    }

    fseek(file, 0L, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(fileSize + 1);

    if (buffer == NULL) {
        fprintf(stderr, ANSI_COLOR_RED "Not enough memory to read \"%s\"." ANSI_COLOR_RESET "\n", path);
        exit(74);
    }

    size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);

    if (bytesRead < fileSize) {
        fprintf(stderr, ANSI_COLOR_RED "Could not read file \"%s\"." ANSI_COLOR_RESET "\n", path);
        exit(74);
    }

    buffer[bytesRead] = '\0';

    fclose(file);

    return buffer;
}