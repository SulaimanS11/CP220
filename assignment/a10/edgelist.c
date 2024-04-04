/**
 * -------------------------------------
 * @file  name.c
 * Assignment #  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */

#include <stdio.h>
#include <stdlib.h> 
#include "edgelist.h"

EDGELIST *new_edgelist() {
    EDGELIST *tp = malloc(sizeof(EDGELIST));
    tp->size = 0;
    tp->start = NULL;
    tp->end = NULL;
    return tp;
}

void insert_edge_end(EDGELIST *g, int from, int to, int weight) {
    EDGENODE *new_edge = malloc(sizeof(EDGENODE));
    new_edge->from = from;
    new_edge->to = to;
    new_edge->weight = weight;
    new_edge->next = NULL;

    if (g->start == NULL) {
        g->start = new_edge;
        g->end = new_edge;
    } else {
        g->end->next = new_edge;
        g->end = new_edge;
    }
    g->size++;
}

void insert_edge_start(EDGELIST *g, int from, int to, int weight) {
    EDGENODE *new_edge = malloc(sizeof(EDGENODE));
    new_edge->from = from;
    new_edge->to = to;
    new_edge->weight = weight;
    new_edge->next = g->start;
    g->start = new_edge;

    if (g->end == NULL)
        g->end = new_edge;

    g->size++;
}

void delete_edge(EDGELIST *g, int from, int to) {
    EDGENODE *prev = NULL;
    EDGENODE *current = g->start;

    while (current != NULL) {
        if (current->from == from && current->to == to) {
            if (prev == NULL) {
                g->start = current->next;
                if (g->start == NULL)
                    g->end = NULL;
            } else {
                prev->next = current->next;
                if (prev->next == NULL)
                    g->end = prev;
            }
            free(current);
            g->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

int weight_edgelist(EDGELIST *g) {
    int total_weight = 0;
    EDGENODE *current = g->start;
    while (current != NULL) {
        total_weight += current->weight;
        current = current->next;
    }
    return total_weight;
}

void clean_edgelist(EDGELIST **gp) {
    EDGELIST *g = *gp;
    EDGENODE *temp, *p = g->start;
    while (p) {
        temp = p;
        p = p->next;
        free(temp);
    }
    free(g);
    *gp = NULL;
}

void display_edgelist(EDGELIST *g) {
    if (g == NULL)
        return;
    printf("size %d ", g->size);
    printf("(from to weight) ");
    EDGENODE *p = g->start;
    while (p) {
        printf("(%d %d %d) ", p->from, p->to, p->weight);
        p = p->next;
    }
}