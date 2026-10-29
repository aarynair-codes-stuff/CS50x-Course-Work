#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_score(string letter_values[], int size_of_array, string inp_word);
void determine_winner(int score1, int score2);

int main(void)
{
    // Declare the scores for each lower case letter
    string letter_scores[26] = {"a1", "b3", "c3", "d2", "e1", "f4", "g2", "h4", "i1",
                                "j8", "k5", "l1", "m3", "n1", "o1", "p3", "qX", "r1",
                                "s1", "t1", "u1", "v4", "w4", "x8", "y4", "zX"};

    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute the score of each word
    int score1 = get_score(letter_scores, 26, word1);
    int score2 = get_score(letter_scores, 26, word2);

    // Print the winner
    determine_winner(score1, score2);
}

int get_score(string letter_values[], int size_of_array, string inp_word)
{
    // Initialise the score variable
    int score = 0;

    // Calculate the word length
    int word_len = strlen(inp_word);

    for (int i = 0; i < word_len; i++)
    {
        // Takes the ith letter from the word
        char letter = inp_word[i];

        // Converts it to lowercase because the scoring array is in lowercase
        char lower_letter = tolower(letter);

        // Checks if the character against the scoring array
        for (int j = 0; j < size_of_array; j++)
        {
            char arr_elem = letter_values[j][0];

            if (arr_elem == lower_letter)
            {
                // Adds score value to total score if letter matches
                if (letter_values[j][1] == 'X')
                {
                    score += 10;
                }
                else
                {
                    score += letter_values[j][1] - '0';
                }
            }
        }
    }
    return score;
}

void determine_winner(int score1, int score2)
{
    int winner;

    // Checks who won by comparing scores
    if (score1 > score2)
    {
        winner = 1;
    }
    else if (score1 < score2)
    {
        winner = 2;
    }
    else
    {
        winner = 0;
    }

    // Prints winning message by substituting player num or by printing tie if scores are the same
    if (winner == 0)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player %i wins!\n", winner);
    }
}
