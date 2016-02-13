// write a cpp version on implement stack to compare difference
class Stack
{
public:
	Stack();
	~Stack();
	void Push(void *data);
	void *Pop();
protected:
	// Element strcut needed only internally
	typedef struct elementT {
		struct elementT *next;
		void *data;
	} element;

	element *firstEI;
};

Stack::Stack() {
	firstEI = NULL;
	return;
}

Stack::~Stack() {
	element *next;
	while (firstEI) {
		next = firstEI->next;
		delete firstEI;
		firstEI = next;
	}
	return return;
}

void Stack::Push(void *data) {
	// Allocation error will throw exception
	element *element = new element;
	element->data = data;
	element->next = firstEI;
	firstEI = element;
	return;
}

void *Stack::Pop() {
	element *popElement = firstEI;
	void *data;

	/* Assume StackError exception class is defined elsewhere */
	if (firstEI == NULL) {
		throw StackError(E_EMPTY);
	}

	data = firstEI->data;
	firstEI = firstEI->next;
	delete popElement;
	return data;
}