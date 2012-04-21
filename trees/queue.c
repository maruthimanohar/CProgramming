#include<stdio.h>
#include "queue.h"
#include<stdlib.h>
#include "tree.h"
int isempty(struct queue *q) {
	if(q->head == NULL)
		return 1;
	return 0;
}
void enqueue(struct queue* q, struct tree *tnode){
	struct qnode *node = (struct qnode*)malloc(sizeof(struct qnode));
	node->tnode = tnode;
	node->next = NULL;
	node->prev = NULL;
	if(isempty(q)) {
		q->head = node;
		q->tail = node;
	} else {
		node->prev = q->tail;
		q->tail->next = node;
		q->tail = node;
	}
}

struct tree *dequeue(struct queue* q) {
	if(isempty(q)) {
		return NULL;
	}
	struct qnode *head = q->head;
	q->head = q->head->next;
	if(q->head == NULL)
		q->tail = NULL;
	struct tree *tnode = head->tnode;
	free(head);
	return tnode;
}
