#include <stdio.h>

// Function to check if a number is prime
int ft_is_prime(int nb)
{
    int i;

    // Handle numbers less than 2 (not prime)
    if (nb < 2)
        return (0);

    // Check divisibility from 2 up to the square root of nb
    for (i = 2; i * i <= nb; i++)
    {
        if (nb % i == 0)
            return (0);  // Not prime
    }
    return (1);  // Prime
}

int main(void)
{
    int min, max;

    // Get the minimum value from the user
    printf("Minimum: ");
    scanf("%d", &min);

    // Get the maximum value from the user
    printf("Maximum: ");
    scanf("%d", &max);

    // Check and print prime numbers within the range
    for (int i = min; i <= max; i++)
    {
        if (ft_is_prime(i))
        {
            printf("%d\n", i);  // Print prime number
        }
    }

    return 0;
}