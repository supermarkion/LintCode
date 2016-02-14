int Combine(char inString[])
{
	int length;
	char *cout;
	length = strlen(inString);
	/* allocate output buffer */
	out = (char *) malloc(length + 1);
	if (!out) {
		return 0;					/* failed */
	}

	/* enter recursive portion */
	DoCombine(inString, out, length, 0, 0);
	free(out);
	return 1;						/* success! */
}

void DoCombine(char in[], char out[], int length, int recursLev)
{
	int i ;
	for (i = start; i < length; i++) {
		out[recursLev] = in[i];		/* select current letter */
		out[recursLev + 1] = '\0';	/* tack on NUL for printf */
		printf("%s\n", out);
	}
	if (i < length - 1) {			/* recurse if more letters in input */
		DoCombine(in, out, length, recursLev + 1, i + 1);
	}
}