#include"linkedlist.h"
void swappair(struct node **head) {
	if(*head == NULL)
		return ;
	if((*head)->next == NULL)
		return ;

	struct node *curr = *head;
	*head = curr->next;
	struct node *prev = NULL;
	
	while(curr && curr->next) {
		if(prev)
			prev ->next = curr->next;
		prev = curr;
		curr = curr->next;
		prev->next = curr->next;
		curr->next = prev;
		
		curr = prev->next;		
	}
}
main() {
	struct node *head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	print(head);
	swappair(&head);
	print(head);
}
