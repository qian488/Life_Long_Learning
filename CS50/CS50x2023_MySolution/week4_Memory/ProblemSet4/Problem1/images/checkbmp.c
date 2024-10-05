#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#pragma pack(1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;

int main() {
    const char *filename = "D:/Projects/VscodeProjects/Life_Long_Learning/CS50_Start/CS50x2023_MySolution/week4_Memory/ProblemSet4/Problem1/images/test.bmp";
    if (access(filename, F_OK) != -1) {
        printf("File exists.\n");
    } else {
        printf("File does not exist.\n");
    }
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;

    if (fread(&bf, sizeof(BITMAPFILEHEADER), 1, file) != 1 ||
        fread(&bi, sizeof(BITMAPINFOHEADER), 1, file) != 1) {
        perror("Error reading headers");
        fclose(file);
        return EXIT_FAILURE;
    }

    printf("bfType: %04X\n", bf.bfType);
    printf("bfSize: %u\n", bf.bfSize);
    printf("bfOffBits: %u\n", bf.bfOffBits);
    printf("biSize: %u\n", bi.biSize);
    printf("biWidth: %d\n", bi.biWidth);
    printf("biHeight: %d\n", bi.biHeight);
    printf("biPlanes: %u\n", bi.biPlanes);
    printf("biBitCount: %u\n", bi.biBitCount);
    printf("biCompression: %u\n", bi.biCompression);

    fclose(file);
    return EXIT_SUCCESS;
}