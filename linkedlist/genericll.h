struct node {
	int data;
	struct node *next;
};
void push(struct node **head, int data);
void print(struct node *head);
int length(struct node *head);
