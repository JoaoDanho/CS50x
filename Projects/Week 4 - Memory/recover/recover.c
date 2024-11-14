#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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

    // If the file cannot be opened, print an error and return
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // Variable to track the output file number
    int jpg_count = 0;

    // Variable to store the current JPEG file
    FILE *jpg = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check if the start of a JPEG is found (0xFF, 0xD8, 0xFF, 0xE0 to 0xE7)
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF &&
            (buffer[3] >= 0xE0 && buffer[3] <= 0xEF))
        {
            // If already found a JPEG, close the previous file
            if (jpg != NULL)
            {
                fclose(jpg);
            }

            // Create a new JPEG file
            char filename[8];
            sprintf(filename, "%03i.jpg", jpg_count);
            jpg = fopen(filename, "w");

            // Increment the counter for the next file
            jpg_count++;
        }

        // If we're currently writing to a JPEG file, write the buffer to the file
        if (jpg != NULL)
        {
            fwrite(buffer, 1, 512, jpg);
        }
    }

    // Close the last JPEG file if it was opened
    if (jpg != NULL)
    {
        fclose(jpg);
    }

    // Close the memory card file
    fclose(card);

    return 0;
}
