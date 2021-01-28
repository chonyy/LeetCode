/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        stack<TreeNode*> stk;

        if(!root) return res;

        while(cur || !stk.empty()) {
            while(cur) {
                res.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top();
            stk.pop();
            cur = cur->right;
        }
        return res;
    }
};
// @lc code=end

