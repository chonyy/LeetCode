/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        for(int i = 0; i < n; i ++) {
            if(nums[i] == 0)
                swap(nums[i], nums[cur++]);
        }
        for(int i = 0; i < n; i ++) {
            if(nums[i] == 1)
                swap(nums[i], nums[cur++]);
        }
    }
};
// @lc code=end

