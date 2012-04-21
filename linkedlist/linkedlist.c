#include"linkedlist.h"
struct node *newNode(int data) {
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

void push(struct node **head, int data) {
	struct node *newnode = newNode(data);
	newnode->next = *head;
	*head = newnode;
}

void print(struct node *head) {
	while(head != NULL) {
		printf("%d,",head->data);
		head = head->next;
	}
	printf("\n");
}

int length(struct node *head) {
	int length = 0;
	while(head != NULL) {
		length++;
		head = head->next;
	}
	return length;
}
