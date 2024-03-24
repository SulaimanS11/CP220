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

#include "stddef.h"
#include <stdio.h>
#include "common_queue_stack.h"

NODE *new_node(int data, int type) {
	NODE *np = (NODE *) malloc(sizeof(NODE));
	np->data = data;
	np->type = type;
	np->next = NULL;
	return np;
}

void clean(NODE **npp) {
	NODE *tmp, *np = *npp;
	while (np) {
		tmp = np;
		np = np->next;
		free(tmp);
	}
	*npp = NULL;
}

void display(NODE *np) {
	while (np) {
		if (np->type == 0)
			printf("%d", np->data);
		else
			printf("%c", np->data);

		np = np->next;

		if (np)
			printf(" ");
	}
}

int get_type(char c) {
	int t = -1;
	if (c >= '0' && c <= '9')
		t = 0;
	else if (c == '+' || c == '-' || c == '*' || c == '/')
		t = 1;
	else if (c == '(')
		t = 2;
	else if (c == ')')
		t = 3;
	else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		t = 4;
	else if (c == ' ')
	    t = 5;

	return t;
}

int get_priority(char op) {
	int r = -1;
	if (op == '/' || op == '*' || op == '%')
		r = 1;
	else if (op == '+' || op == '-')
		r = 0;

	return r;
}

void enqueue(QUEUE *qp, NODE *np) {
    if (qp->rear == NULL) { 
        qp->front = qp->rear = np; 
    } else {
        qp->rear->next = np; 
        qp->rear = np; 
    }
    qp->length++; 
    qp->rear->next = NULL; 
}

NODE *dequeue(QUEUE *qp) {
    if (qp->front == NULL) { 
        return NULL; 
    }
    NODE *temp = qp->front; 
    qp->front = qp->front->next; // Update the front to the next node
    if (qp->front == NULL) {
        qp->rear = NULL; 
    }
    qp->length--;
    temp->next = NULL; 
    return temp; // Return the dequeued node
}

void queue_clean(QUEUE *qp) {
    while(dequeue(qp) != NULL); 
}



void push(STACK *sp, NODE *np) {
    np->next = sp->top; // Point new node to the current top
    sp->top = np; 
    sp->length++; 
}

NODE *pop(STACK *sp) {
    if (sp->top == NULL) return NULL; 

    NODE *temp = sp->top; 
    sp->top = sp->top->next; 
    sp->length--; 

    temp->next = NULL; 
    return temp; // Return the popped node
}

void clean_stack(STACK *sp) {
  clean(&(sp->top));
  sp->top = NULL;
  sp->length=0;
}