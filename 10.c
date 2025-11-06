#include <stdio.h>

#include <stdlib.h>



int main() {

    char inputFile[100], outputFile[100];

    FILE *source, *destination;

    char ch;



    // Get the file names from user

    printf("Enter the name of the input file: ");

    scanf("%s", inputFile);



    printf("Enter the name of the output file: ");

    scanf("%s", outputFile);



    // Open input file in read mode

    source = fopen(inputFile, "r");

    if (source == NULL) {

        printf("Error: Cannot open input file '%s'.\n", inputFile);

        exit(1);

    }



    // Open/create output file in write mode

    destination = fopen(outputFile, "w");

    if (destination == NULL) {

        printf("Error: Cannot create output file '%s'.\n", outputFile);

        fclose(source);

        exit(1);

    }



    // Copy contents from source to destination

    while ((ch = fgetc(source)) != EOF) {

        fputc(ch, destination);

    }



    printf("File copied successfully from '%s' to '%s'.\n", inputFile, outputFile);



    // Close both files

    fclose(source);

    fclose(destination);



    return 0;

}
