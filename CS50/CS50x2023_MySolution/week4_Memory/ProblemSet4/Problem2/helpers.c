#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            double average = 0.299 * red + 0.587 * green + 0.114 * blue;
            // double average = (red + green + blue)/3.0;
            image[i][j].rgbtBlue=average;
            image[i][j].rgbtGreen=average;
            image[i][j].rgbtRed=average;
        }
        
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width/2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j]=image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
        
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            double sumR=0,sumG=0,sumB=0,cnt=0;

            for(int row=-1;row<=1;row++){
                for(int col=-1;col<=1;col++){
                    if((i+row<0)||(i+row>=height)||(j+col<0)||(j+col>=width)) continue;
                    sumR += image[i+row][j+col].rgbtRed;
                    sumG += image[i+row][j+col].rgbtGreen;
                    sumB += image[i+row][j+col].rgbtBlue;
                    cnt++;
                }
            }

            if(cnt>0){
                temp[i][j].rgbtRed = sumR/cnt;
                temp[i][j].rgbtGreen = sumG/cnt;
                temp[i][j].rgbtBlue = sumB/cnt;
            }else{
                temp[i][j]=image[i][j];
            }

        }
        
    }

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            image[i][j]=temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxBlue = 0;
            int gyBlue = 0;
            int gxGreen = 0;
            int gyGreen = 0;
            int gxRed = 0;
            int gyRed = 0;

            for (int row = -1; row < 2; row++)
            {
                for (int col = -1; col < 2; col++)
                {
                    if (i + row < 0 || i + row >= height)continue;
                    if (j + col < 0 || j + col >= width)continue;

                    gxBlue += image[i + row][j + col].rgbtBlue * gx[row + 1][col + 1];
                    gyBlue += image[i + row][j + col].rgbtBlue * gy[row + 1][col + 1];
                    gxGreen += image[i + row][j + col].rgbtGreen * gx[row + 1][col + 1];
                    gyGreen += image[i + row][j + col].rgbtGreen * gy[row + 1][col + 1];
                    gxRed += image[i + row][j + col].rgbtRed * gx[row + 1][col + 1];
                    gyRed += image[i + row][j + col].rgbtRed * gy[row + 1][col + 1];
                }
            }

            int blue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            int green = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int red = round(sqrt(gxRed * gxRed + gyRed * gyRed));

            temp[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
            temp[i][j].rgbtGreen = (green > 255) ? 255 : green;
            temp[i][j].rgbtRed = (red > 255) ? 255 : red;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           image[i][j]=temp[i][j];
        }
    }

    return ;
}