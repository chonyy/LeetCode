/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp{0};

        for(int i = 1; i <= n; i ++) {
            int localMin = INT_MAX;
            for(int j = 1; j*j <= i ; j ++) {
                int cal = i - j*j;
                localMin = min(localMin, dp[cal] + 1);
            }
            dp.push_back(localMin);
        }

        return dp[n];
    }
};
// @lc code=end

