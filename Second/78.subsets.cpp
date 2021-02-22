/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(0, res, cur, nums);
        return res;
    }

    void helper(int idx, vector<vector<int>>& res, vector<int>& cur, vector<int>& nums) {
        res.push_back(cur);

        if(idx == nums.size())
            return;

        for(int i = idx; i < nums.size(); i ++) {
            cur.push_back(nums[i]);
            helper(i+1, res, cur, nums);
            cur.pop_back();
        }
    }
};
// @lc code=end

