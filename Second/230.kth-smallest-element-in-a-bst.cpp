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
    int res;
    int nodes = 0;

    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return res;
    }

    void helper(TreeNode* root, int k) {
        if(!root)
            return;
        helper(root->left, k);
        nodes ++;
        if(nodes == k)
            res = root->val;
        helper(root->right, k);
    }
};
// @lc code=end

