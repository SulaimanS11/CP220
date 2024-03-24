/**
 * -------------------------------------
 * @file  hash.c
 * Assignment #  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "hash.h"

HASHNODE *hashtable_search(HASHTABLE *ht, char *key) {
    int index = hash(key, ht->size);
    HASHNODE *current = ht->hna[index];
    
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int hashtable_insert(HASHTABLE *ht, char *key, int value) {
    int index = hash(key, ht->size);
    HASHNODE **head = &(ht->hna[index]);
    HASHNODE *current = *head;
    HASHNODE *prev = NULL;
    
    // Find the appropriate position in the linked list to maintain sorted order
    while (current != NULL && strcmp(current->key, key) < 0) {
        prev = current;
        current = current->next;
    }
    
    // Check if the key already exists and update the value
    if (current != NULL && strcmp(current->key, key) == 0) {
        current->value = value;
        return 0;
    }
    
    // Create a new HASHNODE for the key-value pair
    HASHNODE *new_node = (HASHNODE *)malloc(sizeof(HASHNODE));
    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = current;
    
    if (prev == NULL) {
        *head = new_node; // Insert at the beginning
    } else {
        prev->next = new_node; // Insert after the previous node
    }
    
    ht->count++;
    return 1;
}

int hashtable_delete(HASHTABLE *ht, char *key) {
    int index = hash(key, ht->size);
    HASHNODE **head = &(ht->hna[index]);
    HASHNODE *current = *head;
    HASHNODE *prev = NULL;
    
    while (current != NULL && strcmp(current->key, key) != 0) {
        prev = current;
        current = current->next;
    }
    
    // Key not found
    if (current == NULL) {
        return 0;
    }
    
    // Remove the node from the linked list
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    
    free(current);
    ht->count--;
    return 1;
}


int hash(char* key, int size) {
    unsigned int hash = 0;
    while (*key) {
        hash += *key++;
    }
    return hash % size;
}

HASHTABLE *new_hashtable(int size) {
    HASHTABLE *ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));
    ht->hna = (HASHNODE**) malloc(sizeof(HASHNODE**) * size);
    int i;
    for (i = 0; i < size; i++)
        *(ht->hna + i) = NULL;

    ht->size = size;
    ht->count = 0;
    return ht;
}


void hashtable_clean(HASHTABLE **htp) {
    if (*htp == NULL)
        return;
    HASHTABLE *ht = *htp;
    HASHNODE *p, *temp;
    int i;
    for (i = 0; i < ht->size; i++) {
        p = ht->hna[i];
        while (p) {
            temp = p;
            p = p->next;
            free(temp);
        }
        ht->hna[i] = NULL;
    }
    free(ht->hna);
    ht->hna = NULL;
    *htp = NULL;
}