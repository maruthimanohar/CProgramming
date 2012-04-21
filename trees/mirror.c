#include<stdio.h>
#include "tree.h"
#include<stdlib.h>
void mirror(struct tree *root) {
	if(root == NULL) 
		return ;

	mirror(root->left);
	mirror(root->right);
	struct tree *tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	return ;
}
void main() {
	struct tree *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	printf("Printing Preorder\n");
	preorder(root);
	printf("\n");
	mirror(root);
	printf("Printing Preorder after mirroring\n");
	preorder(root);
	printf("\n");
	
}
