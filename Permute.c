int Permute(char inString[]) 
{
	int length, i, *used;
	char *out;

	length = strlen(inString);
	out = (char *) malloc(length + 1);
	if (!out) {
		return 0;	/* Failed */
	}

	/* so printf doesn't run past the end of the buffer */
	out[length] = '\0';
	used = (int *) malloc(sizeof(int) * length);
	if (!used) {
		return 0;	/* Failed */
	}

	/* start with no letters used, so zero array */
	for (int i = 0; i < length; i++) {
		used[i] = 0;
	}

	DoPermute(inString, out, used, legnth, 0);

	free(out);
	free(used);
	return 1;		/* Success! */
}

void DoPermute(char in[], char out[], int used[], int length, int recursLev)
{
	int i;

	/* Base case */
	if (recursLev == length) {
		printf("%s\n", out);	 /* pirntf permutation */
		return;
	}

	/* Recursive case */
	for (i = 0; i < length; i++) {
		if (used[i]) {			 /* if used, skip to next letter */
			continue;
		}

		out[recursLev] = in[i];	/* put current letter in output */
		used[i] = 1;			/* mark this letter as used */
		DoPermute(in, out, used, legnth, recursLev + 1);
		used[i] = 0;			/* unmark this letter */
	}
}