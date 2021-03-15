/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution {
public:
    // buttom-up
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= coins.size(); i ++) {
            for(int j = 1; j <= amount; j ++) {
                int useCoin = j >= coins[i-1] ? dp[j - coins[i-1]] : 0;
                int dontUse = dp[j];
                dp[j] = useCoin + dontUse;
            }
        }

        return dp[amount];
    }

    // top-down
    // int count = 0;
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
    //     return backtrack(amount, coins, 0, dp);
    // }

    // int backtrack(int remain, vector<int>& coins, int idx, vector<vector<int>>& dp) {
    //     if(remain == 0) {
    //         return 1;
    //     }

    //     if(remain < 0 || idx == coins.size())
    //         return 0;

    //     if(dp[idx][remain] != -1)
    //         return dp[idx][remain];

    //     int useCoin = backtrack(remain-coins[idx], coins, idx, dp);
    //     int dontUse = backtrack(remain, coins, idx+1, dp);

    //     dp[idx][remain] = useCoin + dontUse;
    //     return useCoin + dontUse;
    // }
};
// @lc code=end

