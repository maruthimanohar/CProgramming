struct qnode {
	struct tree *tnode;
	struct qnode *next;
	struct qnode *prev;
};

struct queue {
	struct qnode *head;
	struct qnode *tail;
};

void enqueue(struct queue* q, struct tree *tnode);
struct tree *dequeue(struct queue* q);
