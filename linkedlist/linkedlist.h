#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};

struct node *newNode(int data);
void push(struct node **head, int data);
void print(struct node *head);
int length(struct node *head);
