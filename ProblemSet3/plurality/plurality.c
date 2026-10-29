#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Loops through the candidate names
    for (int i = 0; i < candidate_count; i++)
    {
        // If the input name matches one of them
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Their vote is incremented by one
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Set the maximum vote to the first vote value
    int maximum_vote = candidates[0].votes;
    // Loop through the votes of each candidate
    for (int i = 1; i < candidate_count; i++)
    {
        int vote = candidates[i].votes;
        // If the current vote value is greater than the maximum vote
        if (vote > maximum_vote)
        {
            // The maximum vote is updated
            maximum_vote = vote;
        }
    }

    // Initialises the count variable
    int count = 0;
    // Creates an array to store the name of successful candidates
    string names[9];
    // Loop through the votes of each candidate
    for (int j = 0; j < candidate_count; j++)
    {
        int vote = candidates[j].votes;
        // If the current vote matches the maximum vote
        if (vote == maximum_vote)
        {
            // Increment the count variable
            count++;
            // Add the candidates name to the names array
            names[count] = candidates[j].name;
        }
    }

    // Loop through the names array
    for (int k = 1; k <= count; k++)
    {
        // Print the names of all successful candidates
        printf("%s\n", names[k]);
    }

    return;
}
