/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;

        p(res, cur, nums);

        return res;
    }

    void p(vector<vector<int>> &res, vector<int> &cur, vector<int> nums) {
        int n = nums.size();

        if(cur.size() == n) {
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < n; i ++) {
            if(find(cur.begin(), cur.end(), nums[i]) != cur.end())
                continue;
            cur.push_back(nums[i]);
            p(res, cur, nums);
            cur.pop_back();
        }
    }
};
// @lc code=end

