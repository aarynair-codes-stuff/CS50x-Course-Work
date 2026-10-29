#include <cs50.h>
#include <stdio.h>
#include <string.h>

int get_n(void)
{
    // Get user input
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void generate_row(int width, int height)
{
    // Creates a string to store the row value
    char output[64] = "";

    // Adds the leading spaces
    for (int i = height; i > 1; i--)
    {
        strcat(output, " ");
    }

    char blocks[9] = "";
    // Creates the symmetrical blocks
    for (int j = 0; j < width; j++)
    {
        strcat(blocks, "#");
    }

    // Joins the spaces, first blocks, gap and second blocks
    strcat(output, blocks);
    strcat(output, "  ");
    strcat(output, blocks);
    printf("%s\n", output);
}

void create_pyramid(int height)
{
    // Generates the pyramid line by line
    for (int i = 0; i < height; i++)
    {
        generate_row(i + 1, height - i);
    }
}

int main(void)
{
    int n = get_n();
    create_pyramid(n);
}
