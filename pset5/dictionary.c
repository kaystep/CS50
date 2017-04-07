/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

//us this to index where in a word you are
    int place_of_c(const char c)
    {
        if (c == '\'')
        {
            return 26;
        }
        else
        {
            return tolower(c) - 'a';
        }
    }
    
    typedef struct node
    {
        bool is_word;
        //pointers to other nodes
        struct node *children[27];
    }
    node;

    //initialize root node
    node *root;
    
    //Words in dictionary counter variable
    unsigned int words_in_dictionary = 0;
    
    //Words Mispelled Counter variable
    int words_misspelled = 0;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    node* current_node = root;
    //loop over every character in the string until you hit \0 which signifies the end of a word
    for (int i = 0; word[i] != '\0'; i++)
    {
    int index = place_of_c(word[i]);
    
    if (current_node->children[index] == NULL)
    {
    words_misspelled++;
    return false;
    }
    else
    {
      current_node = current_node->children[index];  
    }
    //the loop will end at the end of a word
    }

if (current_node->is_word == true)
{
    return true;
}
else
{
    return false;
}

return false;
    
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{

    
    
    //Make space for the root node
    root = malloc(sizeof(node));
    
    //set the checker to the beginning of the trie, the checker will be used to keep track of where we are in the trie
    node *current_node = root;
    
    //open the dictionary
    FILE *dictionary_open = fopen(dictionary, "r");
    if (dictionary_open == NULL)
    {
        printf("Could not open dictionary\n");
        return false;
    }
    
   words_in_dictionary = 0;
    //Read every word in the dictionary
    for (int c = fgetc(dictionary_open); c != EOF; c = fgetc(dictionary_open))
    {
    if (c == '\n')
    {
        //if hit new line must be a word, set is_word to true
        current_node->is_word = true;
        
        //Add to the word counter
        words_in_dictionary++;
        
        //Start back at the beginning of the tree
        current_node = root;
        
        
    }
    else 
    {
        //if you're not at a new linew figure out where in the trie you are by calling the place_of_c function
        int index = place_of_c(c);
        
        //See if there is a node for this letter
        if (current_node->children[index] == NULL)
        {
            //if no node create a new node for this letter
            current_node->children[index] = malloc(sizeof(node));
        }
        //start creating the next node
        current_node = current_node->children[index];
    }
    
    }
    
    fclose(dictionary_open);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    
    return words_in_dictionary;
}



bool free_dictionary(node* current_node)
{
    int i;
    
    for (i = 0; i < 27; i++)
    {
    if(current_node->children[i] != NULL)
    {
        free_dictionary(current_node->children[i]);
    }
    }
    free(current_node);
   
    return true; 
}
/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    
    return free_dictionary(root);
}