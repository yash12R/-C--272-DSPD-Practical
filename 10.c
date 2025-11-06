#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourceName[100], destName[100];
    char ch;

    // Get file names from user
    printf("Enter source file name (e.g., input.txt): ");
    scanf("%s", sourceName);

    printf("Enter destination file name (e.g., output.txt): ");
    scanf("%s", destName);

    // Open source file in read mode
    sourceFile = fopen(sourceName, "r");
    if (sourceFile == NULL) {
        printf("Error: Cannot open source file %s\n", sourceName);
        exit(1);
    }

    // Create destination file in write mode
    destFile = fopen(destName, "w");
    if (destFile == NULL) {
        printf("Error: Cannot create destination file %s\n", destName);
        fclose(sourceFile);
        exit(1);
    }

    // Copy contents from source to destination
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("\nFile copied successfully from %s to %s\n", sourceName, destName);

    // Close both files
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
