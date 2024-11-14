#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // Check if the number of arguments is exactly 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Check if the key is valid
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Get the plaintext from the user
    string plaintext = get_string("plaintext: ");

    // Initialize the ciphertext
    printf("ciphertext: ");

    // Process each character of the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        // Substitute only alphabetic characters
        if (isalpha(c))
        {
            if (islower(c))
            {
                // Map the lowercase character to the key
                printf("%c", tolower(key[c - 'a']));
            }
            else
            {
                // Map the uppercase character to the key
                printf("%c", toupper(key[c - 'A']));
            }
        }
        else
        {
            // Leave non-alphabetic characters unchanged
            printf("%c", c);
        }
    }

    // Newline after the ciphertext
    printf("\n");
    return 0;
}

// Function to validate the key
bool is_valid_key(string key)
{
    // The key must have exactly 26 characters
    if (strlen(key) != 26)
    {
        return false;
    }

    // Check if all characters are letters and are unique
    int letters[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = tolower(key[i]) - 'a';
        if (letters[index] > 0)
        {
            return false;
        }
        letters[index]++;
    }

    return true;
}
