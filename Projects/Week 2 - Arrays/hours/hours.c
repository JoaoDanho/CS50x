#include <stdio.h>
#include <ctype.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks;

    // Prompt the user for the number of weeks
    printf("Number of weeks taking CS50: ");
    scanf("%d", &weeks);

    // Declare an array to store hours
    int hours[weeks];

    // Collect hours for each week
    for (int i = 0; i < weeks; i++)
    {
        printf("Week %i HW Hours: ", i);
        scanf("%d", &hours[i]);
    }

    char output;

    // Get the user's choice for total or average
    do
    {
        printf("Enter T for total hours, A for average hours per week: ");
        scanf(" %c", &output);
        output = toupper(output); // Ensure input is uppercase
    }
    while (output != 'T' && output != 'A');

    // Print the result based on the user's choice
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// Function to calculate total or average hours
float calc_hours(int hours[], int weeks, char output)
{
    int total = 0;

    // Calculate the total hours
    for (int i = 0; i < weeks; i++)
    {
        total += hours[i];
    }

    // Return total or average based on the user's choice
    if (output == 'T')
    {
        return (float)total; // Total hours
    }
    else
    {
        return (float)total / weeks; // Average hours
    }
}