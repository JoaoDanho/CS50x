#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    // Prompt the user for the height of the pyramid, between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Loop for each row of the pyramid
    for (int i = 1; i <= height; i++)
    {
        // Print spaces before the left pyramid
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        // Print hashes for the left pyramid
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // Print two spaces in the middle
        printf("  ");

        // Print hashes for the right pyramid
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // Move to the next line
        printf("\n");
    }
}
