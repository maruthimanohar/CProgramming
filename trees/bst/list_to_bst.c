#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct list {
	int data;
	struct list *next;
};

struct node *newNode(int data) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct list *newListNode(int data) {
	struct list *newNode = (struct list*)malloc(sizeof(struct list));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

struct node *arr_to_bst_util(int *arr, int start, int end) {
	if(start > end )
		return NULL;
	int middle = (start+end) / 2;
	struct node *root = newNode(arr[middle]);
	root->left = arr_to_bst_util(arr, start, middle -1);
	root->right = arr_to_bst_util(arr, middle+1, end);
	return root;
}

struct node *arr_to_bst(int *arr, int size) {
	return arr_to_bst_util(arr, 0, size-1);
}
struct node *list_to_bst_util(struct list **head, int n) {
	if(*head == NULL || n <= 0)
		return NULL;
	struct node *left = list_to_bst_util(head, n/2);
	struct node *root = newNode((*head)->data);
	*head = (*head)->next;
	root->left = left;
	root->right = list_to_bst_util(head, n - (n/2 +1));
	return root;
}

int size(struct list *head) {
	int size = 0;
	while(head != NULL) {
		size++;
		head = head->next;
	}
	return size;	
}

struct node *list_to_bst(struct list *head) {
	int n = size(head);
	return list_to_bst_util(&head, n);
}

void inorder(struct node *root) {
	if(root == NULL)
		return ;
	inorder(root->left);
	printf("%d,",root->data);
	inorder(root->right);
}

void preorder(struct node *root) {
	if(root == NULL)
		return;
	printf("%d,",root->data);
	preorder(root->left);
	preorder(root->right);
}
void main() {
	struct list *head = newListNode(1);
	head->next = newListNode(2);
	head->next->next = newListNode(3);
	head->next->next->next = newListNode(4);
	struct node *root = list_to_bst(head);
	printf("Inorder traversal:");
	inorder(root);
	printf("\n");
	printf("Preorder traversal:");
	preorder(root);
	printf("\n");
	printf("constructing from array\n");
	int arr[4] = {1,2,3,4};
	int size = 4;
	struct node *root1 = arr_to_bst(arr,size);
	
	printf("Inorder traversal:");
	inorder(root1);
	printf("\n");
	printf("Preorder traversal:");
	preorder(root1);
	printf("\n");



}
