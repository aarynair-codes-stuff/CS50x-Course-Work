#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    // Check if file was correctly opened
    if (card == NULL)
    {
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // Initialise variables to be used in the loop
    int count = 0;
    char filename[8];
    FILE *img = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Create JPEGs from the data
        // If the header is a JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If it isn't the first file
            if (count != 0)
            {
                // Close the previous file
                fclose(img);
            }
            // Initialise the new filename and open it
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            // Write to the file and update the count variable for the next file
            fwrite(buffer, 1, 512, img);
            count++;
        }
        // If the header isn't a JPEG header
        else
        {
            // If the count is 0 but an image file is open
            if (count == 0 && img != NULL)
            {
                // Write to the file
                fwrite(buffer, 1, 512, img);
            }
            // If a file has already been created
            else if (count > 0)
            {
                // Write to the file
                fwrite(buffer, 1, 512, img);
            }
        }
    }

    // Close any open files
    fclose(img);
    fclose(card);
}
