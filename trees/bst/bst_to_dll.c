#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode ->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

struct node *append(struct node *a, struct node *b) {
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	a->left->right = b;
	b->left->right = a;
	struct node *tmp = a->left;
	a->left = b->left;
	b->left = tmp;
	return a;
}

struct node *bst_to_dll(struct node *root) {
	if(root == NULL)
		return NULL;
	struct node *left_dll = bst_to_dll(root->left);
	struct node *right_dll = bst_to_dll(root->right);
	root->left = root;
	root->right = root;
	left_dll = append(left_dll, root);
	return append(left_dll, right_dll);
}

void main() {

	struct node *root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(8);

	struct node *result = bst_to_dll(root);
	int a = result->data;
	printf("%d,",result->data);
	result = result->right;
	while( result && result->data != a) {
		printf("%d,",result->data);
		result = result->right;
	}
	printf("\n");
}
