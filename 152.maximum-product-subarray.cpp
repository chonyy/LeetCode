/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int res = nums[0];

        int curMax = res;
        int curMin = res;

        for(int i = 1; i < n; i ++) {
            int cur = nums[i];

            if(cur < 0)
                swap(curMax, curMin);

            curMax = max(cur, curMax * cur);
            curMin = min(cur, curMin * cur);

            res = max(curMax, res);
            cout << res << endl;
        }

        return res;
    }
};
// @lc code=end

