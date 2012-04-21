#include"linkedlist.h"

struct node *findnth(struct node *head, int n) {
	while(head->next != NULL && n > 0) {
		head = head->next;
		n--;
	}
	return head;
}

struct node *reversen_util(struct node *head, struct node **tail, int n) {
	if(head == NULL) 
		return NULL;
	struct node *curtail = findnth(head, n-1);
	printf("%d\n",curtail->data);
	struct node *ret = head;
	if(curtail->next) {
		ret = reversen_util(curtail->next, tail, n);
		(*tail)->next = head;
	}
	curtail->next = NULL;
	*tail = curtail;
	return ret;
	
}

struct node *reversen(struct node *head, int n) {
	if (n == 1 || head == NULL )
		return head;
	struct node *tail = NULL;
	return reversen_util(head, &tail, n);
}

main() {
	struct node *list = NULL;
	push(&list,1);
	push(&list,2);
	push(&list,3);
	push(&list,4);
	push(&list,5);
	push(&list,6);
	print(list);
	list = reversen(list,1);
	print(list);
}
