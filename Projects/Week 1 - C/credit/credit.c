#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long card_number;
    int sum = 0;
    int length = 0;

    // Prompt the user for the credit card number
    do
    {
        card_number = get_long_long("Number: ");
    }
    while (card_number <= 0);

    long long temp_card = card_number;

    // Check the length of the card number and calculate checksum
    while (temp_card > 0)
    {
        length++;
        int digit = temp_card % 10; // Get the last digit

        // If the position of the digit is even (starting from the end)
        if ((length % 2) == 0)
        {
            digit *= 2; // Double the digit
            // If the doubled digit is greater than 9, add the digits
            sum += (digit > 9) ? (digit - 9) : digit;
        }
        else
        {
            sum += digit; // Add the digit directly
        }
        temp_card /= 10; // Remove the last digit
    }

    // Validate the card number
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Determine the card type
    if ((length == 15) &&
        (card_number / 10000000000000 == 34 || card_number / 10000000000000 == 37))
    {
        printf("AMEX\n");
    }
    else if ((length == 16) &&
             (card_number / 100000000000000 >= 51 && card_number / 100000000000000 <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) &&
             (card_number / 1000000000000 == 4 || card_number / 1000000000000000 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
