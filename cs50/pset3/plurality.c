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
    // Populate array of candidates
    // Get number of voters
    // Loop over voter counts
    //   get vote
    //   check if valid
    // print winner

    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

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

bool vote(string name)
{
    // Take in a name str of the canidates name;
    // Find the right candiate from the list of candiates via loop an
    // compering candidates[i].name and name;
    // Increment the according vote and return true;
    // Use strcmp as we can not compare two strings direcetly otherwise (see
    // audience question.);
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Loop over candiates and find the highest number of votes. Store it in
    // highestNumberOfVotes. If candidates[i].votes is larger, update the
    // variable accordingly.
    int highestNumberOfVotes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (highestNumberOfVotes < candidates[i].votes)
        {
            highestNumberOfVotes = candidates[i].votes;
        }
    }

    // Loop over candiates and print all candiates which .votes ==
    // highestNumberOfVotes;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == highestNumberOfVotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
