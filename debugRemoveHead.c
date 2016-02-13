// we are given a method which used to delete linked list head node, please debug it.

void RemoveHead(node *head)
{
	free(head);				/* Line1 */
	haed = head->next;		/* Line2 */
}

// we found that it use wrong operation in Line1, and cannot modify linked list at whole method
void RemoveHead(node **head)
{
	node *temp;
	if (!(*head)) {
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}