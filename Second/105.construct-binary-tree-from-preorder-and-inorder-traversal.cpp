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
    int n;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = inorder.size();
        return build(0,0, n-1, preorder, inorder);
    }

    TreeNode* build(int preStart, int inStart, int inEnd, vector<int>& preOrder, vector<int>& inOrder) {
        if(preStart < 0 || preStart >= n || inStart > inEnd)
            return nullptr;

        int val = preOrder[preStart];
        TreeNode* root = new TreeNode(val);
        int inIdx;

        for(int i = inStart; i <= inEnd; i ++) {
            if(inOrder[i] == val) {
                inIdx = i;
                break;
            }
        }

        root->left = build(preStart+1, inStart, inIdx-1, preOrder, inOrder);
        root->right = build(preStart + (inIdx-inStart+1), inIdx+1, inEnd, preOrder, inOrder);

        return root;
    }
};
// @lc code=end