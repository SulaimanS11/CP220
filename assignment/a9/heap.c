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

void swap(HEAPDATA *a, HEAPDATA *b) {
    HEAPDATA temp = *a;
    *a = *b;
    *b = temp;
}

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
void heapify_up(HEAPDATA *hda, int index) 
{
    while (index != 0 && cmp(hda[(index - 1) / 2].key, hda[index].key) > 0) {
        swap(&hda[(index - 1) / 2], &hda[index]);
        index = (index - 1) / 2;
    }
}

// you may add this function to be used other functions.
void heapify_down(HEAPDATA *hda, int n, int index) 
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && cmp(hda[left].key, hda[smallest].key) < 0)
        smallest = left;

    if (right < n && cmp(hda[right].key, hda[smallest].key) < 0)
        smallest = right;

    if (smallest != index) {
        swap(&hda[index], &hda[smallest]);
        heapify_down(hda, n, smallest);
    }
}

void heap_insert(HEAP *heap, HEAPDATA data) 
{
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->hda = realloc(heap->hda, heap->capacity * sizeof(HEAPDATA));
    }

    heap->hda[heap->size] = data;
    heapify_up(heap->hda, heap->size);
    heap->size++;
}

HEAPDATA heap_find_min(HEAP *heap)
{
    if (heap->size == 0) {
        // Error: heap is empty
        HEAPDATA null_data = {0};
        return null_data;
    }
    return heap->hda[0];
}

HEAPDATA heap_extract_min(HEAP *heap)
{
    if (heap->size == 0) {
        // Error: heap is empty
        HEAPDATA null_data = {0};
        return null_data;
    }

    HEAPDATA minData = heap->hda[0];
    heap->hda[0] = heap->hda[heap->size - 1];
    heap->size--;
    heapify_down(heap->hda, heap->size, 0);

    if (heap->size <= (heap->capacity / 4) && heap->capacity > 4) {
        heap->capacity /= 2;
        heap->hda = realloc(heap->hda, heap->capacity * sizeof(HEAPDATA));
    }

    return minData;
}

int heap_change_key(HEAP *heap, int index, KEYTYPE new_key)
{
    if (index < 0 || index >= heap->size) {
        // Error: index out of bounds
        return -1;
    }

    KEYTYPE old_key = heap->hda[index].key;
    heap->hda[index].key = new_key;

    if (cmp(new_key, old_key) < 0) {
        heapify_up(heap->hda, index);
    } else {
        heapify_down(heap->hda, heap->size, index);
    }

    return index;
}

int heap_search_data(HEAP *heap, VALUETYPE data) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->hda[i].value == data) {
            return i;
        }
    }
    return -1;
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