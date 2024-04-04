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
#include "heap.h"
#include "algorithm.h"
#include <limits.h>
#include <stdbool.h>

EDGELIST *mst_prim(GRAPH *g, int start) {
// your code
}

EDGELIST *spt_dijkstra(GRAPH *g, int start) {
    int numVertices = g->order;
    int dist[numVertices];
    bool sptSet[numVertices];

    for (int i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX, sptSet[i] = false;
    }

    dist[start] = 0;


    for (int count = 0; count < numVertices - 1; count++) {

        int u = -1;
        int min = INT_MAX;

        for (int v = 0; v < numVertices; v++) {
            if (sptSet[v] == false && dist[v] <= min) {
                min = dist[v], u = v;
            }
        }

        sptSet[u] = true;

        for (ADJNODE *adj = g->nodes[u]->neighbor; adj != NULL; adj = adj->next) {
            int v = adj->nid;

            if (!sptSet[v] && adj->weight && dist[u] != INT_MAX && dist[u] + adj->weight < dist[v]) {
                dist[v] = dist[u] + adj->weight;
            }
        }
    }
}


EDGELIST *sp_dijkstra(GRAPH *g, int start, int end) {
// your code
}