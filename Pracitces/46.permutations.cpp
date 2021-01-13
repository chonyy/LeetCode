/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    void p(vector<vector<int>> &res, vector<int> &per, vector<int> nums) {
        int n = nums.size();
        
        if(per.size() == n) {
            res.push_back(per);
            return;
        }

        for(int i = 0; i < n; i ++) {
            if(find(per.begin(), per.end(), nums[i]) != per.end())
                continue;
            per.push_back(nums[i]);
            p(res, per, nums);
            per.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> per;
        p(res, per, nums);
        return res;
    }
};
// @lc code=end

