// Use two pointers method to find a loop

/* Takes a pointer to the head of a linked list and determines if 
 * the list ends in a cycle or is NULL terminated
 */

 int DetermineTermination(node *head)
 {
 	node *fast, *slow;
 	fast = slow = head;
 	while(1) {
 		if (!fast || !fast->next) {
 			return 0;
 		} else if (fast == slow || fast->next == slow) {
 			return 1;
 		} else {
 			slow = slow->next;
 			fast = fast->next->next;
 		}
 	}
 }