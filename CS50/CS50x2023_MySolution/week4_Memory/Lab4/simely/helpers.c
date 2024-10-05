#include "helpers.h"

// 调节RGB使得图像变色，我这里的颜色是我比较喜欢的天蓝色

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                image[i][j].rgbtRed = 135;
                image[i][j].rgbtGreen = 205;
                image[i][j].rgbtBlue = 250;
            }
        }
    }
}
