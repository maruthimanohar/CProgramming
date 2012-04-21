#include"bst.h"

main() {
	struct node *root;
	root = insert(root,4);
	root = insert(root,5);
	root = insert(root,6);
	root = insert(root,2);
	root = insert(root,1);
	root = insert(root,3);
	inorder(root);
	preorder(root);
}
