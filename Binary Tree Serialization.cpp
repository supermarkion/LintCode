/*
    Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is 
    called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.
	There is no limit of how you deserialize or serialize a binary tree, you only need to make sure you can serialize a 
	binary tree to a string and deserialize this string to the original structure.
    
    Link: http://www.lintcode.com/en/problem/binary-tree-serialization/

    Example: An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote the following structure:
		  3
		 / \
		9  20
		  /  \
		 15   7

    Solution: In this method, we have two sub-methods, which include serialize & deserialize. The serialize method is easy
	to understand and implement by perform pre-order traversal, and add traversal string into a total string. For
	the deserialize method, we should divide total string into several tokens, and if is "#", means empty node,
	then construct a node by current vale, then get its left node and right nodes.
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/binary-tree-serialization.cpp
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        string output;
        serializeHelper(root, &output);
        return output;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        TreeNode *root = nullptr;
        int start = 0;
        return deserializeHelper(data, &start);
    }

private:
    bool getNumber(const string &data, int *start, int *num) {
        int sign = 1;
        if (data[*start] == '#') {
            *start += 2;  // Skip "# ".
            return false;
        } else if (data[*start] == '-') {
            sign = -1;
            ++(*start);
        }

        for (*num = 0; isdigit(data[*start]); ++(*start)) {
            *num = *num * 10 + data[*start] - '0';
        }
        *num *= sign;
        ++(*start);  // Skip " ".

        return true;
    }

    void serializeHelper(const TreeNode *root, string *prev) {
        if (!root)  {
            prev->append("# ");
        } else {
            prev->append(to_string(root->val).append(" "));
            serializeHelper(root->left, prev);
            serializeHelper(root->right, prev);
        }
    }

    TreeNode *deserializeHelper(const string& data, int *start) {
        int num;
        if (!getNumber(data, start, &num)) {
            return nullptr;
        } else {
            TreeNode *root = new TreeNode(num);
            root->left = deserializeHelper(data, start);
            root->right = deserializeHelper(data, start);
            return root;
        }
    }

};
