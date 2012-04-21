#include<stdio.h>
#include "genericll.h"

struct node *merge(struct node *left, struct node *right) {
	if(left == NULL)
		return right;
	if(right == NULL)
		return left;
	struct node *head=NULL;
	if(left->data <= right->data) {
		head = left;
		head->next = merge(left->next, right);
	} else {
		head = right;
		head->next = merge(left, right->next);
	}
	return head;
}
struct node *merge_cnt(struct node *left, int lc, struct node *right, int rc) {
	struct node *head= NULL, *curr=NULL;
	if(lc > 0 && rc > 0) {
		if(left->data <= right->data) {
			head = left;
			left= left->next;
			lc--;
		} else {
			head = right;
			right = right->next;
			rc++;
		}
	} else if(rc == 0) {
		return left;
	} else if(lc == 0) {
		return right;
	}
	
	curr = head;
	while(1) {
		if(lc > 0 && rc > 0) {
			if(left->data <= right->data) {
				curr->next = left;
				left = left->next;
				lc--;
			} else {
				curr->next = right;
				right = right->next;
				rc--;
			}
		} else if (rc == 0) {
			curr->next = left;
		} else if(lc ==0) {
			curr->next = right;
		}
	}
	return head;
}
struct node* mergesort_util(struct node **head, int len) {
	printf("len = %d\n",len);
	if(len == 1)
		return *head;

	struct node *left = mergesort_util(head, len/2);
	*head = (*head)->next;
	if(*head != NULL) {
		printf("head : %d\n",(*head)->data);
	}
	struct node *right = mergesort_util(head, len - len/2);
	printf("merging %d , %d.\n",left->data,right->data);

	return merge_cnt(left, len/2, right, len - len/2);

}
void mergesort(struct node **head){
	int len = length(*head);
	if(len > 1) {
		struct node *tmp = mergesort_util(head, len);
		*head = tmp;
	}
}
main()
{
	struct node *ll = NULL;
	push(&ll,1);
	push(&ll,5);
	push(&ll,3);
	
	print(ll);
	
	struct node *list2 = NULL;
	push(&list2,2);
	push(&list2,6);
	push(&list2,4);
	printf("pushed all the elements.\n");
	print(list2);
	printf("printed all the elements.\n");
	struct node *tmp = merge(ll,list2);
	print(tmp);

	mergesort(&tmp);


}
