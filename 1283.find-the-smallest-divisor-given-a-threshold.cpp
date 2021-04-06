/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
class Solution {
public:
    bool sum(int div, vector<int>& nums, int threshold) {
        int summ = 0;
        for(int num : nums) {
            summ += (num + div - 1) / div;
        }
        return summ <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e6;
        while(l < r) {
            int mid = l + (r-l) / 2;
            if(sum(mid, nums, threshold))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

