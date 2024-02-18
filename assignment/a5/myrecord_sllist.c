/**
 * -------------------------------------
 * @file  myrecord_sllist.c
 * Assignment #5  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-02-10
 *
 * ------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myrecord_sllist.h"


NODE *sll_search(SLL *sllp, char *name) {
    NODE *current = sllp->start;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Not found
}

void sll_insert(SLL *sllp, char *name, float score) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    strncpy(newNode->data.name, name, 19);
    newNode->data.name[19] = '\0';
    newNode->data.score = score;
    newNode->next = NULL;

    if (sllp->start == NULL || strcmp(sllp->start->data.name, name) > 0) {
        // Insert at the beginning
        newNode->next = sllp->start;
        sllp->start = newNode;
    } else {
        // Find the insertion point
        NODE *current = sllp->start;
        while (current->next != NULL && strcmp(current->next->data.name, name) < 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    sllp->length++;
}

int sll_delete(SLL *sllp, char *name) {
    if (sllp->start == NULL) return 0; // Empty list

    NODE *current = sllp->start;
    NODE *previous = NULL;

    if (strcmp(current->data.name, name) == 0) {
        sllp->start = current->next;
        free(current);
        sllp->length--;
        return 1;
    }

    while (current != NULL && strcmp(current->data.name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return 0; // Not found

    // Unlink node
    previous->next = current->next;
    free(current);
    sllp->length--;
    return 1;
}

void sll_clean(SLL *sllp) {
    NODE *temp, *ptr = sllp->start;
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    sllp->start = NULL;
    sllp->length = 0;
}