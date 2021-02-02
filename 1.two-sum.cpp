/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i ++) {
            if(m.find(nums[i]) == m.end()) {
                m[target - nums[i]] = i;
            }
            else {
                res.push_back(m[nums[i]]);
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

