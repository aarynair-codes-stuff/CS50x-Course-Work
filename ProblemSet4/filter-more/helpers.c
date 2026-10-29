// To access rounding, powers and square roots
#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loops through all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculates the sum and the average
            int sum = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen);
            int average = (sum / 3);
            // If the average is truncated, use the rounded value
            if (sum % 3 != 0)
            {
                average = round(sum / 3.0);
            }

            // Set all RGB values to the average
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Calculate the midpoint of the picture
    int midpoint = width / 2;
    // Loop though the picture until the middle
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < midpoint; j++)
        {
            // Swap the values of the pixels about the middle using temp variables
            int tempRed = image[i][width - j - 1].rgbtRed;
            int tempBlue = image[i][width - j - 1].rgbtBlue;
            int tempGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtRed = image[i][j].rgbtRed;
            image[i][width - j - 1].rgbtBlue = image[i][j].rgbtBlue;
            image[i][width - j - 1].rgbtGreen = image[i][j].rgbtGreen;
            image[i][j].rgbtRed = tempRed;
            image[i][j].rgbtBlue = tempBlue;
            image[i][j].rgbtGreen = tempGreen;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Initialise another array to store the final image
    RGBTRIPLE final_image[height][width];
    // Loop through the picture
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Check if the pixel is a corner pixel
            if (i == 0 && j == 0)
            {
                // Calculate the sums of the colour values
                int sumRed = (image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                              image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed);
                int sumGreen = (image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen);
                int sumBlue = (image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                               image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue);

                // Calculate the averages for the colours
                int averageRed = sumRed / 4;
                int averageGreen = sumGreen / 4;
                int averageBlue = sumBlue / 4;

                // Check for rounding
                if (sumRed % 4 != 0)
                {
                    averageRed = round(sumRed / 4.0);
                }
                if (sumGreen % 4 != 0)
                {
                    averageGreen = round(sumGreen / 4.0);
                }
                if (sumBlue % 4 != 0)
                {
                    averageBlue = round(sumBlue / 4.0);
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            else if (i == 0 && j == width - 1)
            {
                // Calculate the sums of the colour values
                int sumRed = (image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                              image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed);
                int sumGreen = (image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen);
                int sumBlue = (image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                               image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue);

                // Calculate the averages for the colours
                int averageRed = sumRed / 4;
                int averageGreen = sumGreen / 4;
                int averageBlue = sumBlue / 4;

                // Check for rounding
                if (sumRed % 4 != 0)
                {
                    averageRed = round(sumRed / 4.0);
                }
                if (sumGreen % 4 != 0)
                {
                    averageGreen = round(sumGreen / 4.0);
                }
                if (sumBlue % 4 != 0)
                {
                    averageBlue = round(sumBlue / 4.0);
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            else if (i == height - 1 && j == 0)
            {
                // Calculate the sums of the colour values
                int sumRed = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed +
                              image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed);
                int sumGreen = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen +
                                image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen);
                int sumBlue = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue +
                               image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue);

                // Calculate the averages for the colours
                int averageRed = sumRed / 4;
                int averageGreen = sumGreen / 4;
                int averageBlue = sumBlue / 4;

                // Check for rounding
                if (sumRed % 4 != 0)
                {
                    averageRed = round(sumRed / 4.0);
                }
                if (sumGreen % 4 != 0)
                {
                    averageGreen = round(sumGreen / 4.0);
                }
                if (sumBlue % 4 != 0)
                {
                    averageBlue = round(sumBlue / 4.0);
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            else if (i == height - 1 && j == width - 1)
            {
                // Calculate the sums of the colour values
                int sumRed = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed +
                              image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed);
                int sumGreen = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen +
                                image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen);
                int sumBlue = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue +
                               image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue);

                // Calculate the averages for the colours
                int averageRed = sumRed / 4;
                int averageGreen = sumGreen / 4;
                int averageBlue = sumBlue / 4;

                // Check for rounding
                if (sumRed % 4 != 0)
                {
                    averageRed = round(sumRed / 4.0);
                }
                if (sumGreen % 4 != 0)
                {
                    averageGreen = round(sumGreen / 4.0);
                }
                if (sumBlue % 4 != 0)
                {
                    averageBlue = round(sumBlue / 4.0);
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            // Check if the pixel is an edge pixel
            else if (i == 0)
            {
                // Calculate the sums of the colour values
                int sumRed = (image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                              image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
                              image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed);
                int sumGreen = (image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                                image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen);
                int sumBlue = (image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                               image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                               image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue);

                // Calculate the averages for the colours
                int averageRed = sumRed / 6;
                int averageGreen = sumGreen / 6;
                int averageBlue = sumBlue / 6;

                // Check for rounding
                if (sumRed % 6 != 0)
                {
                    averageRed = round(sumRed / 6.0);
                }
                if (sumGreen % 6 != 0)
                {
                    averageGreen = round(sumGreen / 6.0);
                }
                if (sumBlue % 6 != 0)
                {
                    averageBlue = round(sumBlue / 6.0);
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            else if (j == 0)
            {
                // Calculate the sums of the colour values
                int sumRed = (image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                              image[i][j + 1].rgbtRed + image[i - 1][j].rgbtRed +
                              image[i + 1][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed);
                int sumGreen = (image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                image[i][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                                image[i + 1][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen);
                int sumBlue = (image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                               image[i][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                               image[i + 1][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue);

                // Calculate the averages for the colours
                int averageRed = sumRed / 6;
                int averageGreen = sumGreen / 6;
                int averageBlue = sumBlue / 6;

                // Check for rounding
                if (sumRed % 6 != 0)
                {
                    averageRed = round(sumRed / 6.0);
                }
                if (sumGreen % 6 != 0)
                {
                    averageGreen = round(sumGreen / 6.0);
                }
                if (sumBlue % 6 != 0)
                {
                    averageBlue = round(sumBlue / 6.0);
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            else if (i == height - 1)
            {
                // Calculate the sums of the colour values
                int sumRed = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed +
                              image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed +
                              image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed);
                int sumGreen = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen +
                                image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen +
                                image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen);
                int sumBlue = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue +
                               image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue +
                               image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue);

                // Calculate the averages for the colours
                int averageRed = sumRed / 6;
                int averageGreen = sumGreen / 6;
                int averageBlue = sumBlue / 6;

                // Check for rounding
                if (sumRed % 6 != 0)
                {
                    averageRed = round(sumRed / 6.0);
                }
                if (sumGreen % 6 != 0)
                {
                    averageGreen = round(sumGreen / 6.0);
                }
                if (sumBlue % 6 != 0)
                {
                    averageBlue = round(sumBlue / 6.0);
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            else if (j == width - 1)
            {
                // Calculate the sums of the colour values
                int sumRed = (image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                              image[i][j - 1].rgbtRed + image[i - 1][j].rgbtRed +
                              image[i + 1][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed);
                int sumGreen = (image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                image[i][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                                image[i + 1][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen);
                int sumBlue = (image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                               image[i][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                               image[i + 1][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue);

                // Calculate the averages for the colours
                int averageRed = sumRed / 6;
                int averageGreen = sumGreen / 6;
                int averageBlue = sumBlue / 6;

                // Check for rounding
                if (sumRed % 6 != 0)
                {
                    averageRed = round(sumRed / 6.0);
                }
                if (sumGreen % 6 != 0)
                {
                    averageGreen = round(sumGreen / 6.0);
                }
                if (sumBlue % 6 != 0)
                {
                    averageBlue = round(sumBlue / 6.0);
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            // For all middle pixels
            else
            {
                // Calculate the sums of the colour values
                int sumRed =
                    (image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j - 1].rgbtRed +
                     image[i - 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed +
                     image[i - 1][j - 1].rgbtRed + image[i][j + 1].rgbtRed +
                     image[i + 1][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed);
                int sumGreen =
                    (image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j - 1].rgbtGreen +
                     image[i - 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                     image[i - 1][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen +
                     image[i + 1][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen);
                int sumBlue =
                    (image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j - 1].rgbtBlue +
                     image[i - 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                     image[i - 1][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue +
                     image[i + 1][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue);

                // Calculate the averages for the colours
                int averageRed = sumRed / 9;
                int averageGreen = sumGreen / 9;
                int averageBlue = sumBlue / 9;

                // Check for rounding
                if (sumRed % 9 != 0)
                {
                    averageRed = round(sumRed / 9.0);
                }
                if (sumGreen % 9 != 0)
                {
                    averageGreen = round(sumGreen / 9.0);
                }
                if (sumBlue % 9 != 0)
                {
                    averageBlue = round(sumBlue / 9.0);
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
        }
    }

    // Loop though the filtered image
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            // Copy changes to the original image
            image[k][l] = final_image[k][l];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Initialise a copy variable
    RGBTRIPLE final_image[height][width];
    // Loop through the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Checks for corner pixels
            if (i == 0 && j == 0)
            {
                // Calculate the Gx sum for each colour
                int GxsumRed = ((image[i][j].rgbtRed * 0) + (image[i + 1][j].rgbtRed * 0) +
                                (image[i][j + 1].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed * 1));
                int GxsumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i + 1][j].rgbtGreen * 0) +
                     (image[i][j + 1].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen * 1));
                int GxsumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i + 1][j].rgbtBlue * 0) +
                     (image[i][j + 1].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue * 1));

                // Calculate the Gy sum for each colour
                int GysumRed = ((image[i][j].rgbtRed * 0) + (image[i + 1][j].rgbtRed * -2) +
                                (image[i][j + 1].rgbtRed * 0) + (image[i + 1][j + 1].rgbtRed * -1));
                int GysumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i + 1][j].rgbtGreen * -2) +
                     (image[i][j + 1].rgbtGreen * 0) + (image[i + 1][j + 1].rgbtGreen * -1));
                int GysumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i + 1][j].rgbtBlue * -2) +
                     (image[i][j + 1].rgbtBlue * 0) + (image[i + 1][j + 1].rgbtBlue * -1));

                // Calculate the filter value
                int averageRed = round(sqrt(pow(GxsumRed, 2) + pow(GysumRed, 2)));
                int averageGreen = round(sqrt(pow(GxsumGreen, 2) + pow(GysumGreen, 2)));
                int averageBlue = round(sqrt(pow(GxsumBlue, 2) + pow(GysumBlue, 2)));

                // Check for overflows
                if (averageRed > 255)
                {
                    averageRed = 255;
                }
                if (averageGreen > 255)
                {
                    averageGreen = 255;
                }
                if (averageBlue > 255)
                {
                    averageBlue = 255;
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            else if (i == 0 && j == width - 1)
            {
                // Calculate the Gx sum for each colour
                int GxsumRed =
                    ((image[i][j].rgbtRed * 0) + (image[i + 1][j].rgbtRed * 0) +
                     (image[i][j - 1].rgbtRed * -2) + (image[i + 1][j - 1].rgbtRed * -1));
                int GxsumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i + 1][j].rgbtGreen * 0) +
                     (image[i][j - 1].rgbtGreen * -2) + (image[i + 1][j - 1].rgbtGreen * -1));
                int GxsumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i + 1][j].rgbtBlue * 0) +
                     (image[i][j - 1].rgbtBlue * -2) + (image[i + 1][j - 1].rgbtBlue * -1));

                // Calculate the Gy sum for each colour
                int GysumRed = ((image[i][j].rgbtRed * 0) + (image[i + 1][j].rgbtRed * -2) +
                                (image[i][j - 1].rgbtRed * 0) + (image[i + 1][j - 1].rgbtRed * -1));
                int GysumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i + 1][j].rgbtGreen * -2) +
                     (image[i][j - 1].rgbtGreen * 0) + (image[i + 1][j - 1].rgbtGreen * -1));
                int GysumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i + 1][j].rgbtBlue * -2) +
                     (image[i][j - 1].rgbtBlue * 0) + (image[i + 1][j - 1].rgbtBlue * -1));

                // Calculate the filter value
                int averageRed = round(sqrt(pow(GxsumRed, 2) + pow(GysumRed, 2)));
                int averageGreen = round(sqrt(pow(GxsumGreen, 2) + pow(GysumGreen, 2)));
                int averageBlue = round(sqrt(pow(GxsumBlue, 2) + pow(GysumBlue, 2)));

                // Check for overflows
                if (averageRed > 255)
                {
                    averageRed = 255;
                }
                if (averageGreen > 255)
                {
                    averageGreen = 255;
                }
                if (averageBlue > 255)
                {
                    averageBlue = 255;
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            else if (i == height - 1 && j == 0)
            {
                // Calculate the Gx sum for each colour
                int GxsumRed = ((image[i][j].rgbtRed * 0) + (image[i - 1][j].rgbtRed * 0) +
                                (image[i][j + 1].rgbtRed * 2) + (image[i - 1][j + 1].rgbtRed * 1));
                int GxsumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i - 1][j].rgbtGreen * 0) +
                     (image[i][j + 1].rgbtGreen * 2) + (image[i - 1][j + 1].rgbtGreen * 1));
                int GxsumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i - 1][j].rgbtBlue * 0) +
                     (image[i][j + 1].rgbtBlue * 2) + (image[i - 1][j + 1].rgbtBlue * 1));

                // Calculate the Gy sum for each colour
                int GysumRed = ((image[i][j].rgbtRed * 0) + (image[i - 1][j].rgbtRed * 2) +
                                (image[i][j + 1].rgbtRed * 0) + (image[i - 1][j + 1].rgbtRed * 1));
                int GysumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i - 1][j].rgbtGreen * 2) +
                     (image[i][j + 1].rgbtGreen * 0) + (image[i - 1][j + 1].rgbtGreen * 1));
                int GysumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i - 1][j].rgbtBlue * 2) +
                     (image[i][j + 1].rgbtBlue * 0) + (image[i - 1][j + 1].rgbtBlue * 1));

                // Calculate the filter value
                int averageRed = round(sqrt(pow(GxsumRed, 2) + pow(GysumRed, 2)));
                int averageGreen = round(sqrt(pow(GxsumGreen, 2) + pow(GysumGreen, 2)));
                int averageBlue = round(sqrt(pow(GxsumBlue, 2) + pow(GysumBlue, 2)));

                // Check for overflows
                if (averageRed > 255)
                {
                    averageRed = 255;
                }
                if (averageGreen > 255)
                {
                    averageGreen = 255;
                }
                if (averageBlue > 255)
                {
                    averageBlue = 255;
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            else if (i == height - 1 && j == width - 1)
            {
                // Calculate the Gx sum for each colour
                int GxsumRed =
                    ((image[i][j].rgbtRed * 0) + (image[i - 1][j].rgbtRed * 0) +
                     (image[i][j - 1].rgbtRed * -2) + (image[i - 1][j - 1].rgbtRed * -1));
                int GxsumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i - 1][j].rgbtGreen * 0) +
                     (image[i][j - 1].rgbtGreen * -2) + (image[i - 1][j - 1].rgbtGreen * -1));
                int GxsumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i - 1][j].rgbtBlue * 0) +
                     (image[i][j - 1].rgbtBlue * -2) + (image[i - 1][j - 1].rgbtBlue * -1));

                // Calculate the Gy sum for each colour
                int GysumRed = ((image[i][j].rgbtRed * 0) + (image[i - 1][j].rgbtRed * 2) +
                                (image[i][j - 1].rgbtRed * 0) + (image[i - 1][j - 1].rgbtRed * 1));
                int GysumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i - 1][j].rgbtGreen * 2) +
                     (image[i][j - 1].rgbtGreen * 0) + (image[i - 1][j - 1].rgbtGreen * 1));
                int GysumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i - 1][j].rgbtBlue * 2) +
                     (image[i][j - 1].rgbtBlue * 0) + (image[i - 1][j - 1].rgbtBlue * 1));

                // Calculate the filter value
                int averageRed = round(sqrt(pow(GxsumRed, 2) + pow(GysumRed, 2)));
                int averageGreen = round(sqrt(pow(GxsumGreen, 2) + pow(GysumGreen, 2)));
                int averageBlue = round(sqrt(pow(GxsumBlue, 2) + pow(GysumBlue, 2)));

                // Check for overflows
                if (averageRed > 255)
                {
                    averageRed = 255;
                }
                if (averageGreen > 255)
                {
                    averageGreen = 255;
                }
                if (averageBlue > 255)
                {
                    averageBlue = 255;
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            // Check for edges
            else if (i == 0)
            {
                // Calculate the Gx sum for each colour
                int GxsumRed =
                    ((image[i][j].rgbtRed * 0) + (image[i + 1][j].rgbtRed * 0) +
                     (image[i][j - 1].rgbtRed * -2) + (image[i + 1][j - 1].rgbtRed * -1) +
                     (image[i][j + 1].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed * 1));
                int GxsumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i + 1][j].rgbtGreen * 0) +
                     (image[i][j - 1].rgbtGreen * -2) + (image[i + 1][j - 1].rgbtGreen * -1) +
                     (image[i][j + 1].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen * 1));
                int GxsumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i + 1][j].rgbtBlue * 0) +
                     (image[i][j - 1].rgbtBlue * -2) + (image[i + 1][j - 1].rgbtBlue * -1) +
                     (image[i][j + 1].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue * 1));

                // Calculate the Gy sum for each colour
                int GysumRed = ((image[i][j].rgbtRed * 0) + (image[i + 1][j].rgbtRed * -2) +
                                (image[i][j - 1].rgbtRed * 0) + (image[i + 1][j - 1].rgbtRed * -1) +
                                (image[i][j + 1].rgbtRed * 0) + (image[i + 1][j + 1].rgbtRed * -1));
                int GysumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i + 1][j].rgbtGreen * -2) +
                     (image[i][j - 1].rgbtGreen * 0) + (image[i + 1][j - 1].rgbtGreen * -1) +
                     (image[i][j + 1].rgbtGreen * 0) + (image[i + 1][j + 1].rgbtGreen * -1));
                int GysumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i + 1][j].rgbtBlue * -2) +
                     (image[i][j - 1].rgbtBlue * 0) + (image[i + 1][j - 1].rgbtBlue * -1) +
                     (image[i][j + 1].rgbtBlue * 0) + (image[i + 1][j + 1].rgbtBlue * -1));

                // Calculate the filter value
                int averageRed = round(sqrt(pow(GxsumRed, 2) + pow(GysumRed, 2)));
                int averageGreen = round(sqrt(pow(GxsumGreen, 2) + pow(GysumGreen, 2)));
                int averageBlue = round(sqrt(pow(GxsumBlue, 2) + pow(GysumBlue, 2)));

                // Check for overflows
                if (averageRed > 255)
                {
                    averageRed = 255;
                }
                if (averageGreen > 255)
                {
                    averageGreen = 255;
                }
                if (averageBlue > 255)
                {
                    averageBlue = 255;
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            else if (j == 0)
            {
                // Calculate the Gx sum for each colour
                int GxsumRed =
                    ((image[i][j].rgbtRed * 0) + (image[i + 1][j].rgbtRed * 0) +
                     (image[i][j + 1].rgbtRed * 2) + (image[i - 1][j].rgbtRed * 0) +
                     (image[i + 1][j + 1].rgbtRed * 1) + (image[i - 1][j + 1].rgbtRed * 1));
                int GxsumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i + 1][j].rgbtGreen * 0) +
                     (image[i][j + 1].rgbtGreen * 2) + (image[i - 1][j].rgbtGreen * 0) +
                     (image[i + 1][j + 1].rgbtGreen * 1) + (image[i - 1][j + 1].rgbtGreen * 1));
                int GxsumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i + 1][j].rgbtBlue * 0) +
                     (image[i][j + 1].rgbtBlue * 2) + (image[i - 1][j].rgbtBlue * 0) +
                     (image[i + 1][j + 1].rgbtBlue * 1) + (image[i - 1][j + 1].rgbtBlue * 1));

                // Calculate the Gy sum for each colour
                int GysumRed =
                    ((image[i][j].rgbtRed * 0) + (image[i + 1][j].rgbtRed * -2) +
                     (image[i][j + 1].rgbtRed * 0) + (image[i - 1][j].rgbtRed * 2) +
                     (image[i + 1][j + 1].rgbtRed * -1) + (image[i - 1][j + 1].rgbtRed * 1));
                int GysumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i + 1][j].rgbtGreen * -2) +
                     (image[i][j + 1].rgbtGreen * 0) + (image[i - 1][j].rgbtGreen * 2) +
                     (image[i + 1][j + 1].rgbtGreen * -1) + (image[i - 1][j + 1].rgbtGreen * 1));
                int GysumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i + 1][j].rgbtBlue * -2) +
                     (image[i][j + 1].rgbtBlue * 0) + (image[i - 1][j].rgbtBlue * 2) +
                     (image[i + 1][j + 1].rgbtBlue * -1) + (image[i - 1][j + 1].rgbtBlue * 1));

                // Calculate the filter value
                int averageRed = round(sqrt(pow(GxsumRed, 2) + pow(GysumRed, 2)));
                int averageGreen = round(sqrt(pow(GxsumGreen, 2) + pow(GysumGreen, 2)));
                int averageBlue = round(sqrt(pow(GxsumBlue, 2) + pow(GysumBlue, 2)));

                // Check for overflows
                if (averageRed > 255)
                {
                    averageRed = 255;
                }
                if (averageGreen > 255)
                {
                    averageGreen = 255;
                }
                if (averageBlue > 255)
                {
                    averageBlue = 255;
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            else if (i == height - 1)
            {
                // Calculate the Gx sum for each colour
                int GxsumRed =
                    ((image[i][j].rgbtRed * 0) + (image[i - 1][j].rgbtRed * 0) +
                     (image[i][j - 1].rgbtRed * -2) + (image[i - 1][j - 1].rgbtRed * -1) +
                     (image[i][j + 1].rgbtRed * 2) + (image[i - 1][j + 1].rgbtRed * 1));
                int GxsumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i - 1][j].rgbtGreen * 0) +
                     (image[i][j - 1].rgbtGreen * -2) + (image[i - 1][j - 1].rgbtGreen * -1) +
                     (image[i][j + 1].rgbtGreen * 2) + (image[i - 1][j + 1].rgbtGreen * 1));
                int GxsumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i - 1][j].rgbtBlue * 0) +
                     (image[i][j - 1].rgbtBlue * -2) + (image[i - 1][j - 1].rgbtBlue * -1) +
                     (image[i][j + 1].rgbtBlue * 2) + (image[i - 1][j + 1].rgbtBlue * 1));

                // Calculate the Gy sum for each colour
                int GysumRed = ((image[i][j].rgbtRed * 0) + (image[i - 1][j].rgbtRed * 2) +
                                (image[i][j - 1].rgbtRed * 0) + (image[i - 1][j - 1].rgbtRed * 1) +
                                (image[i][j + 1].rgbtRed * 0) + (image[i - 1][j + 1].rgbtRed * 1));
                int GysumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i - 1][j].rgbtGreen * 2) +
                     (image[i][j - 1].rgbtGreen * 0) + (image[i - 1][j - 1].rgbtGreen * 1) +
                     (image[i][j + 1].rgbtGreen * 0) + (image[i - 1][j + 1].rgbtGreen * 1));
                int GysumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i - 1][j].rgbtBlue * 2) +
                     (image[i][j - 1].rgbtBlue * 0) + (image[i - 1][j - 1].rgbtBlue * 1) +
                     (image[i][j + 1].rgbtBlue * 0) + (image[i - 1][j + 1].rgbtBlue * 1));

                // Calculate the filter value
                int averageRed = round(sqrt(pow(GxsumRed, 2) + pow(GysumRed, 2)));
                int averageGreen = round(sqrt(pow(GxsumGreen, 2) + pow(GysumGreen, 2)));
                int averageBlue = round(sqrt(pow(GxsumBlue, 2) + pow(GysumBlue, 2)));

                // Check for overflows
                if (averageRed > 255)
                {
                    averageRed = 255;
                }
                if (averageGreen > 255)
                {
                    averageGreen = 255;
                }
                if (averageBlue > 255)
                {
                    averageBlue = 255;
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            else if (j == width - 1)
            {
                // Calculate the Gx sum for each colour
                int GxsumRed =
                    ((image[i][j].rgbtRed * 0) + (image[i + 1][j].rgbtRed * 0) +
                     (image[i][j - 1].rgbtRed * -2) + (image[i - 1][j].rgbtRed * 0) +
                     (image[i + 1][j - 1].rgbtRed * -1) + (image[i - 1][j - 1].rgbtRed * -1));
                int GxsumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i + 1][j].rgbtGreen * 0) +
                     (image[i][j - 1].rgbtGreen * -2) + (image[i - 1][j].rgbtGreen * 0) +
                     (image[i + 1][j - 1].rgbtGreen * -1) + (image[i - 1][j - 1].rgbtGreen * -1));
                int GxsumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i + 1][j].rgbtBlue * 0) +
                     (image[i][j - 1].rgbtBlue * -2) + (image[i - 1][j].rgbtBlue * 0) +
                     (image[i + 1][j - 1].rgbtBlue * -1) + (image[i - 1][j - 1].rgbtBlue * -1));

                // Calculate the Gy sum for each colour
                int GysumRed =
                    ((image[i][j].rgbtRed * 0) + (image[i + 1][j].rgbtRed * -2) +
                     (image[i][j - 1].rgbtRed * 0) + (image[i - 1][j].rgbtRed * 2) +
                     (image[i + 1][j - 1].rgbtRed * -1) + (image[i - 1][j - 1].rgbtRed * 1));
                int GysumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i + 1][j].rgbtGreen * -2) +
                     (image[i][j - 1].rgbtGreen * 0) + (image[i - 1][j].rgbtGreen * 2) +
                     (image[i + 1][j - 1].rgbtGreen * -1) + (image[i - 1][j - 1].rgbtGreen * 1));
                int GysumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i + 1][j].rgbtBlue * -2) +
                     (image[i][j - 1].rgbtBlue * 0) + (image[i - 1][j].rgbtBlue * 2) +
                     (image[i + 1][j - 1].rgbtBlue * -1) + (image[i - 1][j - 1].rgbtBlue * 1));

                // Calculate the filter value
                int averageRed = round(sqrt(pow(GxsumRed, 2) + pow(GysumRed, 2)));
                int averageGreen = round(sqrt(pow(GxsumGreen, 2) + pow(GysumGreen, 2)));
                int averageBlue = round(sqrt(pow(GxsumBlue, 2) + pow(GysumBlue, 2)));

                // Check for overflows
                if (averageRed > 255)
                {
                    averageRed = 255;
                }
                if (averageGreen > 255)
                {
                    averageGreen = 255;
                }
                if (averageBlue > 255)
                {
                    averageBlue = 255;
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
            // For all middle pixels
            else
            {
                // Calculate the Gx sum for each colour
                int GxsumRed =
                    ((image[i][j].rgbtRed * 0) + (image[i + 1][j].rgbtRed * 0) +
                     (image[i][j - 1].rgbtRed * -2) + (image[i - 1][j].rgbtRed * 0) +
                     (image[i + 1][j - 1].rgbtRed * -1) + (image[i - 1][j - 1].rgbtRed * -1) +
                     (image[i][j + 1].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed * 1) +
                     (image[i - 1][j + 1].rgbtRed * 1));
                int GxsumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i + 1][j].rgbtGreen * 0) +
                     (image[i][j - 1].rgbtGreen * -2) + (image[i - 1][j].rgbtGreen * 0) +
                     (image[i + 1][j - 1].rgbtGreen * -1) + (image[i - 1][j - 1].rgbtGreen * -1) +
                     (image[i][j + 1].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen * 1) +
                     (image[i - 1][j + 1].rgbtGreen * 1));
                int GxsumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i + 1][j].rgbtBlue * 0) +
                     (image[i][j - 1].rgbtBlue * -2) + (image[i - 1][j].rgbtBlue * 0) +
                     (image[i + 1][j - 1].rgbtBlue * -1) + (image[i - 1][j - 1].rgbtBlue * -1) +
                     (image[i][j + 1].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue * 1) +
                     (image[i - 1][j + 1].rgbtBlue * 1));

                // Calculate the Gy sum for each colour
                int GysumRed =
                    ((image[i][j].rgbtRed * 0) + (image[i + 1][j].rgbtRed * -2) +
                     (image[i][j - 1].rgbtRed * 0) + (image[i - 1][j].rgbtRed * 2) +
                     (image[i + 1][j - 1].rgbtRed * -1) + (image[i - 1][j - 1].rgbtRed * 1) +
                     (image[i][j + 1].rgbtRed * 0) + (image[i + 1][j + 1].rgbtRed * -1) +
                     (image[i - 1][j + 1].rgbtRed * 1));
                int GysumGreen =
                    ((image[i][j].rgbtGreen * 0) + (image[i + 1][j].rgbtGreen * -2) +
                     (image[i][j - 1].rgbtGreen * 0) + (image[i - 1][j].rgbtGreen * 2) +
                     (image[i + 1][j - 1].rgbtGreen * -1) + (image[i - 1][j - 1].rgbtGreen * 1) +
                     (image[i][j + 1].rgbtGreen * 0) + (image[i + 1][j + 1].rgbtGreen * -1) +
                     (image[i - 1][j + 1].rgbtGreen * 1));
                int GysumBlue =
                    ((image[i][j].rgbtBlue * 0) + (image[i + 1][j].rgbtBlue * -2) +
                     (image[i][j - 1].rgbtBlue * 0) + (image[i - 1][j].rgbtBlue * 2) +
                     (image[i + 1][j - 1].rgbtBlue * -1) + (image[i - 1][j - 1].rgbtBlue * 1) +
                     (image[i][j + 1].rgbtBlue * 0) + (image[i + 1][j + 1].rgbtBlue * -1) +
                     (image[i - 1][j + 1].rgbtBlue * 1));

                // Calculate the filter value
                int averageRed = round(sqrt(pow(GxsumRed, 2) + pow(GysumRed, 2)));
                int averageGreen = round(sqrt(pow(GxsumGreen, 2) + pow(GysumGreen, 2)));
                int averageBlue = round(sqrt(pow(GxsumBlue, 2) + pow(GysumBlue, 2)));

                // Check for overflows
                if (averageRed > 255)
                {
                    averageRed = 255;
                }
                if (averageGreen > 255)
                {
                    averageGreen = 255;
                }
                if (averageBlue > 255)
                {
                    averageBlue = 255;
                }

                // Set the copy values to the filter values
                final_image[i][j].rgbtRed = averageRed;
                final_image[i][j].rgbtGreen = averageGreen;
                final_image[i][j].rgbtBlue = averageBlue;
            }
        }
    }

    // Loop though the filtered image
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            // Copies the changes to the original image
            image[k][l] = final_image[k][l];
        }
    }
    return;
}
