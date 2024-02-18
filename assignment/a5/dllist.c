/**
 * -------------------------------------
 * @file  dllist.c
 * Assignment #5  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-02-10
 *
 * ------------------------------------- */

#include <stdio.h>
#include <stdlib.h> 
#include "dllist.h"

NODE *new_node(char data) {
    NODE *np = (NODE *)malloc(sizeof(NODE));
    if (np != NULL) {
        np->data = data;
        np->prev = NULL;
        np->next = NULL;
    }
    return np;
}

void dll_insert_start(DLL *dllp, NODE *np) {
    if (dllp->start == NULL) { // List is empty
        dllp->start = dllp->end = np;
    } else {
        np->next = dllp->start;
        dllp->start->prev = np;
        dllp->start = np;
    }
    dllp->length++;
}

void dll_insert_end(DLL *dllp, NODE *np) {
    if (dllp->end == NULL) { // List is empty
        dllp->start = dllp->end = np;
    } else {
        np->prev = dllp->end;
        dllp->end->next = np;
        dllp->end = np;
    }
    dllp->length++;
}

void dll_delete_start(DLL *dllp) {
    if (dllp->start == NULL) return; // List is empty

    NODE *temp = dllp->start;
    if (dllp->start == dllp->end) { // Only one node
        dllp->start = dllp->end = NULL;
    } else {
        dllp->start = dllp->start->next;
        dllp->start->prev = NULL;
    }
    free(temp);
    dllp->length--;
}

void dll_delete_end(DLL *dllp) {
    if (dllp->end == NULL) return; // List is empty

    NODE *temp = dllp->end;
    if (dllp->start == dllp->end) { // Only one node
        dllp->start = dllp->end = NULL;
    } else {
        dllp->end = dllp->end->prev;
        dllp->end->next = NULL;
    }
    free(temp);
    dllp->length--;
}

void dll_clean(DLL *dllp) {
    NODE *current = dllp->start;
    while (current != NULL) {
        NODE *next = current->next;
        free(current);
        current = next;
    }
    dllp->start = NULL;
    dllp->end = NULL;
    dllp->length = 0;
}