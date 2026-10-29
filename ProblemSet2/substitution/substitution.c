#include <cs50.h>   // To take plaintext input
#include <ctype.h>  // For use in lower/upper
#include <stdio.h>  // Use for printf
#include <stdlib.h> // To use quicksort
#include <string.h> // String length and comparison

// Prototype functions
int check_valid_key_length(string key);
int check_valid_alpabetical(string key);
int comp(const void *a, const void *b);
int check_valid_unique(string key);
void encryption(string plaintext, string key);

int main(int argc, string argv[])
{
    // Declares a variable to hold the key value
    string key = argv[1];

    // Checks for too many arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Checks for 26 chars
    else if (check_valid_key_length(key) == 0)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // Checks if all chars alphabetic
    else if (check_valid_alpabetical(key) == 0)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    // Checks if all 26 chars unique
    else if (check_valid_unique(key) == 0)
    {
        printf("Key must contain each of all the 26 characters.\n");
        return 1;
    }

    // Takes plaintext input
    string plaintext = get_string("plaintext: ");

    // Encrypts and outputs ciphertext
    encryption(plaintext, argv[1]);

    // Returns 0 for success
    return 0;
}

int check_valid_key_length(string key)
{
    if (strlen(key) == 26)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_valid_alpabetical(string key)
{
    // Initialise the count variable
    int count = 0;

    // Calculate the key length
    int key_len = strlen(key);

    for (int i = 0; i < key_len; i++)
    {
        // Takes the ith letter from the key
        char letter = key[i];

        // Checks if it isn't alphabetic
        if (isalpha(letter) == 0)
        {
            count++;
        }
    }

    // Checks if any non-alphabetic characters were present
    if (count > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int comp(const void *a, const void *b)
{
    // Declares comparison function, source:
    // https://www.geeksforgeeks.org/c/c-program-to-sort-a-string-of-characters/
    return (*(char *) a - *(char *) b);
}

int check_valid_unique(string str)
{
    // Initialises a variable which will store a lowercase copy of the key for comparison
    char copy[26];
    int length = strlen(str);

    // Initialises a variable to store the expected lowercase sorted alphabet
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    // Stores a lowercase copy of the key
    for (int i = 0; i < length; i++)
    {
        copy[i] = tolower(str[i]);
    }

    // Sorts the copy alphabetically
    qsort(copy, length, sizeof(char), comp);

    // Checks if it is correct without duplication
    if (strcmp(copy, alphabet) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void encryption(string plaintext, string key)
{
    // Initialises a variable to store the lowercase sorted alphabet
    string letters = "abcdefghijklmnopqrstuvwxyz";

    // Initialise the ciphertext variable
    char ciphertext[64];

    // Calculate the text length
    int text_len = strlen(plaintext);

    for (int i = 0; i < text_len; i++)
    {
        // Takes the ith letter from the text
        char text_letter = plaintext[i];

        // Converts it to lowercase because alphabet is in lowercase
        char lower_letter = tolower(text_letter);

        // Checks if the letter is alphabetic
        if (isalpha(lower_letter) != 0)
        {
            // Checks if the character against the letters array
            for (int j = 0; j < 26; j++)
            {
                char arr_elem = letters[j];

                // Finds the matching index of the plaintext letter
                if (arr_elem == lower_letter)
                {
                    // Checks if the plaintext letter was uppercase (to match case)
                    if (islower(text_letter) == 0)
                    {
                        ciphertext[i] = toupper(key[j]);
                    }
                    else
                    {
                        ciphertext[i] = tolower(key[j]);
                    }
                }
            }
        }
        // If the letter wasn't alphabetic
        else
        {
            // Same character is copied
            ciphertext[i] = text_letter;
        }
    }

    // Prints opener
    printf("ciphertext: ");

    // Prints ciphertext letter by letter
    for (int k = 0; k < text_len; k++)
    {
        printf("%c", ciphertext[k]);
    }
    // Newline
    printf("\n");
}
