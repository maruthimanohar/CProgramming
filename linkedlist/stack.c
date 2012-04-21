#include<stdio.h>
#include "stack.h"
#include<stdlib.h>

void push(struct stack *st, int data){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode -> data = data;
	newNode ->next = st->head;
	st->head = newNode;
	return;	
}

int pop(struct stack *st){
	if(st->head == NULL)
		return 0;
	struct node *head = st->head;
	st->head = head->next;
	int data = head->data;
	free(head);
	return data;
}

