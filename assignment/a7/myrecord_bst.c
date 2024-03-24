/**
 * -------------------------------------
 * @file  myrecord_bst.h
 * Assignment #  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */

#include <stdio.h>
#include <math.h>
#include "queue_stack.h"
#include "bst.h"
#include "myrecord_bst.h"

void add_record(BSTDS *ds, RECORD record) {
    bst_insert(&(ds->root), record);
    
    ds->count++;
    
    float oldMean = ds->mean;
    ds->mean = oldMean + (record.score - oldMean) / ds->count;
    
    if (ds->count > 1) {
        ds->stddev = sqrt(((ds->stddev * ds->stddev * (ds->count - 1)) + (record.score - oldMean) * (record.score - ds->mean)) / ds->count);
    } else {
        ds->stddev = 0;
    }
}

void remove_record(BSTDS *ds, char *name) {
    BSTNODE *node = bst_search(ds->root, name);
    if (node != NULL) {
        ds->count--;
    
        if (ds->count > 0) {
            float oldMean = ds->mean;
            ds->mean = (ds->mean * (ds->count + 1) - node->data.score) / ds->count;
            
            ds->stddev = sqrt(((ds->stddev * ds->stddev * (ds->count + 1)) - (node->data.score - oldMean) * (node->data.score - ds->mean)) / ds->count);
        } else {
            ds->mean = 0;
            ds->stddev = 0;
        }
        bst_delete(&(ds->root), name);
    }
}

void clean_bstds(BSTDS *ds) {
  clean_bst(&ds->root);
  ds->count = 0;
  ds->mean = 0;
  ds->stddev = 0;
}