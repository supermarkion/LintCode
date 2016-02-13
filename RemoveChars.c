void RemoveChars(char str[], char remove[])
{
	int src, dst, removeArray[256];

	/* Zero all elements in array */
	for (src = 0; src < 256; src++) {
		removeArray[src] = 0;
	}

	/* Set true for chars to be removed */
	src = 0;
	while (remove[src]) {
		removeArray[remove[src]] = 1;
		src++;
	}

	/* Copy char unless it must be removed */
	src = dst = 0;
	do {
		if (!removeArray[str[src]]) {
			str[dst++] = str[src];
		}
	} while {str[src++]}
}