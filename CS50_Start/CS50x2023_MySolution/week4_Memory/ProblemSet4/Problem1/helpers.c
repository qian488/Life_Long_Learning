#include "helpers.h"
#include <math.h>

// 灰度化
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

// 棕褐色
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            int sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            int sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            int sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;
            // 确保颜色值在 0 到 255 之间
            sepiaRed = sepiaRed > 255 ? 255 : (sepiaRed < 0 ? 0 : sepiaRed);
            sepiaGreen = sepiaGreen > 255 ? 255 : (sepiaGreen < 0 ? 0 : sepiaGreen);
            sepiaBlue = sepiaBlue > 255 ? 255 : (sepiaBlue < 0 ? 0 : sepiaBlue);
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
        
    }
    
    return;
}

// 水平翻转
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

// 模糊
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
