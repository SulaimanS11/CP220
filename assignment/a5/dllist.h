/**
 * -------------------------------------
 * @file  dllist.h
 * Assignment #5  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-02-10
 *
 * ------------------------------------- */

#ifndef DLL_H
#define DLL_H
/*
 * Define node structure NODE of a doubly linked list to hold a char data value. 
 */
typedef struct NODE {
    char data;
    struct NODE *prev;
    struct NODE *next;
} NODE;

/* 
 * Define a structure DLL to hold the length, start and end node addresses of a doubly linked list.
 */
typedef struct {
    int length;
    NODE *start;
    NODE *end;
} DLL;

/*
 * Create and return a new node using malloc() with passed data value and returns pointer of the node.
*/
NODE *new_node(char value);

/*
 * Insert a given node at the beginning the of a doubly linked list. 
 * @param DLL *dllp -  reference to input DLL variable 
 * @param NODE *np  -  reference of a NODE node to be inserted
*/
void dll_insert_start(DLL *dllp, NODE *np);

/*
 * Insert a node at the end of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable 
 * @param NODE *np  -  reference of a NODE node to be inserted
*/
void dll_insert_end(DLL *dllp, NODE *np);

/*
 * This deletes the first node of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable 
*/
void dll_delete_start(DLL *dllp);

/*
 * Delete the end node of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable  
*/
void dll_delete_end(DLL *dllp);

/*
 * Clean and free the nodes of a doubly linked list and reset start and length.
 * @param DLL *dllp -  reference to input DLL variable 
*/
void dll_clean(DLL *dllp);

#endif