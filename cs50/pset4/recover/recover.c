#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define BLOCKSIZE 512

bool isJpg(uint8_t buffer[]);

int main(int argc, char *argv[])
{
    // 1 Check argc
    // 2 Open file and check if is != NULL && create outputFile;
    // 3 Create buffer, jpgCount, bool flag if is 1st jpg and filename holder;
    // 4 fread in
    //   4.1 check if isJpg
    //     4.1.1 check if not 1st jpg
    //       4.1.1.1 set is 1st to true
    //       4.1.1.1 else close outputFile
    //     4.1.2 send formatted output to a string pointed to, by str && increase jpg count
    //           we gona write in here
    //     4.1.3 open output file ... and check it ...
    //     4.1.4 write buffer inside
    //   4.1 else if is 1st jpg write buffer inside

    if (argc != 2)
        return 1;

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = NULL;
    if (inputFile == NULL)
        return 1;

    uint8_t buffer[BLOCKSIZE];
    int jpgCount = 0;
    bool is_1st_jpg = false;
    char filename[8];

    while (fread(buffer, BLOCKSIZE, 1, inputFile))
    {
        if (isJpg(buffer))
        {
            if (!is_1st_jpg)
                is_1st_jpg = true;
            else
                fclose(outputFile);

            sprintf(filename, "%03i.jpg", jpgCount++);
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