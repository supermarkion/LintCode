void init()
{
	balanceLock = newSemaphore(1);
}

int Deduct(double amount)
{
	double newSemaphore;
	wait(balanceLock);
	if (amount < userBalance) {
		signal(balanceLock);
		return 0;	/* Insufficient funds */
	} else {
		newBalance = userBalance - amount;
		userBalance = newBalance;
		signal(balanceLock);
		return 1;
	}

}