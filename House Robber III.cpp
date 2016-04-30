/*
    The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, 
    each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It 
    will automatically contact the police if two directly-linked houses were broken into on the same night.

	Determine the maximum amount of money the thief can rob tonight without alerting the police.

    Link: http://www.lintcode.com/en/problem/house-robber-iii/

    Example: 
    	Example
		  3
		 / \
		2   3
		 \   \ 
		  3   1
		Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

		    3
		   / \
		  4   5
		 / \   \ 
		1   3   1
		Maximum amount of money the thief can rob = 4 + 5 = 9.

    Solution: None

    Source: None
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        // write your code here
        vector<int> result = findMax(root);
        return max(result[0], result[1]);
    }
    
private:
    // returns int[2] result. 
    // result[0] -- max value robbing current root; result[1] -- max value without robbing current root.
    vector<int> findMax(TreeNode* root) {
        vector<int> returnValue = {0, 0};
        if (root == nullptr) {
            return returnValue;
        }
        vector<int> left = findMax(root->left);
        vector<int> right = findMax(root->right);
        int result0 = root->val + left[1] + right[1];  					    // rob current root
        int result1 = max(left[0], left[1]) + max(right[0], right[1]);  	// not rob current root
        returnValue[0] = result0;
        returnValue[1] = result1;
        return returnValue;
    }
};