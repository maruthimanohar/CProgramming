#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

struct tree *newNode(int data) {
	struct tree* newNode = (struct tree *)malloc(sizeof(struct tree));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

int max(int a, int b) {
	return a > b ? a:b;
}
int height(struct tree *root) {
	if(root == NULL)
		return 0;
	return max(height(root->left), height(root->right)) + 1;
}

