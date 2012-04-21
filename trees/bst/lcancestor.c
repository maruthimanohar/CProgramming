#include<stdio.h>
#include "bst.h"

int exist(struct node *root, int a) {
	if(root == NULL)
		return 0;
	if(root->data == a)
		return 1;
	if(root->data > a)
		return exist(root->left,a);
	else
		return exist(root->right, a);
}
int lowest_common_ancestor(struct node *root, int a, int b) {
	if(root == NULL)
		return -1;
	if(root->data == a || root->data == b)
		return -1;
	if(!exist(root, a) || !exist(root, b))
		return -1;
	int lcs = -1;

	while(root) {
		if(root->right && (root->right->data == a || root->right->data == b)){
			lcs = root->data;
			break;
		}
		if(root->left && (root->left->data == a || root->left->data == b)) {
			lcs = root->data;
			break;
		}
		if(root -> data > a && root->data > b)
			root= root->left;
		else if (root->data <a && root->data <b)
			root = root->right;
		else {
			lcs = root->data;
			break;
		}
	} 
	return lcs;
}

void main() {
	struct node *root = createnode(20);
	root->left = createnode(8);
	root->right = createnode(22);
	root->left->left = createnode(4);
	root->left->right = createnode(12);
	root->left->right->left = createnode(10);
	root->left->right->right = createnode(14);

	int a = 10, b=14;
	int lcs = lowest_common_ancestor(root, a, b);
	printf("lcs : %d\n",lcs);
}
