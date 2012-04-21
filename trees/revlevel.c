#include<stdio.h>
#include"tree.h"
#include"stack.h"
#include"queue.h"
#include<stdlib.h>
populate_stack(struct tree *root, struct stack *st){
	
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->head = NULL;
	enqueue(q, root);
	struct tree *cur = dequeue(q);
	while(cur != NULL) {
		push(st, cur);
		if(cur->right)
			enqueue(q, cur->right);
		if(cur->left)
			enqueue(q, cur->left);
		cur = dequeue(q);
	}
}
print_revlev(struct tree *root) {

	struct stack *st = (struct stack*)malloc(sizeof(struct stack));
	st->head = NULL;
	populate_stack(root, st);
	struct tree *cur = pop(st);
	while(cur!= NULL) {
		printf("%d,",cur->data);
		cur = pop(st);
	}
	printf("\n");
	 
}

main() {
//	struct tree *root = NULL;
	struct tree *root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(9);
	root->left->right->left = newNode(10);
	root->right->right->left = newNode(11);
	
	print_revlev(root);	
}
