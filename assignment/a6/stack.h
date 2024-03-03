/**
 * -------------------------------------
 * @file  stack.h
 * Assignment #  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */

#ifndef STACK_H
#define STACK_H
#include "common.h"

typedef struct stack {
  int length;  
  NODE *top;
} STACK;

/* 
 * Push a node into a linked list stack
 * @param STACK *sp - pointer to the stack 
 * @param NODE *np - pointer to the node.
*/ 
void push(STACK *sp, NODE *np);

/* 
 * Pop and return the pointer of the removed top node
 * @param STACK *sp - pointer to the stack
 * @return - the reference of the removed node and set it's next to NULL  
*/ 
NODE *pop(STACK *sp); 

/*
 * clean the linked list stack
 */ 
void clean_stack(STACK *sp);

#endif