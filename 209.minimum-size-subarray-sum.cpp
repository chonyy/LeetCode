/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int minLen = INT_MAX;
        int sum = 0;

        while(r < n) {
            // make the sum larger or equal than target
            while(r < n && sum < target) {
                sum += nums[r];
                r ++;
            }

            // record the length until the sum is smaller
            while(l < n && sum >= target) {
                minLen = min(minLen, r - l);
                sum -= nums[l];
                l ++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};
// @lc code=end

1, 2, 1, 4, 3, 1, 1
target = 7