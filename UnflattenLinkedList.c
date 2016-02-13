/* This is a wrapper function that also updates the tail pointer. */
void Unflatten(node *start, node **tail)
{
	node *curNode;
	ExploreAndSeparate(start);

	/* Update the tail pointer */
	for (curNode = start; curNode->next; curNode = curNode->next) {
		; /* body intentionally empty */
	}
	*tail = curNode;
}

/* This is the function that actually does the recursion and 
 * the separation
 */
 void ExploreAndSeparate(node *childListStart)
 {
 	node *curNode = childListStart;

 	while (curNode) {
 		if (curNode->child) {
 			/* terminates the child list before the child */
 			curNode->child->prev->next = NULL;
 			/* starts the child list beginning with the child */
 			curNode->child->prev = NULL;
 			ExploreAndSeparate(curNode->child);
 		}
 		curNOde = curNode->next;
 	}
 }