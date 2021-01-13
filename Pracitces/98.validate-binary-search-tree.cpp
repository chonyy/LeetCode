/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }

    bool helper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(root == nullptr) return true;

        if(minNode && root->val <= minNode->val) return false;
        if(maxNode && root->val >= maxNode->val) return false;

        return(helper(root->left, minNode, root) && helper(root->right, root, maxNode));
    }
};
// @lc code=end

