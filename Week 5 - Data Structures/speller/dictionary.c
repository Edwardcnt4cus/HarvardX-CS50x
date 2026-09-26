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

int no_words = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_value = hash(word);
    node *cursor = table[hash_value];
    while (cursor != NULL)
    {
        if(strcasecmp(cursor -> word, word) ==0)
        {
            return true;
        }

        else
        {
           cursor = cursor -> next;
        }
    }

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
    // TODO
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
        // Open the dictionary file
    FILE *source = fopen(dictionary, "r");

    // Read each word in the file
    if(source == NULL)
    {
        printf(" was not able to open dictionary file\n");
        return false;
    }

    char buffer[45];
    while (fscanf(source, "%s", buffer) !=EOF)
    {
       // Add each word to the hash table
        node *new_word = malloc(sizeof(node));
        int hash_value = hash(buffer);
        strcpy(new_word -> word, buffer);
        new_word -> next = table[hash_value];
        table[hash_value] = new_word;
        no_words++;
    }



    // Close the dictionary file
    fclose(source);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return no_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *temp =table[i];
        node *cursor =table[i];
        while (cursor != NULL)
        {
            cursor = cursor ->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}
