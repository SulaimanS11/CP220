/**
 * -------------------------------------
 * @file  hash.h
 * Assignment #  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */

#ifndef HASH_H
#define HASH_H

typedef struct {
    char key[20];
    int value;
} HASHDATA;

typedef struct hashnode {
  char key[20];
  int  value;
  struct hashnode *next; 
} HASHNODE;

typedef struct hashtable {
  HASHNODE **hna;
  int size;
  int count;
} HASHTABLE;

int hash(char *key, int size);

HASHTABLE *new_hashtable(int size); 

int hashtable_insert(HASHTABLE *ht, char *key, int value);

HASHNODE *hashtable_search(HASHTABLE *ht, char *key);

int hashtable_delete(HASHTABLE *ht, char *key);

void hashtable_clean(HASHTABLE **ht);

#endif