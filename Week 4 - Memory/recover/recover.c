#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // Create a buffer for a block of data
    uint8_t buffer[512];
    FILE *outfile = NULL;
    char filename[8];
    int filecount = 0;
    int is_file_open = 0;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Create JPEGs from the data

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (is_file_open)
            {
                fclose(outfile);
            }

            sprintf(filename, "%03i.jpg", filecount);
            outfile = fopen(filename, "w");

            if (outfile == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", filename);
                fclose(card);
                return 1;
            }

            filecount++;
            is_file_open = 1;
        }

        if (is_file_open)
        {
            fwrite(buffer, sizeof(BYTE), 512, outfile);
        }
    }

    if (is_file_open)
    {
        fclose(outfile);
    }

    fclose(card);

    return 0;
}
