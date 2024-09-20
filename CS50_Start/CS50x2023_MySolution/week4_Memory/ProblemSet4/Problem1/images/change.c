#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)  // 确保结构体按字节对齐
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

typedef struct {
    unsigned char r, g, b;
} RGBTRIPLE;

void convertTo24BitBMP(const char *inputFile, const char *outputFile) {
    FILE *inptr = fopen(inputFile, "rb");
    if (inptr == NULL) {
        perror("Error opening input file");
        return;
    }

    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;

    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    if (bf.bfType != 0x4D42) {
        printf("Unsupported file format.\n");
        fclose(inptr);
        return;
    }

    int width = bi.biWidth;
    int height = abs(bi.biHeight);
    int padding = (4 - (width * 3) % 4) % 4;
    unsigned int imageSize = width * height * 3 + padding * height;

    if (bi.biBitCount == 32) {
        printf("Converting 32-bit BMP to 24-bit BMP.\n");
        bi.biBitCount = 24;
        bi.biSizeImage = imageSize;
    } else if (bi.biBitCount != 24) {
        printf("Unsupported bit count: %d\n", bi.biBitCount);
        fclose(inptr);
        return;
    }

    bf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + imageSize;

    FILE *outptr = fopen(outputFile, "wb");
    if (outptr == NULL) {
        perror("Error opening output file");
        fclose(inptr);
        return;
    }

    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    unsigned char *pixels = (unsigned char *)malloc(imageSize);
    if (!pixels) {
        perror("Unable to allocate memory for pixel data");
        fclose(inptr);
        fclose(outptr);
        return;
    }

    fseek(inptr, bf.bfOffBits, SEEK_SET);
    fread(pixels, 1, imageSize, inptr);

    if (bi.biBitCount == 32) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int idx = (i * width + j) * 4;  // 32位图像，每个像素4个字节
                int rgbIdx = (i * width + j) * 3;  // 24位图像，每个像素3个字节
                pixels[rgbIdx] = pixels[idx];      // R
                pixels[rgbIdx + 1] = pixels[idx + 1];  // G
                pixels[rgbIdx + 2] = pixels[idx + 2];  // B
            }
            fwrite(pixels + i * width * 3, 1, width * 3, outptr);
            for (int p = 0; p < padding; p++) {
                fputc(0x00, outptr);
            }
        }
    } else {
        fwrite(pixels, 1, imageSize, outptr);
    }

    free(pixels);
    fclose(inptr);
    fclose(outptr);
}

int main() {
    const char *inputFile = "D:/Projects/VscodeProjects/Life_Long_Learning/CS50_Start/CS50x2023_MySolution/week4_Memory/ProblemSet4/Problem1/images/00.bmp";  // 替换为实际输入文件名
    const char *outputFile = "D:/Projects/VscodeProjects/Life_Long_Learning/CS50_Start/CS50x2023_MySolution/week4_Memory/ProblemSet4/Problem1/images/output.bmp"; // 替换为实际输出文件名

    convertTo24BitBMP(inputFile, outputFile);
    return 0;
}