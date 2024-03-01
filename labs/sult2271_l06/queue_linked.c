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
// Includes
#include "queue_linked.h"

// Functions

// Initializes a queue
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
        free(temp->item); // Ensure data_ptr management is handled correctly
        free(temp);
    }
    free(*source);
    *source = NULL;
}

// Determines if a queue is empty
BOOLEAN queue_empty(const queue_linked *source) {
    return !source || source->count == 0;
}

// Returns the number of items in a queue
int queue_count(const queue_linked *source) {
    return source ? source->count : 0;
}

// Pushes a copy of an item onto a queue
void queue_insert(queue_linked *source, data_ptr item) {
    if (!source) return;
    queue_node *newNode = (queue_node *)malloc(sizeof(queue_node));
    if (!newNode) {
        fprintf(stderr, "Failed to allocate memory for a new node.\n");
        return;
    }
    newNode->item = malloc(sizeof(*item)); // Allocate memory for the item
    if (!newNode->item) {
        fprintf(stderr, "Failed to allocate memory for the item.\n");
        free(newNode);
        return;
    }
    *(newNode->item) = *item; // Assuming data_ptr is a pointer to a type like int
    newNode->next = NULL;

    if (source->rear == NULL) { // Empty queue
        source->front = source->rear = newNode;
    } else {
        source->rear->next = newNode;
        source->rear = newNode;
    }
    source->count++;
}

// Returns a copy of the item on the front of a queue
BOOLEAN queue_peek(const queue_linked *source, data_ptr item) {
    if (queue_empty(source) || !item) return FALSE;
    // Assuming direct assignment works as intended; may need adjustment for complex data_ptr types
    *item = *(source->front->item);
    return TRUE;
}

// Removes and returns the item on the front of a queue
BOOLEAN queue_remove(queue_linked *source, data_ptr *item) {
    if (queue_empty(source) || !item) return FALSE;
    queue_node* temp = source->front;
    *item = temp->item; // Direct assignment, adjust for data_ptr as needed
    source->front = source->front->next;
    if (!source->front) source->rear = NULL;
    free(temp);
    source->count--;
    return TRUE;
}

// Prints the items in a queue from front to rear
void queue_print(const queue_linked *source) {
    queue_node* current = source->front;
    while (current) {
        // Implement data_ptr printing according to its structure
        printf("%p ", current->item); // Placeholder, replace with actual data printing
        current = current->next;
    }
    printf("\n");
}