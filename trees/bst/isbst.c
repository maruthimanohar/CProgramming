#include<stdio.h>
#include "bst.h"
int isBst_util(struct node *root, struct node **prev) {
	if(root == NULL)
		return 1;
	if(!isBst_util(root->left,prev))
		return 0;
	if((*prev) != NULL && (*prev)->data > root->data) {
		return 0;
	}
	*prev = root;
	return isBst_util(root->right, prev);
}
int isBst(struct node *root) {
	struct node *prev = NULL;
	return isBst_util(root, &prev);
}

void main() {
	struct node *root = createnode(4);
	root->left = createnode(2);
	root->right = createnode(5);
	root->left->left = createnode(1);
	root->left->right = createnode(3);

	if(isBst(root)) {
		printf("This is a BST.\n");
	} else {
		printf("This is not a BST.\n");
	}
}
