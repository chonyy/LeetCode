/*
 * @lc app=leetcode id=285 lang=cpp
 *
 * [285] Inorder Successor in BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 /*
6
28
0479

 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root)
            return nullptr;

        if(root->val > p->val) {
            TreeNode* left = inorderSuccessor(root->left, p);
            return left ? left : root;
        }
        else {
            return inorderSuccessor(root->right, p);
        }
        return nullptr;
    }
};
// @lc code=end

