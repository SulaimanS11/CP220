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
#include <string.h>
#include "queue_stack.h"
#include "graph.h"

GRAPH *new_graph(int order) {
  GRAPH *gp = malloc(sizeof(GRAPH));
  gp->nodes = malloc(order * sizeof(GNODE*));
  
  int i;
  for (i = 0; i < order; i++) {
    gp->nodes[i] = malloc(sizeof(GNODE));
    gp->nodes[i]->nid = i;
    strcpy(gp->nodes[i]->name, "null");
    gp->nodes[i]->neighbor = NULL;
  }
  
  gp->order = order;
  gp->size = 0;  
 
  return gp;
}

void insert_edge_graph(GRAPH *g, int from, int to, int weight) {
    if (from >= g->order || to >= g->order)
        return;

    ADJNODE *ptr = g->nodes[from]->neighbor;
    while (ptr != NULL) {
        if (ptr->nid == to) {
            ptr->weight = weight;
            return;
        }
        ptr = ptr->next;
    }

    ADJNODE *new_edge = malloc(sizeof(ADJNODE));
    new_edge->nid = to;
    new_edge->weight = weight;
    new_edge->next = g->nodes[from]->neighbor;
    g->nodes[from]->neighbor = new_edge;
    g->size++;
}

void delete_edge_graph(GRAPH *g, int from, int to) {
    if (from >= g->order || to >= g->order)
        return;

    ADJNODE *prev = NULL;
    ADJNODE *current = g->nodes[from]->neighbor;

    while (current != NULL) {
        if (current->nid == to) {
            if (prev == NULL)
                g->nodes[from]->neighbor = current->next;
            else
                prev->next = current->next;
            free(current);
            g->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

int get_edge_weight(GRAPH *g, int from, int to) {
    if (from >= g->order || to >= g->order)
        return INFINITY;
    ADJNODE *ptr = g->nodes[from]->neighbor;
    while (ptr != NULL) {
        if (ptr->nid == to)
            return ptr->weight;
        ptr = ptr->next;
    }
    return INFINITY; 
}

void traverse_bforder(GRAPH *g, int nid) {
    // sadas
}


// Use auxiliary stack data structure for the algorithm
void traverse_dforder(GRAPH *g, int nid) {
// your code
}

void clean_graph(GRAPH **gp) {
  int i;
  GRAPH *g = *gp;
  ADJNODE *temp, *ptr;
  for (i = 0; i < g->order; i++) {
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      temp = ptr;
      ptr = ptr->next;
      free(temp);
    }
    free(g->nodes[i]);
  }
  free(g->nodes);
  free(g);
  *gp = NULL;
}

void display_graph(GRAPH *g) {
  if (g ) {
  printf("order %d ", g->order);
  printf("size %d ", g->size);
  printf("(from to weight) ");
  int i;
  ADJNODE *ptr;
  for (i = 0; i < g->order; i++) {
    //printf("\n%d:", g->nodes[i]->nid);
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      printf("(%d %d %d) ", i,  ptr->nid, ptr->weight);
      ptr = ptr->next;
    }
  }
  }
}