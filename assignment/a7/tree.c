/**
 * -------------------------------------
 * @file  tree.h
 * Assignment #  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h"
#include "tree.h"

TPROPS tree_property(TNODE *root) {
    TPROPS props = {0, 0};
    return props;
}

void preorder(TNODE *root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TNODE *root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void postorder(TNODE *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

void bforder(TNODE *root) {
    if (!root) return;
    QUEUE queue = {0};
    enqueue(&queue, root);
    TNODE *current;
    while ((current = dequeue(&queue)) != NULL) {
        printf("%c ", current->data);
        if (current->left) enqueue(&queue, current->left);
        if (current->right) enqueue(&queue, current->right);
    }
    clean_queue(&queue);
}

TNODE *bfs(TNODE *root, char val) {
    if (!root) return NULL;
    QUEUE queue = {0};
    enqueue(&queue, root);
    TNODE *current;
    while ((current = dequeue(&queue)) != NULL) {
        if (current->data == val) {
            clean_queue(&queue);
            return current;
        }
        if (current->left) enqueue(&queue, current->left);
        if (current->right) enqueue(&queue, current->right);
    }
    clean_queue(&queue);
    return NULL;
}

TNODE *dfs(TNODE *root, char val) {
    if (!root) return NULL;
    STACK stack = {0};
    push(&stack, root);
    TNODE *current;
    while ((current = pop(&stack)) != NULL) {
        if (current->data == val) {
            clean_stack(&stack);
            return current;
        }
        if (current->right) push(&stack, current->right);
        if (current->left) push(&stack, current->left);
    }
    clean_stack(&stack);
    return NULL;
}

// the following functions are given, need to add to your program.

TNODE *new_node(char val) {
    TNODE *np = (TNODE *) malloc(sizeof(TNODE));
    if (np != NULL) {
        np->data = val;
        np->left = NULL;
        np->right = NULL;
    }
    return np;
}

void clean_tree(TNODE **rootp) {
    TNODE *p = *rootp;
    if (p) {
        if (p->left)
            clean_tree(&p->left);
        if (p->right)
            clean_tree(&p->right);
        free(p);
    }
    *rootp = NULL;
}

void insert_tree(TNODE **rootp, char val) {
    if (*rootp == NULL) {
        *rootp = new_node(val);
    } else {
        QUEUE queue = { 0 };
        TNODE *p;
        enqueue(&queue, *rootp);
        while (queue.front) {
            p = dequeue(&queue);
            if (p->left == NULL) {
                p->left = new_node(val);
                break;
            } else {
                enqueue(&queue, p->left);
            }

            if (p->right == NULL) {
                p->right = new_node(val);
                break;
            } else {
                enqueue(&queue, p->right);
            }
        }
    }
}