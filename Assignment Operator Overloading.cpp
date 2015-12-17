/*
    Implement an assignment operator overloading method.
	Make sure that:
		The new data can be copied correctly
		The old data can be deleted / free correctly.
		We can assign like A = B = C
    Link: http://www.lintcode.com/en/problem/assignment-operator-overloading-c-only/#
    Example: 
		If we assign like A = B, the data in A should be deleted, and A can have a copy of data from B.
		If we assign like A = B = C, both A and B should have a copy of data from C.
    Solution: None
    Source: None
*/

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        if (this != &object) {
            // 1: Allocate new memory and copy the elements.
            char *new_pData = nullptr;
            if (object.m_pData != nullptr) {
                size_t count = strlen(object.m_pData);
                new_pData = new char[count];
                copy(object.m_pData, object.m_pData + count, new_pData);
            }

            // 2: Deallocate old memory.
            if (m_pData != nullptr) {
                delete[] m_pData;
            }

            // 3: Assign the new memory to the object.
            m_pData = new_pData;;
        }
        return *this;
    }
};
