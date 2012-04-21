#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
	struct node *next;
};

struct node *createnode(int data) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;
	newNode->next = NULL;
	return newNode;
}

void populate_next_ptr_util(struct node *root, struct node **nextptr) {
	if(root == NULL)
		return;
	populate_next_ptr_util(root->right, nextptr);
	root->next = *nextptr;
	*nextptr = root;
	populate_next_ptr_util(root->left, nextptr);
}
void populate_next_ptr(struct node *root) {
	struct node *nextptr = NULL;
	populate_next_ptr_util(root, &nextptr);
}

void main() {
	struct node *root = createnode(4);
	root->left = createnode(2);
	root->right = createnode(5);
	root->left->left = createnode(1);
	root->left->right = createnode(3);

	populate_next_ptr(root);
	while(root->left != NULL)
		root = root->left;
	while(root !=NULL) {
		printf("%d,",root->data);
		root = root->next;
	}
	printf("\n");
}
