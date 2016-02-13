// typical two pointer method in C language
element *FindMToLastElement()
{
	element *current, *mBehind;
	int i ;

	/* Advance current m elements from begining,
	 * checking for the end of the list.
	 */
	current = head;
	for (i = 0; i < m; i++) {
		if (current->next) {
			current = current->next;
		} else {
			return NULL;
		}
	}

	/* Start mBehind at beginning and advance pointers
	 * together until current hits last element
	 */
	 mBehind = head;
	 while (current->next) {
	 	current = current->next;
	 	mBehind = mBehind->next;
	 }

	 /* mBehind now points to the element we were
	  * searching for, so return it
	  */
	return mBehind;
}