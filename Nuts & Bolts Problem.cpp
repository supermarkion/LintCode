/*
    Given a set of n nuts of different sizes and n bolts of different sizes. There is a one-one
    mapping between nuts and bolts. Comparison of a nut to another nut or a bolt to another bolt
    is not allowed. It means nut can only be compared with bolt and bolt can only be compared with
    nut to see which one is bigger/smaller. We will give you a compare function to compare nut with bolt.
    
    Link: http://www.lintcode.com/en/problem/nuts-bolts-problem/
    
    Example: Given nuts = ['ab','bc','dd','gg'], bolts = ['AB','GG', 'DD', 'BC'].
    Your code should find the matching bolts and nuts. one of the possible return:
	nuts = ['ab','bc','dd','gg'], bolts = ['AB','BC','DD','GG'].
	we will tell you the match compare function. If we give you another compare function.
	the possible return is the following:
	nuts = ['ab','bc','dd','gg'], bolts = ['BC','AA','DD','GG'].
	So you must use the compare function that we give to do the sorting.
	The order of the nuts or bolts does not matter. You just need to find the matching bolt for each nut.
    
    Solution: Perform Quick Sort, consider of its randomly pivot selection, the number
    of solution is big.
    
    Source:
        https://github.com/kamyu104/LintCode/blob/master/C++/nuts-bolts-problem.cpp
        http://www.1point3acres.com/bbs/thread-138798-1-1.html
*/

 /**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    
    typedef enum { SMALLER = -1, EQUAL = 0,
                   BIGGER = 1, REVERSE = 2 } CompareResult;

    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        quickSort(nuts, bolts, 0, nuts.size() - 1, compare);
    }
    
    void quickSort(vector<string> &nuts, vector<string> &bolts, int left, int right,
                    Comparator compare) {
        if (left < right) {
            // perform quick sort by select a pivot
            default_random_engine gen((random_device())());
            
            /* uniform_int_distribution: Random number distribution that produces
            integer values according to a uniform discrete distribution, which is
            described by the following probability mass function:
            This distribution produces random integers in a range [a,b]*/
            uniform_int_distribution<int> dis(left, right);
            int pivot = dis(gen);
            
            // Use the pivot bolt to make a partition of nuts,
            // Then we could know the index where the pivot pair should be in sorted order
            pivot = partition(nuts, left, right, bolts[pivot], compare);
            
            // Use the nut in the pivot bolt to make a partition of bolts
            partition(bolts, left, right, nuts[pivot], compare);
            
            // NOt, both nuts and bolts are partitioned by the oivot nut-bolt pair,
            // then pivot nut-bolt pair is also in the correct index of the sorted
            // order. Recursively do the same thing in the left and right side of pivot.
            quickSort(nuts, bolts, left, pivot - 1, compare);
            quickSort(nuts, bolts, pivot + 1, right, compare);
        }
    }
    
    int partition(vector<string>& arr, int left, int right, const string& pivot,
                Comparator& compare) {
        for (int i = left; i < right; ) {
            if (compare.cmp(arr[i], pivot) == SMALLER ||  // Smaller.
                (compare.cmp(arr[i], pivot) == REVERSE &&
                 compare.cmp(pivot, arr[i]) == BIGGER)) {
                swap(arr[left++], arr[i++]);
            } else if (compare.cmp(arr[i], pivot) == BIGGER ||  // Bigger.
                      (compare.cmp(arr[i], pivot) == REVERSE &&
                       compare.cmp(pivot, arr[i]) == SMALLER)) {
                ++i;
            } else {  // Equal.
                swap(arr[i], arr[right]);
            }
        }
        // Put the pivot to the partition index.
        swap(arr[left], arr[right]);

        // Return the partition index of an array.
        return left;
    }            
    
};