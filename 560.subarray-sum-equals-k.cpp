/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prevSums;
        prevSums[0] = 1;
        int sum = 0;
        int count = 0;

        // 3 4 7
        for(int num : nums) {
            sum += num;
            count += prevSums[sum - k];
            prevSums[sum] ++;
        }

        return count;
    }
};
// @lc code=end

