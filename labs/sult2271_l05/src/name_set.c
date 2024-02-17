/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-02-09
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set* name_set_initialize() {
    
    name_set *set = malloc(sizeof *set);
    
    set->front = NULL;
    set->rear = NULL;
    return set;
}

int name_set_free(name_set **set) {
    int freed_count = 0;
    name_set_node *current = (*set)->front;
    while (current != NULL) {
        name_set_node *temp = current;
        current = current->next;
        free(temp);
        freed_count++;
    }
    free(*set);
    *set = NULL;
    return freed_count;
}

BOOLEAN name_set_append(name_set *set, const char *first_name, const char *last_name) {
    if (name_set_contains(set, first_name, last_name)) {
        return FALSE;
    }

    name_set_node *new_node = malloc(sizeof(name_set_node));
    if (!new_node) {
        return FALSE;
    }
    strncpy(new_node->first_name, first_name, NAME_LEN);
    strncpy(new_node->last_name, last_name, NAME_LEN);
    new_node->next = NULL;

    if (set->rear == NULL) {
        set->front = set->rear = new_node;
    } else {
        set->rear->next = new_node;
        set->rear = new_node;
    }

    return TRUE;
}

BOOLEAN name_set_contains(const name_set *set, const char *first_name, const char *last_name) {
    for (name_set_node *current = set->front; current != NULL; current = current->next) {
        if (strcmp(current->first_name, first_name) == 0 && strcmp(current->last_name, last_name) == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

void name_set_print(const name_set *set) {
    for (name_set_node *current = set->front; current != NULL; current = current->next) {
        printf("%s, %s\n", current->last_name, current->first_name);
    }
}