/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int number = 0;
    int count = 0;

    int kthSmallest(TreeNode* root, int k) {
        count = k;
        helper(root);
        return number;
    }

    void helper(TreeNode *node) {
        if(node->left) helper(node->left);

        count --;
        if(count == 0) {
            number = node->val;
            return;
        }
        if(node->right) helper(node->right);
    }
};
// @lc code=end

