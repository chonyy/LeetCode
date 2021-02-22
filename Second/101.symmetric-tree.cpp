/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left, root->right);
    }

    bool check(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return true;
        if(!r1 && r2) return false;
        if(r1 && !r2) return false;

        bool subtreeSymmetric = check(r1->right, r2->left) && check(r1->left, r2->right);

        return((r1->val == r2->val) && subtreeSymmetric);
    }
};
// @lc code=end

