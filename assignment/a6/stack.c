/**
 * -------------------------------------
 * @file  stack.c
 * Assignment #  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */

#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
    np->next = sp->top; // Point new node to the current top
    sp->top = np; 
    sp->length++; 
}

NODE *pop(STACK *sp) {
    if (sp->top == NULL) return NULL; 

    NODE *temp = sp->top; 
    sp->top = sp->top->next; 
    sp->length--; 

    temp->next = NULL; 
    return temp; // Return the popped node
}

void clean_stack(STACK *sp) {
  clean(&(sp->top));
  sp->top = NULL;
  sp->length=0;
}
