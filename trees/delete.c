#include<stdio.h>
#include "tree.h"
#include<stdlib.h>
void delete(struct tree *root) {
	if(root == NULL) 
		return ;
	delete(root->left);
	delete(root->right);
	printf("Deleting the node %d\n",root->data);
	free(root);
	return ;
}
void main() {
	struct tree *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	delete(root);
	printf("deleted the tree.\n");	
}
