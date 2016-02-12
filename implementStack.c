// first of all, stack is last-in-first-out

// for the struct, we should use void type as pointers
typedef struct elementT {
	struct elementT *next;
	void *data;
} element;

int CreateStack(element **stack)
{
	*stack = NULL;
	return 1;
}

// push method assign memory to new node, and check operation result
int Push(element **stack, void *data)
{
	element *elem;
	elem = (element *) malloc(sizeof(element));
	if (!elem) {
		return 0;
	}
	elem->data = data;
	elem->next = *stack;
	*stack = elem;
	return 1;
}

// pop method will check stack is empty or not, and return top value
int Pop(element **stack, void **data)
{
	element *elem;
	if (!(elem = *stack)) {
		return 0;
	}
	*data = elem->data;
	*stack = elem->next;
	free(elem);
	return 1;
}

// delete stack
int DeleteStack(element **stack)
{
	element *next;
	while (*stack) {
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	return 1;
}