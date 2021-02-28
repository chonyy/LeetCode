/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        helper(res, root, to_delete, true);
        return res;
    }

    TreeNode* helper(vector<TreeNode*>& res, TreeNode* node, vector<int>& toDel, bool isRoot) {
        if(!node)
            return nullptr;

        auto it = find(toDel.begin(), toDel.end(), node->val);
        bool deleted = it != toDel.end();

        if(isRoot && !deleted) {
            cout << node->val << endl;
            res.push_back(node);
        }

        node->left = helper(res, node->left, toDel, deleted);
        node->right = helper(res, node->right, toDel, deleted);

        return deleted ? nullptr : node;
    }
};
// @lc code=end

