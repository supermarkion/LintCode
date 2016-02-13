/*
	Given a linked list, and also given global node as head and tail node. Please write delete and insertAfter methodes.

*/

int Delete(element *elem)
{
	element *curPos = head;

	if (!elem) {
		return 0;
	}

	if (elem == head) {
		head = elem->next;
		free(elem);
		/* special case for 1 element list */
		if (!head) {
			tail = NULL;
		}
		return 1;
	}

	while (curPos) {
		if (curPos->next == elem) {
			curPos->next = elem->next;
			free(elem);
			if (curPos->next == NULL) {
				tail = curPos;
			}
			return 1;
		}
		curPos = curPos->next;
	}

	return 0;
}

int insertAfter (element *elem, int data)
{
	element *newElem, *curPos = head;

	newElem = (element *) malloc(sizeof(element));
	if (!newElem) {
		return 0;
	}
	newElem->data = data;

	/* Insert at begining of list */
	if (!elem) {
		newElem->next = head;
		head = newElem;

		/* Special case for empty list */
		if (!tail) {
			tail = newElem;
		}
		return 1;
	}

	while (curPos) {
		if (curPos == elem) {
			newElem->next = curPos->next;
			curPos->next = newElem;

			/* Speical case for inserting at end of list */
			if (!(newElem->next)) {
				tail = newElem;
			}
			return 1;
		}
		curPos = curPOs->next;
	}

	/* Insert position not found; free element and return failure */
	free(newELem);
	return 0;
}