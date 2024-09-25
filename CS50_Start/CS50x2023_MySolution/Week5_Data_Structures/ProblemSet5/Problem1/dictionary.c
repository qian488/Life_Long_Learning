// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>

#include "dictionary.h"

// 读文件暂存到链表中，load就是读文件构建链表，unload就是释放链表
// 链表+哈希

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Choose number of buckets in hash table
#define N 100005

int loaded_size = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    for (node *tmp = table[hash(word)]; tmp != NULL; tmp = tmp->next)
    {
        // Your implementation of check must be case-insensitive.
        if (strcasecmp(word, tmp->word) == 0) // 找到返回真
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long long int hash = 0;
    unsigned long long int prime = 131;

    for (int i = 0; i < strlen(word); i++) {
        hash = (hash * prime + tolower(word[i])) % N;
    }

    return (unsigned int)hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
     FILE *file = fopen(dictionary, "rb");
    if (file == NULL) return false;

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL) return false;

        strcpy(n->word, word);
        n->next = table[hash(word)];
        table[hash(word)] = n;
        loaded_size++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return loaded_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];

        while (n != NULL)
        {
            node *tmp = n;
            n = n->next;
            free(tmp);
        }

        if (n == NULL && i == N - 1) return true;
    }
    return false;
}
