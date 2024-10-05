#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Error: usage ./reverse.c <input_file> <output_file>");
        return 1;
    }

    // Open input file for reading
     FILE *inputfile = fopen(argv[1], "rb");
    if (inputfile == NULL)
    {
        printf("Error: can't open file");
        return 1;
    }

    // Read header
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, inputfile);


    // Use check_format to ensure WAV format
    if (check_format(header) == 0)
    {
        printf("Error: file type not supported");
        return 1;
    }

    // Open output file for writing
    FILE *outputfile = fopen(argv[2], "wb");
    if (outputfile == NULL)
    {
        return 1;
    }

    // Write header to file
    fwrite(&header, sizeof(WAVHEADER), 1, outputfile);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(header);

    // Write reversed audio to file
    fseek(inputfile, block_size * -1, SEEK_END);
    while (ftell(inputfile) >= 44)
    {
        BYTE sound_piece[block_size];
        fread(sound_piece, block_size, 1, inputfile);
        fwrite(sound_piece, block_size, 1, outputfile);
        fseek(inputfile, block_size * 2 * -1, SEEK_CUR);
    }

    fclose(inputfile);
    fclose(outputfile);

    return 0;
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    int bytesPerSample = header.bitsPerSample / 8;
    return header.numChannels * bytesPerSample;
}