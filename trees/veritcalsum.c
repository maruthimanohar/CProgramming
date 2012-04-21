#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct dll {
	int data;
	struct dll *next;
	struct dll *prev;
};

struct node *newNode(int data) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode ->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}
void verticalsum_util(struct node *root,struct dll **dlist, struct dll *nextorprev , int flag) {
	if(root == NULL)
		return ;
	if(*dlist == NULL) {
		*dlist = (struct dll*)malloc(sizeof(struct dll));
		(*dlist)->prev = NULL;
		(*dlist)->next = NULL;
		(*dlist)->data = root->data;
		if(flag == 0)
			(*dlist)->next = nextorprev;
		else if(flag == 1)
			(*dlist)->prev = nextorprev;
	} else
		(*dlist)->data = (*dlist)->data + root->data;

	verticalsum_util(root->left, &((*dlist)->prev), *dlist, 0);
	verticalsum_util(root->right, &((*dlist)->next), *dlist, 1);
}

struct dll *verticalsum(struct node *root) {
	struct dll *dlist = NULL;
	verticalsum_util(root,&dlist, NULL, 0);
	if(dlist == NULL)
		return NULL;
	while(dlist->prev != NULL) {
		dlist = dlist->prev;	
	}
	return dlist;
}

void main() {
	struct node *root;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	struct dll *sum = verticalsum(root);
	while(sum != NULL) {
		printf("%d,",sum->data);
		sum = sum->next;
	}
	printf("\n");
}
