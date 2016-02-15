int NumOnesInBinary(unsigned int number)
{
	int numOnes = 0;
	while (number) {
		if (number & 1) {
			numOnes++;
		}
		number = number >> 1;
	}
	return numOnes;
}

int NumOnesInBinary(int number)
{
	int numOnes = 0;
	while (number) {
		number = number & (number - 1);
		numOnes++;
	}
	return numOnes;
}