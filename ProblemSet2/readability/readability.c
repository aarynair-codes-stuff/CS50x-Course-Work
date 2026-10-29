#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_letters(char letters[], int size_of_array, string inp_text, int text_len);
int get_words(string inp_text, int text_len);
int get_sentences(string inp_text, int text_len);
int C_L_index(int letters, int words, int sentences);
void grade_output(int grade);

int main(void)
{
    char lowercase_letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // Prompt the user for some text
    string text = get_string("Text: ");
    int text_len = strlen(text);

    // Count the number of letters, words, and sentences in the text
    int letter_count = get_letters(lowercase_letters, 26, text, text_len);
    int word_count = get_words(text, text_len);
    int sentence_count = get_sentences(text, text_len);

    // Compute the Coleman-Liau index
    int grade = C_L_index(letter_count, word_count, sentence_count);

    // Print the grade level
    grade_output(grade);
}

int get_letters(char letters[], int size_of_array, string inp_text, int text_len)
{
    // Initialise the total variable
    int total = 0;

    for (int i = 0; i < text_len; i++)
    {
        // Takes the ith letter from the text
        char letter = inp_text[i];

        // Converts it to lowercase because the letters array is in lowercase
        char lower_letter = tolower(letter);

        // Checks if the character against the letters array
        for (int j = 0; j < size_of_array; j++)
        {
            char arr_elem = letters[j];

            if (arr_elem == lower_letter)
            {
                total++;
            }
        }
    }
    return total;
}

int get_words(string inp_text, int text_len)
{
    // Initialise the total variable
    int total = 1;

    for (int i = 0; i < text_len; i++)
    {
        if (inp_text[i] == ' ')
        {
            total++;
        }
    }
    return total;
}

int get_sentences(string inp_text, int text_len)
{
    // Initialise the total variable
    int total = 0;

    for (int i = 0; i < text_len; i++)
    {
        if (inp_text[i] == '.' || inp_text[i] == '!' || inp_text[i] == '?')
        {
            total++;
        }
    }
    return total;
}

int C_L_index(int letters, int words, int sentences)
{
    float l_per_100 = (letters / (float) words) * 100;
    float s_per_100 = (sentences / (float) words) * 100;

    float index = 0.0588 * l_per_100 - 0.296 * s_per_100 - 15.8;

    int grade = (int) round(index);
    return grade;
}

void grade_output(int grade)
{
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
