/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool direction = true;

        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            vector<int> curLevel;
            int size = q.size();

            for(int i = 0; i < size; i ++) {
                TreeNode *curNode = q.front();
                q.pop();

                curLevel.push_back(curNode->val);

                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
            }

            if(!direction)
                reverse(curLevel.begin(), curLevel.end());

            res.push_back(curLevel);
            direction = !direction;
        }
        return res;
    }
};
// @lc code=end

