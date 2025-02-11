#include <stdio.h>

// Function to calculate half of the total amount (bill + tax + tip)
float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount, tax_percent;
    int tip_percent;

    // Ask the user for the bill amount before tax and tip
    printf("Bill before tax and tip: ");
    scanf("%f", &bill_amount);

    // Ask the user for the sales tax percentage
    printf("Sale Tax Percent: ");
    scanf("%f", &tax_percent);

    // Ask the user for the tip percentage
    printf("Tip percent: ");
    scanf("%d", &tip_percent);

    // Calculate and display the amount each person owes
    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// Function to calculate half of the total amount including tax and tip
float half(float bill, float tax, int tip)
{
    // Calculate the tax amount
    float tax_amount = bill * (tax / 100.0);

    // Calculate the total bill with tax
    float total_with_tax = bill + tax_amount;

    // Calculate the tip amount based on the total with tax
    float tip_amount = total_with_tax * (tip / 100.0);

    // Calculate the final total (bill + tax + tip)
    float total = total_with_tax + tip_amount;

    // Return half of the total amount
    return total / 2.0;
}