#include"linkedlist.h"

struct node *merge(struct node *list1, struct node *list2) {
	if(list1 == NULL)
		return list2;
	if(list2 == NULL)
		return list1;
	struct node *head, *prev;
	if(list1->data > list2->data) {
		head = list2;
		list2 = list2->next;
	}
	else {
		head = list1;
		list1 = list1->next;
	}
	prev = head;
	while(list1!= NULL && list2!= NULL) {
		if(list1->data < list2->data) {
			prev->next = list1;
			prev = list1;
			list1 = list1->next;
		} else {
			prev->next = list2;
			prev = list2;
			list2 = list2->next;
		}
	}
	if(list1)
		prev->next = list1;
	else
		prev->next = list2;	
	return head;
}
main() {
	struct node *list1 = NULL;
	push(&list1,8);
	push(&list1,6);
	push(&list1,4);
	push(&list1,2);

	struct node *list2 = NULL;
//	push(&list2,9);
	push(&list2,7);
	push(&list2,5);
	push(&list2,3);
	push(&list2,1);

	struct node *merged = merge(list1, list2);
	print(merged);

}
