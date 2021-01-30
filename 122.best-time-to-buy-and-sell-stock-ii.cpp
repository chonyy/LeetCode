/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int n = prices.size() - 1;
        int sum = 0;

        while(i < n) {
            while(i < n && prices[i] >= prices[i+1])
                i ++;

            int buy = prices[i];

            while(i < n && prices[i] < prices[i+1])
                i ++;

            int sell = prices[i];

            sum += sell - buy;
        }

        return sum;
    }
};
// @lc code=end

