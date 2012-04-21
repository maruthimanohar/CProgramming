#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *createnode(int data) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}

int kthlargest_util(struct node *root, int *k) {
	if(root == NULL)
		return -1;
//	printf("k:%d\n",*k);

	int result = kthlargest_util(root->right, k);
	if(result != -1)
		return result;
	if(*k==1)
		return root->data;
	(*k)--;
	return kthlargest_util(root->left, k);
}

int kthlargest(struct node *root, int k) {
	int max = kthlargest_util(root, &k);
	return max;
}

void main() {
	struct node *root = createnode(4);
	root->left = createnode(2);
	root->right = createnode(5);
	root->left->left = createnode(1);
	root->left->right = createnode(3);
	int max = kthlargest(root, 5);
	printf("%d\n",max);
	max = kthlargest(root, 4);
	printf("%d\n",max);
	max = kthlargest(root, 3);
	printf("%d\n",max);
	max = kthlargest(root, 2);
	printf("%d\n",max);
	max = kthlargest(root, 1);
	printf("%d\n",max);
	/*populate_next_ptr(root);
	while(root->left != NULL)
		root = root->left;
	while(root !=NULL) {
		printf("%d,",root->data);
		root = root->next;
	}*/
	printf("\n");
}
