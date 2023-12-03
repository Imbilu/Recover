#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    // Remember file names
    char *infile = argv[1];
    FILE *inpt = fopen(infile, "r");
    if (inpt == NULL)
    {
        printf("Unsurpoted format\n");
        return 1;
    }
    // Read 512 bytes into a buffer.
    unsigned char buffer[512];
    int count = 0; // JPEG count

    FILE *img = NULL;

    // Repeat until end of card:
    while (fread(buffer, 512, 1, inpt) == 1)
    {
        // If start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the current file.
            if (img != NULL)
            {
                fclose(img);
            }

            // Open a new file.
            char filename[9];
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            count++;
        }

        // If already found a JPEG, write to the file
        if (count > 0)
        {
            // write 512 bytes until a new jpg is found
            fwrite(buffer, 512, 1, img);
        }
    }
    // Close any remaining files.
    fclose(img);
    fclose(inpt);
}
