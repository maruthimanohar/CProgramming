struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree *newNode(int data);
void preorder(struct tree *root);
void inorder(struct tree *root);
void postorder(struct tree *root);
int height(struct tree *root); 
