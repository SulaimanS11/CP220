/**
 * -------------------------------------
 * @file  queue.h
 * Assignment #  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */

#ifndef QUEUE_H
#define QUEUE_H
#include "common.h"

typedef struct queue {
  int length;  
  NODE *front;
  NODE *rear;
} QUEUE;    

/* 
 * Enqueue a node into a queue
 * @param *qp - pointer to the queue 
 * @param NODE *np - pointer to the node.
*/
void enqueue(QUEUE *qp, NODE *np);  

/* 
 * Dequeue and return the pointer of the removed node. 
 * @param *qp - pointer to the queue
 * @return - the reference of the removed node, and set it's next to NULL 
*/
NODE *dequeue(QUEUE *qp);

/* 
 * Clean the linked list queue
*/
void queue_clean(QUEUE *qp);

#endif