static int index = 0;
static int buffer[8];
static Semaphore bufferWrite;
static Semaphore bufferNotFull;
static Semaphore bufferNotEmpty;

void init(void)
{
	bufferWrite = newSemaphore(1);
	bufferNotFull = newSemaphore(8);
	bufferNotEmpty = newSemaphore(0);
}

void Product(void)
{
	while (1) {
		wait(bufferNotFull);
		wait(bufferWrite);
		buffer[index] = rand();
		index++;
		signal(bufferWrite);
		signal(bufferNotEmpty);
	}
}

void Consumer()
{
	while (1) {
		wait(bufferNotEmpty);
		wait(bufferWrite);
		printf("%d\n", buffer[index]);
		index--;
		signal(bufferWrite);
		signal(bufferNotFull);
	}
}