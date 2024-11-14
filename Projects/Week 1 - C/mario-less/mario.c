#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare variable for height
    int height;

    // Prompt the user for the height until a valid number is given
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); // Ensure height is a positive integer

    // Loop to print the pyramid
    for (int i = 1; i <= height; i++) // Loop over each row
    {
        // Print leading spaces
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // Print hashes
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }
}
