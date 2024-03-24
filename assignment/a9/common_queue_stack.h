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

 
typedef struct node {
	int data;
	int type;
	struct node *next;
} NODE;

NODE *new_node(int data, int type);
void clean(NODE **npp);
void display(NODE *np);
int get_type(char c);
int get_priority(char op);



typedef struct queue {
  int length;  
  NODE *front;
  NODE *rear;
} QUEUE;    

/* 
 * Enqueue a node into a queue
 * @param *qp - pointer to the queue 
 * @param NODE *np - pointer to the node.
*/
void enqueue(QUEUE *qp, NODE *np);  

/* 
 * Dequeue and return the pointer of the removed node. 
 * @param *qp - pointer to the queue
 * @return - the reference of the removed node, and set it's next to NULL 
*/
NODE *dequeue(QUEUE *qp);

/* 
 * Clean the linked list queue
*/
void queue_clean(QUEUE *qp);

typedef struct stack {
  int length;  
  NODE *top;
} STACK;

/* 
 * Push a node into a linked list stack
 * @param STACK *sp - pointer to the stack 
 * @param NODE *np - pointer to the node.
*/ 
void push(STACK *sp, NODE *np);

/* 
 * Pop and return the pointer of the removed top node
 * @param STACK *sp - pointer to the stack
 * @return - the reference of the removed node and set it's next to NULL  
*/ 
NODE *pop(STACK *sp); 

/*
 * clean the linked list stack
 */ 
void clean_stack(STACK *sp);
