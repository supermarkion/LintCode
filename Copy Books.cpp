/*
    Given an array A of integer with size of n( means n books and number of pages of each book)
    and k people to copy the book. You must distribute the continuous id books to one people to
    copy. (You can give book A[1],A[2] to one people, but you cannot give book A[1], A[3] to one
    people, because book A[1] and A[3] is not continuous.) Each person have can copy one page per
    minute. Return the number of smallest minutes need to copy all the books.

    Link: http://www.lintcode.com/en/problem/copy-books/
    Example: Given array A = [3,2,4], k = 2.
    Return 5( First person spends 5 minutes to copy book 1 and book 2 and second person spends
    4 minutes to copy book 3. )
    Solution: We apply binary search to find (guess) the accurate solution.
    Source: None
*/

class Solution {
public:

    bool search(const int mid, vector<int> &pages, const int k) {
        int people = 0;
        int sum = 0;
        for (int i = 0; i < pages.size(); ) {
            if (sum + pages[i] <= mid) {
                sum += pages[i];
                i++;
            } else if (pages[i] <= mid) {
                sum = 0;
                people++;
            } else {
                return false;
            }
        }
        if (sum != 0) {
            people++;
        }
        return people <= k;
    }
    
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        if (pages.size() == 0) {
            return 0;
        }
        int sum = 0;
        for (const auto& page : pages) {
            sum += page;
        }
        int min = sum / k;
        while (min <= sum) {
            int time = 0;
            int mid = min + (sum - min) / 2;
            if (search(mid, pages, k)) {
                sum = mid - 1;
            } else {
                min = min + 1;
            }
        }
        return min;
    }
};