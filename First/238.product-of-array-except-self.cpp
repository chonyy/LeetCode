/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int fromBegin = 1;
        int fromBack = 1;

        vector<int> res(n, 1);

        for(int i = 0; i < n; i ++) {
            if(i > 0) {
                fromBegin *= nums[i-1];
            }
            res[i] *= fromBegin;
        }

        for(int i = n-1; i >= 0; i --) {
            if(i < n-1) {
                fromBack *= nums[i+1];
            }
            res[i] *= fromBack;
        }
        return res;
    }
};
// @lc code=end

