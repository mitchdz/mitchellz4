#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "mitchellz4.h"

int verbose = 1;

void printHelp()
{
    // TODO: implement help message
    printf("TODO: make help message\n");
}


int main(int argc, char *argv[])
{
    char *inputFile = NULL, *outputFile = NULL;

    int opt;
    while((opt = getopt(argc, argv, "i:o:h")) != -1)
    {
        switch(opt)
        {
            case 'i':
                inputFile = strdup(optarg);
                break;
            case 'o':
                outputFile = strdup(optarg);
                break;
            case 'h':
                printHelp();
                break;
        }
    }

    if (verbose) printf("Input file: %s\n", inputFile);
    if (verbose) printf("Output file: %s\n", outputFile);

    if (inputFile == NULL || outputFile == NULL) {
        printf("ERROR: please define an input and output file\n");
        printHelp();
        return -1;
    }

    mlz4_error_t err;

    err = mitchellz4Compress(inputFile, outputFile);
    if (err != E_MLZ4_SUCCESS) {
        printf("ERROR: %s\n", mlz4_errordesc[err].message);
    }


}


mlz4_error_t mitchellz4Compress(char *inputFile, char*outputFile)
{
    mlz4_error_t err = E_MLZ4_SUCCESS;
    FILE *inFile;
    long fileSize;
    int c, i;


    // sanitize inputs
    if (inputFile == NULL || outputFile == NULL) {
        return E_MLZ4_INVALID_INPUT;
    }

    inFile = fopen(inputFile,"rb");

    if (inFile == NULL) {
        return E_MLZ4_FILE_NOT_FOUND;
    }

    // find filesize
    fseek(inFile, 0, SEEK_END);
    fileSize = ftell(inFile);
    rewind(inFile);

    printf("INFO: file is %lu bytes\n", fileSize);

    // read file and print bytes in hex
    for ( i = 0; c = getc(inFile) != EOF; i++) {
        printf("%02x", c);
        if ( i % 16 == 15)
            putchar('\n');
        else if ( i % 2 == 1)
            putchar(' ');
    }
    if (i % 16 != 0)
        putchar('\n');




cleanup:
    fclose(inFile);
    return err;
}





