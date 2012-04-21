#include<stdio.h>
#include "tree.h"
int identicalTrees(struct tree *root1, struct tree *root2) {
	if(root1 == NULL && root2 == NULL)
		return 1;
	if(root1 && root2)
		return(root1->data == root2->data && identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right));
	return 0;
}
void main() {
	struct tree *root1 = newNode(1);
	struct tree *root2 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left = newNode(4);
	root1->left->right = newNode(5);
	
	root2->left = newNode(2);
	root2->right = newNode(3);
	root2->left->left = newNode(4);
	root2->left->right = newNode(5);
	if(identicalTrees(root1, root2))
		printf("Identical\n");
	else
		printf("Not Identical\n");
}
