#include <stdio.h>
#include "genericll.h"
#include <stdlib.h>
void push(struct node **head, int data) {
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
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
	int count = 0;
	while(head != NULL) {
		count ++;
		head = head->next;
	}
	return count;
}

//void main() {
//}
