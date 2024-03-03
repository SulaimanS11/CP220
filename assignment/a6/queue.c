/**
 * -------------------------------------
 * @file  queue.c
 * Assignment #  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */

#include "queue.h"
#include "common.h"
#include "stddef.h"

void enqueue(QUEUE *qp, NODE *np) {
    if (qp->rear == NULL) { 
        qp->front = qp->rear = np; 
    } else {
        qp->rear->next = np; 
        qp->rear = np; 
    }
    qp->length++; 
    qp->rear->next = NULL; 
}

NODE *dequeue(QUEUE *qp) {
    if (qp->front == NULL) { 
        return NULL; 
    }
    NODE *temp = qp->front; 
    qp->front = qp->front->next; // Update the front to the next node
    if (qp->front == NULL) {
        qp->rear = NULL; 
    }
    qp->length--;
    temp->next = NULL; 
    return temp; // Return the dequeued node
}

void queue_clean(QUEUE *qp) {
    while(dequeue(qp) != NULL); 
}