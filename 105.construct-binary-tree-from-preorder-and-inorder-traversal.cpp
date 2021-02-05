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
        int n = preorder.size();
        return helper(0, 0, n-1, preorder, inorder);
    }

    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int> &inorder) {
        if(inStart > inEnd || preStart > preorder.size() - 1)
            return nullptr;

        int val = preorder[preStart];
        TreeNode *root = new TreeNode(val);

        int inIdx;
        for(int i = inStart; i <= inEnd; i ++) {
            if(inorder[i] == val) {
                inIdx = i;
                break;
            }
        }

        root->left = helper(preStart + 1, inStart, inIdx-1, preorder, inorder);
        root->right = helper(preStart + inIdx - inStart + 1, inIdx + 1, inEnd, preorder, inorder);

        return root;
    }
};
// @lc code=end


pre: [3, 9, 1, 20,15,7]
in: [1,9,3,15,20,7]