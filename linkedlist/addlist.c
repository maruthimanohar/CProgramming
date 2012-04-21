#include"linkedlist.h"
struct node *__add(struct node *list1, struct node *list2, int l1, int l2, int *carry) {
	int sum = 0;
	struct node *rest = NULL;
	
	if(l1 == 0)
		return NULL;

	if(l1 > l2) {
		rest = __add(list1->next, list2, l1-1, l2, carry);
		sum = list1->data + *carry;

	} else {
		rest = __add(list1->next, list2->next, l1-1, l2-1, carry);
		sum = list1->data + list2->data + *carry;
	}
	
	struct node *head = newNode(0);
	head->next = rest;
	head->data = sum % 10;
	*carry = sum /10;
	return head;
	
}
struct node *add(struct node *list1, struct node *list2) {
	int l1, l2;
	l1 = length(list1);
	l2 = length(list2);
	int carry = 0;
	struct node *result = NULL;
	if(l1 >= l2)
		result = __add(list1, list2, l1, l2, &carry);
	else
		result =  __add(list2, list1, l2, l1, &carry);
	if(carry > 0) {
		struct node *node = newNode(carry);
		node->next = result;
		result = node;
	}
	return result;
}

main() {
	struct node *list1= NULL, *list2=NULL;
	push(&list1, 5);
	push(&list1, 7);
	push(&list1, 9);
	print(list1);
	push(&list2, 3);
	push(&list2, 4);
	print(list2);
	struct node *result = add(list1, list2);
	print(result);
}
