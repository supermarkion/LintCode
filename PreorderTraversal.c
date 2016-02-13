// perform preorder traversal in the binary search tree
void PreorderTraversal(node *root)
{
	if (root) {
		printf("%d\n", root->value);
	} else {
		return;
	}
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}

// if we do not use recursion
void PreorderTraversal(node *root) {
	element *theStack;
	void *data;
	node *curNode;

	CreateStack(&theStack);
	Push(&theStack, root);

	while (Pop(&theStack, &data)) {
		curNode = (node *) data;
		if (curNode) {
			printf("%d\n", curNode->value);
			Push(&theStack, curNode->right);
			Push(&theStack, curNode->left);
		}
	}
	DeleteStack(&theStack);
}