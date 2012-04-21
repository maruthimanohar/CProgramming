struct stnode {
	struct tree *tnode;
	struct stnode *next;
};

struct stack {
	struct stnode *head;
};

void push(struct stack* st, struct tree *tnode);
struct tree *pop(struct stack* st);
int isempty_stack(struct stack *st);
