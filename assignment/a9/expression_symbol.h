/**
 * -------------------------------------
 * @file  expression_symbol.c
 * Assignment #  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */

#ifndef EXPRESSION_SYMBOL_H
#define EXPRESSION_SYMBOL_H

#include "common_queue_stack.h"
#include "hash.h"

QUEUE infix_to_postfix_symbol(HASHTABLE *ht, char *infixstr);

int evaluate_infix_symbol(HASHTABLE *ht, char *infixstr);

int evaluate_postfix(QUEUE queue);

HASHDATA evaluate_statement(HASHTABLE *ht, char* statement);

#endif