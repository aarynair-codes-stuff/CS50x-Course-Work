// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Global count variable
int dictionary_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Calculate the hash value of the word
    int index = hash(word);

    // Iterate over nodes in list
    for (node *ptr = table[index]; ptr != NULL; ptr = ptr->next)
    {
        // If word is found
        if (strcasecmp(word, ptr->word) == 0)
        {
            // Word was found
            return true;
        }
    }
    // If word wasn't found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    // Check if the file was opened correctly
    if (source == NULL)
    {
        return false;
    }

    // Create a buffer to store the value of the string
    char buffer[LENGTH + 1];

    // Read each word in the file
    while (fscanf(source, "%s", buffer) != EOF)
    {
        // Allocate node for number
        node *n = malloc(sizeof(node));
        // Check if memory was allocated correctly
        if (n == NULL)
        {
            return false;
        }

        // Add each word to the hash table
        strcpy(n->word, buffer);
        n->next = NULL;

        // Calculate the hash index for the word
        int index = hash(buffer);

        // Prepend node to list
        n->next = table[index];
        table[index] = n;

        // Update the dictionary_size global variable
        dictionary_size++;
    }

    // Close the dictionary file
    fclose(source);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Returns the updated
    return dictionary_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        // Free memory
        node *ptr = table[i];
        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }
    }
    return true;
}
