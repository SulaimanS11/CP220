/**
 * -------------------------------------
 * @file  queue_linked.h
 * Linked Queue Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-02-22
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef QUEUE_LINKED_H_
#define QUEUE_LINKED_H_
 
// Includes
#include <stdio.h>
#include <stdlib.h>
 
#include "data.h"
 
// typedefs
 
typedef struct QUEUE_NODE {
    data_ptr item;            // Pointer to the node data_ptr .
    struct QUEUE_NODE *next;  // Pointer to the next queue node.
} queue_node;
 
typedef struct {
    queue_node *front;   // Pointer to the front node of the queue.
    queue_node *rear;    // Pointer to the rear node of the queue.
    int count;           // Number of items in queue.
} queue_linked;
 
// Prototypes
 
queue_linked* queue_initialize();
 
void queue_free(queue_linked **source);
 
BOOLEAN queue_empty(const queue_linked *source);
 
int queue_count(const queue_linked *source);
 
void queue_insert(queue_linked *source, data_ptr item);
 
BOOLEAN queue_peek(const queue_linked *source, data_ptr item);
 
BOOLEAN queue_remove(queue_linked *source, data_ptr *item);
 
void queue_print(const queue_linked *source);
 
#endif /* QUEUE_LINKED_H_ */