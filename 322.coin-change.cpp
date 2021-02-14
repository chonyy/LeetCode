/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        dp[0] = 0;

        for(int i = 1; i <= amount; i ++) {
            int localMin = amount+1;
            int curVal = i;
            for(int coin : coins) {
                if(coin <= curVal) {
                    localMin = min(localMin, dp[i-coin] + 1);
                }
            }
            dp[i] = localMin;
        }

        return dp[amount] <= amount ? dp[amount] : -1;
    }
};
// @lc code=end

