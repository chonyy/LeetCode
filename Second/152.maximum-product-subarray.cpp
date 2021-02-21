/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = nums[0];
        int n = nums.size();
        if(nums.size() == 1)
            return first;

        int curMax = first, curMin = first;
        int ans = first;

        for(int i = 1; i < n; i ++) {
            if(nums[i] < 0) {
                swap(curMax, curMin);
            }

            curMax = max(nums[i], curMax * nums[i]);
            curMin = min(nums[i], curMin * nums[i]);

            ans = max(ans, curMax);
        }
        return ans;
    }
};
// @lc code=end

