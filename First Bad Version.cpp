/*
    The code base version is an integer start from 1 to n. One day, someone committed a bad version in the code case, so it 
    caused this version and the following versions are all failed in the unit tests. Find the first bad version.
    You can call isBadVersion to help you determine which version is the first bad one. The details interface can be found 
    in the code's annotation part.

    Link: http://www.lintcode.com/en/problem/first-bad-version/

    Example: Given n = 5:
        isBadVersion(3) -> false
        isBadVersion(5) -> true
        isBadVersion(4) -> true
    Here we are 100% sure that the 4th version is the first bad version.

    Solution: None

    Source: http://www.jiuzhang.com/solutions/first-bad-version/#cpp
*/

/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int start = 1, end = n;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (SVNRepo::isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (SVNRepo::isBadVersion(start)) {
            return start;
        }
        return end;
    }
};
