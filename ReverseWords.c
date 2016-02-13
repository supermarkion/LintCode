// Reverse a words in C language
int Reverse(char str[])
{
	char *buffer;
	int tokenReadPos, wordReadPos, wordEnd, writePos = 0;

	/* Position of the last character is length - 1 */
	tokenReadPos = strlen(str) - 1;
	buffer = (char *) malloc(tokenReadPos + 2);
	if (!buffer) {
		return 0;	// ReverseWords failed
	}

	while (tokenReadPos >= 0) {
		if (str[tokenReadPos] == ' ') {
			/* Write character */
			buffer[writePos++] = str[tokenReadPos--];
		} else {
			/* Store position of end of word*/
			wordEnd = tokenReadPos;

			/* Scan to next non-word character */
			while (tokenReadPos >= 0 && str[tokenReadPos] != ' ') {
				tokenReadPos--;
			}

			/* tokenReadPos went past the start of the word */
			wordReadPos = tokenReadPos + 1;

			/* Copy the characters of the word */
			while (wordReadPos <= wordEnd) {
				buffer[writePos++] = str[wordReadPos++];
			}
		}
	}
	/* NUL terminate buffer and copy over str */
	buffer[writePos] = '\0';
	strcpy(str, buffer);

	free(buffer);

	return 1;
}

// or we can use another method to finish this task
void ReverseWords(char str[])
{
	int start = 0, end = 0, length;

	length = strlen(str);

	/* Reverse entire string */
	ReverseString(str, start, length - 1);

	while (end < length) {
		if (str[end] != ' ') {	/* Skip non-word characters */

			/* Save position of beginning of word */
			start = end;

			/* Scan to next non-word character */
			while (end < length && str[end] != ' ') {
				end++;
			}

			/* Back up to end of word */
			end--;

			/* REverse word */
			ReverseString(str, start, end);
		}
		end++;	/* Advance to next token */
	}
	return;
}

void ReverseString(char str[], int start, int end) {
	char temp;
	while (end > start) {
		/* Exchange characters */
		temp = str[start];
		str[strat] = str[end];
		str[end] = temp;

		/* Move indices towards middle */
		start++; end--;
	}
	return;
}