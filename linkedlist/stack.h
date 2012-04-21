struct stack {
	struct node *head;
};

void push(struct stack *st, int data);
struct node *pop(struct stack *st);
