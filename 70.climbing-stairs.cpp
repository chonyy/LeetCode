/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(n);
        res[0] = 1;
        if(n > 1)
            res[1] = 2;
        for(int i = 2; i < n; i ++) {
            res[i] = res[i-1] + res[i-2];
        }
        return res[n-1];
    }
};
// @lc code=end

