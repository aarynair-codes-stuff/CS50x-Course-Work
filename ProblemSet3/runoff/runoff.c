#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Checks all of the candidates in the candidates array
    for (int i = 0; i < candidate_count; i++)
    {
        string current_candidate_name = candidates[i].name;
        // Checks if the input name matches a candidate name
        if (strcmp(name, current_candidate_name) == 0)
        {
            // Places the candidate at the specified rank
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        // Sets required variables such as first preference and candidate elimination status
        int preference_index = 0;
        candidate chosen_candidate = candidates[preferences[i][preference_index]];
        bool candidate_eliminated = chosen_candidate.eliminated;
        // While the voter's chosen candidate in the index has been eliminated
        while (candidate_eliminated == true)
        {
            // The variables are updated
            preference_index++;
            chosen_candidate = candidates[preferences[i][preference_index]];
            candidate_eliminated = chosen_candidate.eliminated;
        }
        // The first not eliminated candidate gains one vote
        candidates[preferences[i][preference_index]].votes++;
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Sets required variables
    int candidate_index = 0;
    int max_vote = candidates[0].votes;
    // Checks all the candidates
    for (int i = 1; i < candidate_count; i++)
    {
        int current_vote = candidates[i].votes;
        // Checks if the current vote is greater than the maximum vote
        if (current_vote > max_vote)
        {
            // The max vote is set to the current vote
            max_vote = current_vote;
            candidate_index = i;
        }
    }
    // Finds the name(s) of the candidate with the maximum vote
    string candidate_name = candidates[candidate_index].name;
    // Checks if the candidate has more than half of the vote
    if (max_vote > voter_count / 2)
    {
        printf("%s\n", candidate_name);
        return true;
    }
    else
    {
        return false;
    }
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Initialises the min vote variable
    int min_vote;
    // Checks if the first candidate has not been eliminated
    if (candidates[0].eliminated == false)
    {
        // Sets the min vote to their vote count
        min_vote = candidates[0].votes;
    }
    else
    {
        // Otherwise, loops though the candidates until a candidate that has not been eliminated is
        // found
        int index = 1;
        while (candidates[index].eliminated == true)
        {
            index++;
        }
        // Sets the min vote to their vote count
        min_vote = candidates[index].votes;
    }
    // Loops through the candidates
    for (int i = 1; i < candidate_count; i++)
    {
        int current_vote = candidates[i].votes;
        // Checks if they have fewer votes than the minimum vote and if they haven't been eliminated
        // already
        if (current_vote < min_vote && candidates[i].eliminated == false)
        {
            // Sets the min vote to the lower value
            min_vote = current_vote;
        }
    }
    // Returns the min vote
    return min_vote;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Initialises a variable to store the number of candidates who haven't been eliminated
    int available_candidates = 0;
    // Loops through the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Checks if the candidate has not been eliminated
        if (candidates[i].eliminated == false)
        {
            // Increments the count
            available_candidates++;
        }
    }
    // Initialises a variable to store the number of people with the same vote count
    int votes_count = 0;
    // Loops through the candidates
    for (int j = 0; j < candidate_count; j++)
    {
        // Initialises the current vote and the count variables
        int current_vote = candidates[j].votes;
        int current_vote_count = 0;
        // Loops though the candidates
        for (int k = 0; k < candidate_count; k++)
        {
            // Checks if they have the same vote count as the current vote and haven't been
            // eliminated
            if (candidates[k].votes == current_vote && candidates[k].eliminated == false)
            {
                // Increments the count
                current_vote_count++;
            }
        }
        // Checks if the current vote count is greater than the previous vote count
        if (current_vote_count > votes_count)
        {
            // If so, sets the votes count variable
            votes_count = current_vote_count;
        }
    }

    // Checks if all remaining candidates are tied
    if (votes_count == available_candidates)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Checks all the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Checks if they have the minimum vote count
        if (candidates[i].votes == min)
        {
            // Eliminates them if so
            candidates[i].eliminated = true;
        }
    }
    return;
}
