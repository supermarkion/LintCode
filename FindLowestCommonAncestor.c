/* Find two nodes in a BST lowest common ancestor */
int FindLowestCommonAncestor(node *root, int value1, int value2)
{
	node *curNode = root;

	while (1) {
		/* Go to the left child */
		if (curNode->value > value1 && curNode->value > value2) {
			curNode = curNode->left;
		}
		/* Go to the right child */
		else if (curNode->value < value1 && curNode->value < value2) {
			curNode = curNode->right;
		}
		/* Else, you've found the correct node */
		else {
			return curNode->value;
		}
	}
}