#include<stdio.h>
#include "tree.h"

int findIndex(int *arr, int start, int end, int data) {
	int i;
	for(i=start;i<=end;i++){
		if(arr[i] == data)
			return i;
	}
}

struct tree *constructTree_in_pre(int *inorder, int *preorder, int instart, int inend, int *prestart) {
	if(instart > inend) {
		return NULL;
	}
	struct tree *root = newNode(preorder[*prestart]);
	(*prestart)++;
	if(instart == inend )
		return root;
	int inmatch = findIndex(inorder, instart, inend, root->data);
	root->left = constructTree_in_pre(inorder, preorder, instart, inmatch-1,prestart);
	root->right = constructTree_in_pre(inorder, preorder, inmatch+1, inend, prestart);
	return root;
}

struct tree *constructTree_in_post(int *inorder, int *postorder, int instart, int inend, int *postend) {
	
	if(instart > inend) {
		return NULL;
	}
	struct tree *root = newNode(postorder[*postend]);
	(*postend)--;
	if(instart == inend) 
		return root;
	int inmatch = findIndex(inorder, instart, inend, root->data);
	
	root->right = constructTree_in_post(inorder, postorder, inmatch+1, inend, postend);
	root->left = constructTree_in_post(inorder, postorder, instart, inmatch-1, postend);
	return root;

}

void main(){
	int inord[] = {1,2,3,4,5,6,7,8,9};
	int preord[] = {5,3,2,1,4,8,6,7,9};
	int postord[] = {1,2,4,3,7,6,9,8,5};
	int prestart = 0;
	int postend = 8;
	struct tree *root = constructTree_in_pre(inord, preord, 0, 8, &prestart);
	//struct tree *root = constructTree_in_post(inord, postord, 0, 8, &postend);
	printf("Inorder:");
	inorder(root);
	printf("\nPreorder:");
	preorder(root);
	printf("\nPostorder:");
	postorder(root);
	printf("\n");
}
