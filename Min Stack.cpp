/*
    Implement a stack with min() function, which will return the smallest number in the stack.
	It should support push, pop and min operation all in O(1) cost.

    Link: http://www.lintcode.com/en/problem/min-stack/

    Example: 
    	push(1)
		pop()   // return 1
		push(2)
		push(3)
		min()   // return 2
		push(1)
		min()   // return 1

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/min-stack.cpp
*/

class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        if (elements_.empty()) {
            elements_.emplace(0);
            stack_min_ = number;
        } else {
            elements_.emplace(number - stack_min_);
            if (number < stack_min_) {
                stack_min_ = number; // Update min.
            }
        }
    }

    int pop() {
        int diff = elements_.top();
        elements_.pop();
        if (diff < 0) {
            stack_min_ -= diff; // Restore previous min.
        }
        return stack_min_ + diff;
    }

    int min() {
        return stack_min_;
    }
private:
    stack<int> elements_;
    int stack_min_;
};
