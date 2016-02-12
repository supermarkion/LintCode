// the strcut of each element is following
typedef struct elementT {
	int data;
	struct elementT *next;
} element;

// In the C lanuage, we should free node memory, and this is most important difference between other language

// first of all, each linked list problem start with head element, we should use dummy node
int Insert(element **head)
{
	element *newBlem;
	newBlem = {element *} malloc(sizeof(element));
	if (!newBlem) {
		return 0;
	}

	newBlem -> next = *head;

	/* *ehad gives the calling function's head pointer, so
	* the changee is not lost when this function returns
	*/
	*head = newBlem;
	return 1;
}

// another method is to find node by loop
element *FindSixe(element *elem)
{
	while (elem) {
		if (elem->data == 6) {
			/* Found elem->data == 6 */
			return elem;
		}
		elem = elem->next;
	}
	/* No elem-> data == 6 exists*/
	return NULL;
}

// Insert and delete is also an important method in Linked List
int DeleteElement(element **head, element *deleteMe)
{
	element *elem = *head;

	if (deleteMe == *head) { /* special case for head */
		*head = elem->next;
		free(deleteMe);
		return 1;
	}

	while (elem) {
		if (elem->next == deleteMe) {
			/* elem is element preceding deleteMe */
			elem->next = deleteMe->next;
			free(deleteMe);
			return 1;
		}
		elem = elem->next;
	}
	/* deleteMe not found */
	return 0;
}

// if you want to delete all List
void DeleteList(element *head)
{
	element *next, *deleteMe;
	deleteMe = head;
	while (deleteMe) {
		next = deleteMe->next;
		free(deleteMe);
		deleteMe = next;
	}
}