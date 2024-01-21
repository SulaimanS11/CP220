/**
 * -------------------------------------
 * @file  mychar.h
 * Assignment 1  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */
#include "mychar.h"
#include <assert.h>
/**
 *  add your comment
 */
int mytype(char c) {
 /* Check for digits */
 if (c >= '0' && c <= '9') return 0;
 /* Check for arithmetic ops*/
 else if ((c == '+' || c == '-' || c== '/' || c == '%' || c =='*'|| c=='^')) return 1;
 /* Check for alphabets */
 else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) return 2;
 /* If none of the above conditions are met, then it must be invalid */
 else return -1;
}

/**
 *  add your comment
 */
char case_flip(char c) {
 if ('a' <= c && c <= 'z') return c - ('a'-'A');	/* Convert to uppercase */
 else if ('A' <= c && c <= 'Z') return c + ('a'-'A');	/* Convert to lowercase */
 else return c;	/* Return as it is if not an alphabetical character */
}

/**
 *  add your comment
 */
int char_to_int(char c) {
 assert((c >= '0' && c <= '9'));
 return c - '0';
}