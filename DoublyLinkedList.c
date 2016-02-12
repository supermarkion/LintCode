// In the double linked list, each node has two pointers, which is pre and next
typedef struct elementT {
	int data;
	struct elementT *pre;
	struct elementT *next;
} element;