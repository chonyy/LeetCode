/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(0, 0, inorder.size()-1, preorder, inorder);
    }

    TreeNode* dfs(int preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder) {
        if (preStart > preorder.size()-1 || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[preStart]);
        int inIndex = 0;
        for(int i = 0; i < inorder.size(); i ++) {
            if(inorder[i] == node->val)
                inIndex = i;
        }

        node->left = dfs(preStart+1, inStart, inIndex-1, preorder, inorder);
        node->right = dfs(preStart + inIndex - inStart + 1, inIndex+1, inEnd, preorder, inorder);
        return node;
    }
};
// @lc code=end

