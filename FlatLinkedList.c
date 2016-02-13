/*
	Given a doubly linked list, and each node has a child pointer. The flat this data structure.
*/

typedef struct nodeT {
	struct nodeT *next;
	struct nodeT *prev;
	struct nodeT *child;
	int value;
} node;

void FlattenList(node *head, node **tail)
{
	node *curNode = head;
	while (curNode) {
		/* The current node has a child */
		if (curNode->child) {
			Append(curNode->child, tail);
		}
		curNode = curNode->next;
	}
}

/* Appends the child list to the end of the tail and updates
 * the tail.
 */
void Append(node *child, node **tail)
{
	node *curNode;

	/* Append the child child list to then end */
	(*tail)->next = child;
	child->prev = *tail;

	/* Find the new tail, which is the end of the child child
	 * list
	 */
	 for (curNode = child; curNode->next; curNode = curNode->next) {
	 	; /* Body intentionally empty */
	 }

	 /* Update the tail pointer now that curNode is the new 
	  * tail.
	  */
	 *tail = curNode;
}