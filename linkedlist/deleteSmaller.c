#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

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
int deleteSmaller(struct node **head) {
	if(*head == NULL)
		return 0;
	if((*head)->next == NULL)
		return (*head)->data;
	
	int max = deleteSmaller(&((*head)->next));
	if((*head)->data < max) {
		struct node* tmp = *head;
		*head = (*head)->next;
		free(tmp);
		return max;
	}
	return (*head)->data;
}
int segEvenOdd(struct node **head) {
	if(*head == NULL)
		return ;
	
	struct node *eventail, *oddtail,*cur = *head, evenHead , oddHead;
	evenHead.next = NULL;
	eventail = &(evenHead);
	oddHead.next = NULL;
	oddtail = &(oddHead);
	while(cur != NULL) {
		if((cur->data) % 2 == 0) {
			eventail->next = cur;

			eventail = eventail->next;
			cur = cur->next;
			eventail->next = NULL;
		} else {
			oddtail->next = cur;

			oddtail = oddtail->next;
			cur = cur->next;
			oddtail->next = NULL;
		}

	}
	if(evenHead.next != NULL ) {
		eventail->next = oddHead.next;
		//return evenHead.next;
		*head = evenHead.next;
	} else
		*head = oddHead.next;
}
void main()
{
	struct node *ll;
	push(&ll,3);
	push(&ll,2);
	push(&ll,6);
	push(&ll,5);
	push(&ll,11);
	push(&ll,10);
	push(&ll,15);
	push(&ll,12);
	print(ll);
	deleteSmaller(&ll);
	print(ll);
	segEvenOdd(&ll);
	print(ll);

}
