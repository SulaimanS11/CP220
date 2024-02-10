/**
 * -------------------------------------
 * @file  mystring.c
 * Assignment 3  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */

#include "mystring.h"


/**
 *  add your comment
 */
int str_words(char *s) {
    int count = 0;
    while (*s) {
        count++;
        s++;
    }
    return count;
}

/**
 *  add your comment
 */
int str_lower(char *s) {
    while  (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s += ('a'-'A');
        }
        s++;
    }
    return 0;
}

/**
 * Remove unnecessary space characters in a simple string passed by `s`. Does not skip leading or trailing spaces.
 *
 * @param s - char pointer to a str
 */
void str_trim(char *s) {
    int i, j;
    int len = 0;
    int in_word = 0;

    while (s[len] != '\0') len++;

    while (s[0] == ' ') {
        for (i = 0; i < len; i++) {
            s[i] = s[i + 1];
        }
        len--;
    }

    while (s[len - 1] == ' ') s[--len] = '\0';
    

    for (i = 0, j = 0; i <= len; i++) {
        if (s[i] != ' ') {
            s[j++] = s[i];
            in_word = 1;
        } else if (in_word) {
            s[j++] = s[i];
            in_word = 0;
        }
    }
}