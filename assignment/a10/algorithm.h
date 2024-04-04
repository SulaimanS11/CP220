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
#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "edgelist.h"
#include "graph.h"

 /* Compute and return MST by Prim's algorithm using priority queue (min-heap) 
 * @param g     - graph by reference
 * @param start - the root node of MST
 * @return      - pointer of edge list of shortest path tree
*/ 
EDGELIST *mst_prim(GRAPH *g, int start);

/* 
 * Compute shortest path tree as edge list by Dijkstra's algorithm using priority queue (min-heap) 
 * @param g     - graph by reference
 * @param start - the root node of shortest path tree
 * @return      - pointer of edge list of shortest path tree 
*/ 
EDGELIST *spt_dijkstra(GRAPH *g, int start);

/* 
 * Compute shortest path as edge list by Dijkstra's algorithm using priority queue (min-heap) 
 * @param g     - graph by reference
 * @param start - the start node of shortest path
 * @param end   - the end node of shortest path
 * @return      - pointer of edge list of shortest path
*/ 
EDGELIST *sp_dijkstra(GRAPH *g, int start, int end);

#endif