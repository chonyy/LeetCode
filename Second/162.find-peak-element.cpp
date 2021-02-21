/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;

        for(int i = 1; i < n; i ++) {
            if(nums[i] < nums[i-1])
                return i-1;
        }

        return n-1;
    }
};
// @lc code=end

