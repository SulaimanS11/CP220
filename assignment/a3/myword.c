/**
 * -------------------------------------
 * @file  myword.c
 * Assignment 3  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */

#include <stdio.h>
#include <string.h>
#include "myword.h"
#include "mystring.h"

#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000

/**
 *  add your comment
 */
int create_dictionary(FILE *fp, char *dictionary) {
    char line[MAX_LINE_LEN];
    int count = 0;
    
    while (fgets(line, sizeof(line), fp)) {
    
        strcpy(&dictionary[count*MAX_LINE_LEN], line);
        count++;
    }
    
    return count;
}

/*
 * Determine if a given word is contained in the given dictionary.  
 * 
 * @param *dictionary -  char pointer to a char array of given dictionary.
 * @param *word  -  pointer to a given word.  
 *                     
 * @return - TRUE if the word is in the dictionary, FALSE otherwise.   
 */
BOOLEAN contain_word(char *dictionary, char *word) {
    while (*dictionary != '\0') {
        char *temp_d = dictionary;
        char *temp_w = word;

        while (*temp_d == *temp_w && *temp_w != '\0') {
            temp_d++;
            temp_w++;
        }

        if (*temp_w == '\0' && (*temp_d == ' ' || *temp_d == '\0')) {
            return TRUE;
        }

        while (*dictionary != ' ' && *dictionary != '\0') {
            dictionary++;
        }

        if (*dictionary == ' ') {
            dictionary++;
        }
    }
    return FALSE;
}

/**
 *  add your comment
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
// your code
}