#include<stdio.h>
#include "queue.h"
#include<stdlib.h>
#include "tree.h"
#include "stack.h"

void push(struct stack* st, struct tree *tnode){
	struct stnode *node = (struct stnode*)malloc(sizeof(struct stnode));
	node->tnode = tnode;
	node->next = st->head;
	st->head = node;
}

struct tree *pop(struct stack* st) {
	if(st->head == NULL) {
		return NULL;
	}
	struct stnode *stnode = st->head;
	struct tree *tnode = stnode->tnode;
	st->head = stnode ->next;
	free(stnode);
	return tnode;
}

int isempty_stack(struct stack *st) {
	if(st->head == NULL)
		return 1;
	return 0;
}
