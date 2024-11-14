#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype
bool only_digits(string s);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    // Check if theres only 1 argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // check if the argument its made only by digits
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // converse the argument to intiger
    int key = atoi(argv[1]);

    // ask the user to write something
    string plaintext = get_string("plaintext:  ");

    // show the text coded
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }

    printf("\n");
    return 0;
}

// Function that check if the string only contain numbers
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Function that modify the caracter
char rotate(char c, int k)
{
    // Check if its upper
    if (isupper(c))
    {
        return (c - 'A' + k) % 26 + 'A';
    }
    // Check if its lower
    else if (islower(c))
    {
        return (c - 'a' + k) % 26 + 'a';
    }
    // if its not upper or lower return the same
    return c;
}
