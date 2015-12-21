/*
    Singleton is a most widely used design pattern. If a class has and only has one instance at every moment, 
    we call this design as singleton. For example, for class Mouse (not a animal mouse), we should design it in singleton.
	You job is to implement a getInstance method for given class, return the same instance of this class every time you 
	call this method.
    
    Link: http://www.lintcode.com/en/problem/singleton/

    Example: 
    	A a = A.getInstance();
		A b = A.getInstance();

    Solution: Only implement Thread-safe version

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/singleton.cpp
*/

class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // C++ 11 thread-safe local-static-initialization.
        static Solution *instance = new Solution();

        return instance;
    }

    // Noncopyable.
    Solution(const Solution&) = delete;
    Solution& operator=(const Solution&) = delete;

private:
    Solution() {}
    ~Solution() {}
};