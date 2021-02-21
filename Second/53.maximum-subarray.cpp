/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0;
        int globalMax = INT_MIN;

        for(int num : nums) {
            curMax += num;
            cout << curMax << endl;
            globalMax = max(globalMax, curMax);
            curMax = max(curMax, 0);
        }

        return globalMax;
    }
};
// @lc code=end

