#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	int height;
	struct node *left;
	struct node *right;
	
};

struct node *newNode(int data){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->height = 0;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

int max(int a , int b) {
	if(a>b) 
		return a;
	return b;
}

int height (struct node* head) {
	if(head == NULL)
		return -1;
	return head->height;
}

struct node *crotate(struct node *x){
	printf("CRotatation at %d\n",x->data);
	struct node *y = x->left;
	struct node *tmp = y->right;
	y->right = x;
	x->left = tmp;
	x->height = max(height(x->left),height(x->right)) + 1;	
	y->height = max(height(y->left),height(y->right)) + 1;	

	return y;
}

struct node *acrotate(struct node *x) {
	printf("ACRotattion at %d\n",x->data);
	struct node *y = x->right;
	struct node *tmp = y->left;
	y->left = x;
	x->right = tmp;
	x->height = max(height(x->left),height(x->right)) + 1;	
	y->height = max(height(y->left),height(y->right)) + 1;	

	return y;
}

struct node *avlinsert(struct node* head, int data) {
	if(head == NULL ) {
		return newNode(data);		
	}
	if(data < head->data) 
		head->left = avlinsert(head->left, data);
	else 
		head->right = avlinsert(head->right, data);

	head->height = max(height(head->left) , height(head->right)) + 1;
	int heightDiff = height(head->left) - height(head->right);
//	printf("heightDiff : %d\n",heightDiff);
	if(heightDiff >= 2) {
		if(data < head->left->data)
			return crotate(head);
		else{ 
			head->left = acrotate(head->left);
			return crotate(head);
		}
	} else if(heightDiff <= -2) {
		if(data < head->right->data) {
			head->right = crotate(head->right);
			return acrotate(head);
		}
		else {
			return acrotate(head);
		}
	}
	return head;
}

void preorder(struct node *head) {
	if(head == NULL)
		return;
	//printf("%d at height %d,",head->data,head->height);
	printf("%d,",head->data);
	preorder(head->left);
	preorder(head->right);
}

void main() {
	struct node* head;
	printf("inserting 1\n");
	head = avlinsert(head ,1);
	preorder(head);
	printf("\n");
	printf("inserting 2\n");
	head = avlinsert(head ,2);
	preorder(head);
	printf("\n");
	printf("inserting 3\n");
	head = avlinsert(head ,3);
	preorder(head);
	printf("\n");
	printf("inserting 4\n");
	head = avlinsert(head, 4);
	preorder(head);
	printf("\n");
	printf("inserting 5\n");
	head = avlinsert(head, 5);
	preorder(head);
	printf("\n");
	printf("inserting 6\n");
	head = avlinsert(head, 6);
	preorder(head);
	printf("\n");
	printf("inserting 7\n");
	head = avlinsert(head, 7);
	preorder(head);
	printf("\n");

	printf("inserting 16\n");
	head = avlinsert(head, 16);
	preorder(head);
	printf("\n");

	printf("inserting 15\n");
	head = avlinsert(head, 15);
	preorder(head);
	printf("\n");
	printf("inserting 14\n");
	head = avlinsert(head, 14);
	preorder(head);
	printf("\n");
	printf("inserting 13\n");
	head = avlinsert(head, 13);
	preorder(head);
	printf("\n");
	printf("inserting 12\n");
	head = avlinsert(head, 12);
	preorder(head);
	printf("\n");
	printf("inserting 11\n");
	head = avlinsert(head, 11);
	preorder(head);
	printf("\n");
	printf("inserting 10\n");
	head = avlinsert(head, 10);
	preorder(head);
	printf("\n");
	printf("inserting 9\n");
	head = avlinsert(head, 9);
	preorder(head);
	printf("\n");
	printf("inserting 8\n");
	head = avlinsert(head, 8);
	preorder(head);
	printf("\n");

}
