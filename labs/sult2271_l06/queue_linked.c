/**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author name, ID, email
 *
 * @version 2024-02-22
 *
 * -------------------------------------
 */

#include "queue_linked.h"



queue_linked* queue_initialize() {
    queue_linked* q = (queue_linked*)malloc(sizeof(queue_linked));
    if (!q) return NULL;
    q->front = q->rear = NULL;
    q->count = 0;
    return q;
}

// Frees queue memory
void queue_free(queue_linked **source) {
    if (!source || !*source) return;
    queue_node* current = (*source)->front;
    while (current) {
        queue_node* temp = current;
        current = current->next;
        free(temp->item); 
        free(temp);
    }
    free(*source);
    *source = NULL;
}

BOOLEAN queue_empty(const queue_linked *source) {
    return !source || source->count == 0;
}

int queue_count(const queue_linked *source) {
    return source ? source->count : 0;
}

void queue_insert(queue_linked *source, data_ptr item) {
    if (!source) return;
    queue_node *newNode = (queue_node *)malloc(sizeof(queue_node));
    if (!newNode) {
        fprintf(stderr, "Failed to allocate memory for a new node.\n");
        return;
    }
    newNode->item = malloc(sizeof(*item)); 
    if (!newNode->item) {
        fprintf(stderr, "Failed to allocate memory for the item.\n");
        free(newNode);
        return;
    }
    *(newNode->item) = *item; 
    newNode->next = NULL;

    if (source->rear == NULL) { // Empty queue
        source->front = source->rear = newNode;
    } else {
        source->rear->next = newNode;
        source->rear = newNode;
    }
    source->count++;
}

BOOLEAN queue_peek(const queue_linked *source, data_ptr item) {
    if (queue_empty(source) || !item) return FALSE;

    *item = *(source->front->item);
    return TRUE;
}


BOOLEAN queue_remove(queue_linked *source, data_ptr *item) {
    if (queue_empty(source) || !item) return FALSE;
    queue_node* temp = source->front;
    *item = temp->item; 
    source->front = source->front->next;
    if (!source->front) source->rear = NULL;
    free(temp);
    source->count--;
    return TRUE;
}


void queue_print(const queue_linked *source) {
    queue_node* current = source->front;
    while (current) {

        printf("%p ", current->item); 
        current = current->next;
    }
    printf("\n");
}