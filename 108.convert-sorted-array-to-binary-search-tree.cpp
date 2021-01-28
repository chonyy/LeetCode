/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        return dfs(nums, start, end);
    }

    TreeNode* dfs(vector<int> &nums, int start, int end) {
        if(start > end) 
            return nullptr;

        int mid = start + (end - start) / 2;
        cout << mid << endl;
        int value = nums[mid];
        cout << value << endl;

        TreeNode* root = new TreeNode(value);
        root->left = dfs(nums, start, mid-1);
        root->right = dfs(nums, mid+1, end);

        return root;
    }
};
// @lc code=end

