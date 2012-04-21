struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* insert(struct node* head, int data);
//struct node* delete(struct node* head, int data);
void inorder(struct node* head);
