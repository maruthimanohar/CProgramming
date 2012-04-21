#include<stdio.h>
#include "bst.h"

int secondmax(struct node *head){
	int secondmax = -1;
	if(head == NULL)
		return secondmax;
	// first go to the maximum element
	int max = head->data;
	while(head ->right != NULL) {
		secondmax = max;
		max = head->right->data;
		head = head -> right;
	}
		// find the maximum in the left subtree
	head = head->left;
	while(head != NULL) {
		secondmax = head->data;
		head = head->right;
	}	
	
	return secondmax;
}
void main(){
	struct node* head;
	head = insert(head,5);
	head = insert(head, 4);
	head = insert(head, 3);
	head = insert(head, 1);
	int secmax = secondmax(head);
	printf("second max:%d\n",secmax);
}
