#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Get an image: 3D array (height * width * RGB)
    // 1 Loop over rows (height)  // C is row
    //   2 Loop over row_i
    //     3 Calcualte grey value as rounded average of RGB values;
    //       Mutate RGB values to be the caclualted gery value;
    //
    // Hint:
    // The values of a pixel’s rgbtRed, rgbtGreen, and rgbtBlue components are
    // all integers, so be sure to round any floating-point numbers to the
    // nearest integer when assigning them to a pixel value!
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avrg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avrg;
            image[i][j].rgbtGreen = avrg;
            image[i][j].rgbtBlue = avrg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Get an image: 3D array (height * width * RGB)
    // 1 Loop over rows (height)  // C is row
    //   2 Loop over row_i
    //     3.1 Get pixel color values
    //     3.2 Calculate sepia colors with provided formula && round
    //     3.3 Assign the sepia colors as new values into img;
    //
    // Hint:
    // The values of a pixel’s rgbtRed, rgbtGreen, and rgbtBlue components are
    // all integers, so be sure to round any floating-point numbers to the
    // nearest integer when assigning them to a pixel value!
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float pxlValRed = image[i][j].rgbtRed;
            float pxlValGreen = image[i][j].rgbtGreen;
            float pxlValBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * pxlValRed + .769 * pxlValGreen + .189 * pxlValBlue);
            int sepiaGreen = round(.349 * pxlValRed + .686 * pxlValGreen + .168 * pxlValBlue);
            int sepiaBlue = round(.272 * pxlValRed + .534 * pxlValGreen + .131 * pxlValBlue);

            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Get an image: 3D array (height * width * RGB)
    // 1 Loop over rows (height)  // C is row
    //   2 Loop over row_i
    //     3.1 Store current pxlValColr;
    //     3.2 Get reflectedIndex: j = width - j - 1;
    //     3.3 Move pxlVals from right side of axis to corresponding pos in left side;
    //         [i][j] = [i][width - j - 1]
    //     3.4 Place the stored pxlValColr on right side;
    //         Note: As now [i][j] == [i][width - j - 1] we need to use the stored vals;
    //         [i][width - j - 1] = pxlVal*
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            float pxlValRed = image[i][j].rgbtRed;
            float pxlValGreen = image[i][j].rgbtGreen;
            float pxlValBlue = image[i][j].rgbtBlue;

            int indexReflected = width - j - 1;

            image[i][j].rgbtRed = image[i][indexReflected].rgbtRed;
            image[i][j].rgbtGreen = image[i][indexReflected].rgbtGreen;
            image[i][j].rgbtBlue = image[i][indexReflected].rgbtBlue;

            image[i][indexReflected].rgbtRed = pxlValRed;
            image[i][indexReflected].rgbtGreen = pxlValGreen;
            image[i][indexReflected].rgbtBlue = pxlValBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // 1 Make temporay copy of the image;
    //   1.1 Alloc memory space for RGBTRIPLE;
    //   1.2 Loop over and cp vals from origin img;
    // 2 Loop over cp
    //   2.1 creat sumVlas for pixel values;
    //   2.2 loop over neighbour pixels;
    //        Here direct neighbour: [-1, 0, 1]
    //     2.2.1 Check if neighbour pixel is in bound of image; Calc coordinate
    //           within imag and see if inbounds;
    //     2.2.2 If inbounds: add pxl color values sumPxlVal*;
    //   2.3 Set value within current imgTmp to blured value; Blured value is
    //       avrg-color-value of neighbours;
    // 3. Copy temp values into original;
    RGBTRIPLE imgTmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imgTmp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumPxlValRed = 0.0;
            float sumPxlValGreen = 0.0;
            float sumPxlValBlue = 0.0;
            int count_neighbours = 0;

            for (int ii = -1; ii < 2; ii++)
            {
                for (int jj = -1; jj < 2; jj++)
                {
                    int x0Coord = i + ii;
                    int x1Coord = j + jj;
                    if (x0Coord >= 0 && x0Coord < height && x1Coord >= 0 && x1Coord < height)
                    {
                        sumPxlValRed += image[x0Coord][x1Coord].rgbtRed;
                        sumPxlValGreen += image[x0Coord][x1Coord].rgbtGreen;
                        sumPxlValBlue += image[x0Coord][x1Coord].rgbtBlue;
                        count_neighbours++;
                    }
                }
            }

            imgTmp[i][j].rgbtRed = round(sumPxlValRed / count_neighbours);
            imgTmp[i][j].rgbtGreen = round(sumPxlValGreen / count_neighbours);
            imgTmp[i][j].rgbtBlue = round(sumPxlValBlue / count_neighbours);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = imgTmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = imgTmp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = imgTmp[i][j].rgbtBlue;
        }
    }
}
