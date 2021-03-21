/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    int n;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size();
        return build(inorder, postorder, 0, n-1, n-1);        
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postEnd) {
        if(inStart > inEnd || postEnd < 0 || postEnd >= n)
            return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        int inorderPos;

        // Search for the rootVal in InOrder
        for(int i = inStart; i <= inEnd; i ++) {
            if(inorder[i] == rootVal) {
                inorderPos = i;
                break;
            }
        }

        int rightNum = inEnd - inorderPos;
        root->left = build(inorder, postorder, inStart, inorderPos - 1, postEnd - rightNum - 1);
        root->right = build(inorder, postorder, inorderPos + 1, inEnd, postEnd - 1);

        return root;
    }
};
// @lc code=end

