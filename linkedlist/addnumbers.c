#include<stdio.h>
#include"genericll.h"
#include<stdlib.h>
struct node *__add(struct node *l1, struct node *l2, int len1, int len2, int *carry) {
	
	int sum =0;
	struct node *rest = NULL;
		
	if(len1 > len2) {
		rest = __add(l1->next, l2, len1-1 , len2, carry);
		sum =  l1->data + *carry;
	} else {
		if(l1 == NULL) {
			*carry = 0;
			return NULL;
		}
		rest = __add(l1->next, l2->next, len1-1, len2-1, carry);
		sum = l1->data + l2->data + *carry;
	}
		printf("%d\n",sum);
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = sum %10;
	newnode->next = rest;
	*carry = sum/10;
	return newnode;
}
struct node *add(struct node *l1, struct node *l2) {
	if(l1 == NULL)
		return l2;
	if(l2 == NULL)
		return l1;
	int len1 = length(l1);
	int len2 = length(l2);
	int carry =0;
	struct node *res = NULL;
	if(len1 > len2)
		res = __add(l1, l2, len1, len2, &carry);
	else
		res = __add(l2, l1, len2, len1, &carry);
	while(carry > 0) {
			struct node *newnode = (struct node *)malloc(sizeof(struct node*));
			newnode ->data = carry %10;
			newnode->next = res;
			res = newnode;
			carry = carry / 10;
	}

	return res;
}
void main() {
	struct node *l1= NULL, *l2=NULL;
	push(&l1, 3);
	push(&l1, 9);
	push(&l2, 7);
	struct node *result = add(l1,l2);
	print(result);
}
