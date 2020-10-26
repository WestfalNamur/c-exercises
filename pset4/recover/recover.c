#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t BYTE;

#define BLOCKSIZE 512

bool isJpg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    BYTE buffer[BLOCKSIZE];
    int file_index = 0;
    bool is_1st_jpg = false;
    FILE *outputFile;

    while (fread(buffer, BLOCKSIZE, 1, inputFile))
    {
        if (isJpg(buffer))
        {
            if (!is_1st_jpg)
                is_1st_jpg = true;
            else
                fclose(outputFile);

            char filename[8];
            sprintf(filename, "%03i.jpg", file_index++);
            outputFile = fopen(filename, "w");
            if (outputFile == NULL)
                return 1;
            fwrite(buffer, BLOCKSIZE, 1, outputFile);
        }
        else if (is_1st_jpg)
        {
            fwrite(buffer, BLOCKSIZE, 1, outputFile);
        }
    }

    return 0;
}

bool isJpg(uint8_t buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}