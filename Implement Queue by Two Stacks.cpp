/*
    As the title described, you should only use two stacks to implement a queue's actions. The queue should support 
    push(element), pop() and top() where pop is pop the first(a.k.a front) element in the queue. Both pop and top 
    methods should return the value of first element.
    
    Link: http://www.lintcode.com/en/problem/implement-queue-by-two-stacks/

    Example:
    	push(1)
		pop()     // return 1
		push(2)
		push(3)
		top()     // return 2
		pop()     // return 2

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/implement-queue-by-two-stacks.cpp
*/

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.emplace(element);
    }
    
    int pop() {
        // write your code here
        int element = top();
        stack2.pop();
        return element;
    }

    int top() {
        // write your code here
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.emplace(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }
};
