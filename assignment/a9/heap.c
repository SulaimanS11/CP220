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
#include "heap.h"

int cmp(KEYTYPE a, KEYTYPE b) {
  int r = 0;
  if (a < b) r = -1;
  else if (a > b) r = 1;
  return r;
}

HEAP *new_heap(int capacity)
{
  HEAP *hp = (HEAP*) malloc(sizeof(HEAP));
  if (hp == NULL) return NULL;
  hp->hda = (HEAPDATA *) malloc(sizeof(HEAPDATA) * capacity);
  if ( hp->hda == NULL) { free(hp); return NULL; };
  hp->capacity = capacity;
  hp->size = 0;
  return hp;
}

// you may add this function to be used other functions.
int heapify_up(HEAPDATA *hda, int index) {
// your code
}

// you may add this function to be used other functions.
int heapify_down(HEAPDATA *hda, int n, int index) {
// your code
}

void heap_insert(HEAP *heap, HEAPDATA new_node)
{
// your code
}

HEAPDATA heap_find_min(HEAP *heap)
{
// your code
}

HEAPDATA heap_extract_min(HEAP *heap)
{
// your code
}

int heap_change_key(HEAP *heap, int index, KEYTYPE new_key)
{
// your code
}

int heap_search_data(HEAP *heap, VALUETYPE data) {
// your code
}

void heap_clean(HEAP **heapp) {
  if (heapp) {
    HEAP *heap = *heapp;
    if (heap->capacity > 0) {
      heap->capacity = 0;
      heap->size = 0;
      free(heap->hda);
      free(heap);
    }
    *heapp = NULL;
  }
}