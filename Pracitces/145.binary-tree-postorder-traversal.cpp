/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        deque<int> res;
        stack<TreeNode*> s;

        if(!root) return {};

        s.push(root);


        while(!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            res.push_front(cur->val);
            if(cur->left) 
                s.push(cur->left);
            if(cur->right)
                s.push(cur->right);
        }

        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end

