// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = (LENGTH + 1) * 90; // ASCII 90 = Z;

// Hash table
int n_words_total = 0;
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // 1 Get hash idx
    // 2 access linked list at that idx
    // 3 travers through linked list and check if words match, if: return true
    int hash_idx = hash(word);

    node *cursor = table[hash_idx];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
            return true;

        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // djb2 by Dan Bernstein.
    // unsigned long hash = 5381;
    // int c;
    // while (c == *word++)
    // {
    //     hash = ((hash << 5) + hash) + c;
    // }
    // return hash;
    // Sumup ASCII values in the word
    // Return the % of sum to not go voer bounds of N
    int sum_ascii_vals = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
        sum_ascii_vals += toupper(word[i]);
    return (sum_ascii_vals % N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // 1 Open dict
    // 2 Read one word at a time from file (while loop)
    //   2.1 Alloc new node
    //   2.2 copy word to node
    //   2.3 get hash index and set node in hash table  // append it
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
        return false;

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
            return false;

        strcpy(n->word, word);
        n->next = NULL;

        int hash_idx = hash(word);
        if (table[hash_idx] == NULL)
            table[hash_idx] = n;
        else
        {
            n->next = table[hash_idx];
            table[hash_idx] = n;
        }
        n_words_total++;
    }
    fclose(file);
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return n_words_total;
}

bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}

// clear && make speller && valgrind ./speller texts/lalaland.txt