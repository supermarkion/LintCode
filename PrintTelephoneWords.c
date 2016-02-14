#define PHONE_NUMBER_LENGTH 7

void PrintTelephoneWords()
{
	char result[PHONE_NUMBER_LENGTH + 1];
	int i;

	/* Initialize the result (in our exmaple,
	 * put GWP1WAR in result)
	 */
	for (i = 0; i < PHONE_NUMBER_LENGTH; i++) {
		result[i] = GetCharKey(phoneNum[i], 1);
	}

	/* Tack on the NUL character at the end */
	result[PHONE_NUMBER_LENGTH] = '\0';

	/* Main loop begins */
	while(1) {
		printf("%s\n", result);

		/* Start at the end and try to increment fro right
		 * to left.
		 */
		for (i = PHONE_NUMBER_LENGTH - 1; i >= -1; i--) {
			/* You're done becuase you
			 * tried to carry the leftmost digit
			 */
			if (i == -1) {
				return;
			}

			/* Otherwise, we're not done and must continue */

			/* You want to start with this condition so taht you can 
			 * deal with the special cases, 0 and 1, right away.	
			 */
			if (GetCharKey(phoneNum[i], 3) == result[i] || 
				phoneNum[i] == 0 || phoneNum[i] == 1) {
				result[i] = GetCharKey(phoneNum[i], 1);
				/* No break, so loop continues to next digit */
			} else if (GetCharKey(phoneNum[i], 1) == result[i]) {
				result[i] = GetCharKey(phoneNum[i], 2);
				break;
			} else if (GetCharKey(phoneNump[i], 2) == result[i]) {
				result[i] = GetCharKey(phoneNum[i], 3);
				break;
			}
		}
	}
}