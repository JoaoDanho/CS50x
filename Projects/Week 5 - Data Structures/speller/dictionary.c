#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // For strcpy
#include <strings.h> // For strcasecmp

#include "dictionary.h"

// Prime number for hash table size to reduce collisions
const unsigned int N = 101;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Encapsulates hash table and word count
typedef struct
{
    node *table[N];
    unsigned int word_count;
} dictionary;

// Initializes an empty dictionary context
dictionary dict = {.table = {NULL}, .word_count = 0};

// Hashes word to a number, distributing across the table size (N)
unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value = (hash_value * 31 + toupper(word[i])) % N;
    }
    return hash_value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file for reading
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        fprintf(stderr, "Error: Could not open dictionary file.\n");
        return false;
    }

    // Buffer for reading each word
    char word[LENGTH + 1];

    // Read each word in the file
    while (fscanf(source, "%s", word) != EOF)
    {
        // Allocate memory for new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fprintf(stderr, "Error: Could not allocate memory for new node.\n");
            fclose(source);
            return false;
        }

        // Copy word into node and set the next pointer
        strcpy(new_node->word, word);
        unsigned int index = hash(word);

        // Insert node at the beginning of the list in table[index]
        new_node->next = dict.table[index];
        dict.table[index] = new_node;

        // Increment word count
        dict.word_count++;
    }

    // Check for read errors in the file stream
    if (ferror(source))
    {
        fprintf(stderr, "Error: Failed to read dictionary file.\n");
        fclose(source);
        return false;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash the word to find the index in the hash table
    unsigned int index = hash(word);

    // Traverse linked list at that index
    for (node *cursor = dict.table[index]; cursor != NULL; cursor = cursor->next)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true; // Word found
        }
    }
    return false; // Word not found
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict.word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over each bucket in the hash table
    for (int i = 0; i < N; i++)
    {
        node *cursor = dict.table[i];

        // Free each node in the linked list
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
            temp = NULL; // Set freed pointer to NULL to avoid dangling pointers
        }

        // Set the table entry to NULL after freeing
        dict.table[i] = NULL;
    }

    // Reset word count
    dict.word_count = 0;
    return true;
}
