/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int globalMax = 0;

        for(int i = 0; i < n; i ++) {
            int localMax = 1;
            for(int j = 0; j < i; j ++) {
                if(nums[j] < nums[i])
                    localMax = max(localMax, dp[j] + 1);
            }
            dp[i] = localMax;
            globalMax = max(localMax, globalMax);
        }

        for(int i : dp) {
            cout << i << " ";
        }

        return globalMax;
    }
};
// @lc code=end

