/**
 * -------------------------------------
 * @file  bst.h
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
#include "bst.h"


BSTNODE *new_node(RECORD data);
BSTNODE *extract_smallest_node(BSTNODE **rootp);

BSTNODE *bst_search(BSTNODE *root, char *key) {
    if (root == NULL) return NULL;
    
    int cmp = strcmp(root->data.name, key);
    if (cmp == 0) {
        return root;
    } else if (cmp > 0) {
        return bst_search(root->left, key);
    } else {
        return bst_search(root->right, key);
    }
}


void bst_insert(BSTNODE **rootp, RECORD data) {
    if (*rootp == NULL) {
        *rootp = new_node(data);
    } else {
        int cmp = strcmp((*rootp)->data.name, data.name);
        if (cmp > 0) {
            bst_insert(&((*rootp)->left), data);
        } else if (cmp < 0) {
            bst_insert(&((*rootp)->right), data);
        }
    }
}

void bst_delete(BSTNODE **rootp, char *key) {
    if (*rootp == NULL) return;

    int cmp = strcmp((*rootp)->data.name, key);
    if (cmp > 0) {
        bst_delete(&((*rootp)->left), key);
    } else if (cmp < 0) {
        bst_delete(&((*rootp)->right), key);
    } else {
        BSTNODE *temp = *rootp;
        if ((*rootp)->left == NULL) {
            *rootp = (*rootp)->right;
        } else if ((*rootp)->right == NULL) {
            *rootp = (*rootp)->left;
        } else {
            temp = extract_smallest_node(&((*rootp)->right));
            (*rootp)->data = temp->data;
            bst_delete(&((*rootp)->right), temp->data.name);
        }
        if (temp != *rootp) free(temp);
    }
}



BSTNODE *new_node(RECORD data) {
    BSTNODE *np = (BSTNODE *) malloc(sizeof(BSTNODE));
    if (np) {
        memcpy(np, &data, sizeof(data));
        np->left = NULL;
        np->right = NULL;
    }
    return np;
}

BSTNODE *extract_smallest_node(BSTNODE **rootp) {
    BSTNODE *p = *rootp, *parent = NULL;
    if (p) {
        while (p->left) {
            parent = p;
            p = p->left;
        }

        if (parent == NULL)
            *rootp = p->right;
        else
            parent->left = p->right;

        p->left = NULL;
        p->right = NULL;
    }

    return p;
}

void clean_bst(BSTNODE **rootp) {
    BSTNODE *root = *rootp;
    if (root) {
        if (root->left)
            clean_bst(&root->left);
        if (root->right)
            clean_bst(&root->right);
        free(root);
    }
    *rootp = NULL;
}