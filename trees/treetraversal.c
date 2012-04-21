#include<stdio.h>
#include "tree.h"
#include "queue.h"
#include "stack.h"
#include<stdlib.h>
void preorder(struct tree *root) {
	if(root == NULL)
		return ;
	printf("%d,",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct tree *root) {
	if(root == NULL)
		return ;
	inorder(root->left);
	printf("%d,",root->data);
	inorder(root->right);
}

void postorder(struct tree *root) {
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);

	printf("%d,",root->data);
}

void levelorder(struct tree* root) {
	if(root == NULL)
		return;
	struct queue *q = (struct queue *)malloc(sizeof(struct queue));
	enqueue(q, root);
	struct tree *next = dequeue(q);
	while(next) {
		printf("%d,",next->data);
		if(next->left)
			enqueue(q, next->left);
		if(next->right)
			enqueue(q, next->right);
		next = dequeue(q);
	}
	printf("\n");
}

void spirallevelorder(struct tree *root) {
	if(root== NULL)
		return ;
	int level = 1;
	struct stack *st1 = (struct stack *)malloc(sizeof(struct stack));
	st1->head = NULL;
	struct stack *st2 = (struct stack *)malloc(sizeof(struct stack));
	st2->head = NULL;
	push(st1, root);
	while(!isempty_stack(st1) || !isempty_stack(st2)) {
		if(level %2 == 1) {
			while(!isempty_stack(st1)) {
				struct tree *next = pop(st1);
				printf("%d,",next->data);
				if(next->left) 
					push(st2,next->left);
				if(next->right)
					push(st2, next->right);
			}
		} else {
			while(!isempty_stack(st2)) {
				struct tree *next = pop(st2);
				printf("%d,",next->data);
				if(next ->right)
					push(st1, next->right);
				if(next->left)
					push(st1, next->left);
			}
		}
		level++;
	}
	printf("\n");
}
void main() {
	struct tree *root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(9);
	root->left->right->left = newNode(10);
	root->right->right->left = newNode(11);
	
	printf("Printing Preorder.\n");
	preorder(root);
	printf("\nPrinting inorder.\n");
	inorder(root);
	printf("\nPrinting Postorder.\n");
	postorder(root);
	printf("\nPrinting LevelOrder.\n");
	levelorder(root);
	printf("\n Printing spiral level order.\n");
	spirallevelorder(root);
}
