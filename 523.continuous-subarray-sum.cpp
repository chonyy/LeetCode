/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m{{0 , -1}};
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i ++) {
            sum += nums[i];
            if(k) sum %= k;
            if(m.count(sum)) {
                if(i - m[sum] > 1)
                    return true;
            }
            else {
                m[sum] = i;
            }
        }

        return false;
    }
};
// @lc code=end

