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

struct node *dll_to_bst_util(struct node **head, int n) {
	if(head == NULL || n <=0 )
		return NULL;
	struct node *left = dll_to_bst_util(head, n/2);
	struct node *root = *head;
	root->left = left;
	*head = (*head)->right;
	root->right = dll_to_bst_util(head, n - (n/2 + 1));
	return root;
}

int size(struct node *head) {
	int size = 0;
	while(head != NULL) {
		head = head->right;
		size++;
	}
	return size;
}
struct node *dll_to_bst(struct node *head) {
	int s = size(head);
	return dll_to_bst_util(&head, s);
}

void print_inorder(struct node *root) {
	if(root == NULL)
		return;
	print_inorder(root->left);
	printf("%d,",root->data);
	print_inorder(root->right);
}

void print_preorder(struct node *root) {
	if(root == NULL)
		return;
	printf("%d,",root->data);
	print_preorder(root->left);
	print_preorder(root->right);
}
void main() {

	struct node *root = newNode(1);
	root->right = newNode(2);
	root->right->right = newNode(3);
	root->right->right->right = newNode(4);
	root->right->right->right->right = newNode(5);
	root->right->right->right->right->right = newNode(6);

	struct node *result = dll_to_bst(root);
	print_inorder(result);
	printf("\n");
	print_preorder(result);
	printf("\n");
}
