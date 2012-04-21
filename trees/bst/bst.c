#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

struct node* createnode(int data) {
	struct node* newnode = (struct node*) malloc(sizeof(struct node*));
	newnode -> data = data; 
	newnode -> left = NULL;
	newnode -> right = NULL;
	return newnode;
}

struct node* insert(struct node* head, int data) {
	if(head == NULL) {
		return createnode(data);
	}
	if(data < head->data) {
		head->left = insert(head->left, data);
	} else {
		head->right = insert(head->right, data);
	}
	return head;
}

int findmax(struct node *root) {
	if(root == NULL)
		return -1;
	while(root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

struct node* delete(struct node *head, int data) {
	if(head == NULL) {
		return head;
	}
	if(data < head->data) {
		head->left = delete(head->left, data);
	} else if(data > head->data){
		head->right = delete(head->right, data);
	} else {
		struct node *tmp;
		if(head->left && head->right) {
			int max = findmax(head->left);
			head->data = max;
			head->left = delete(head->left, max);
		} else if(head->left) {
			tmp = head;
			head = head->left;
		} else {
			tmp = head;
			head = head->right;
		}
		if(tmp) {
			free(tmp);
		}
	}
	return head;
}

void inorder(struct node* head) {
	if(head == NULL)
		return ;
	inorder(head->left);
	printf("%d,",head->data);
	inorder(head->right);
}

void postorder(struct node *root) {
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d,",root->data);
}

void preorder(struct node *root) {
	if(root == NULL) 
		return ;
	printf("%d,",root->data);
	preorder(root->left);
	preorder(root->right);
}
