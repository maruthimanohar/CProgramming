#include<stdio.h>
#include "tree.h"
#include<stdlib.h>

void printpaths_util(struct tree *root, int *path, int pathlength) {
	if(root == NULL)
		return;
	int i = 0;
	path[pathlength] = root->data;
	pathlength++;
	if(root->left == NULL && root->right == NULL) {
		for(i=0; i < pathlength ; i++)
			printf("%d,",path[i]);
		printf("\n");
	}
	printpaths_util(root->left, path, pathlength);
	printpaths_util(root->right, path, pathlength);
	return ;
}

void printpaths(struct tree* root) {
	int h = height(root);
	if(h == 0) {
		return ;
	}
	int *paths = (int*)malloc(sizeof(int) * h);
	printpaths_util(root, paths, 0);
}
main() {
	struct tree *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	printpaths(root);
}
