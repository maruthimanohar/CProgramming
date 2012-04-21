#include<stdio.h>
#include "tree.h"

/*
int diameter_util(struct tree *root, int* diameter) {
	if(root == NULL) {
		return -1;
	}
	int lheight = diameter_util(root->left, diameter);
	int rheight = diameter_util(root->right, diameter);
	if(*diameter < (lheight + rheight + 2) )	
		*diameter = lheight + rheight + 2;
	return max(lheight, rheight) + 1;	
}
int diameter(struct tree *root) {
	int d =0;
	diameter_util(root, &d);
	return d;
}
*/
int diameter_util(struct tree *root, int* height) {
	if(root == NULL) {
		*height = 0;
		return 0;
	}
	int lheight = 0, rheight = 0;
	int ldiameter = diameter_util(root->left, &lheight);
	int rdiameter = diameter_util(root->right, &rheight);
	*height = max(lheight,rheight) + 1;
	return max(lheight+rheight+1, max(ldiameter,rdiameter));

}
int diameter(struct tree *root) {
	int h =0;
	return diameter_util(root, &h);
}


void main() {
	struct tree *root = newNode(2);
	root->left = newNode(3);
	root->right = newNode(4);
	root->left->left = newNode(5);
	root->left->right = newNode(6);
	root->left->left->left = newNode(7);
	root->left->right->right = newNode(8);
	root->left->left->left->right = newNode(9);
	root->left->right->right->left = newNode(10);
	int d = diameter(root);
	printf("diameter : %d\n",d);
}
