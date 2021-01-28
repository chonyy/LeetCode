/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() - 1;
        int sum = 0;
        int buy = 0;
        int sell = 0;
        int i = 0;

        while(i < n) {
            while(i < n && prices[i] > prices[i+1]) {
                i ++;
            }
            buy = prices[i];
            cout << buy << endl;

            while(i < n && prices[i] <= prices[i+1]) {
                i ++;
            }
            sell = prices[i];

            sum += sell - buy;
            cout << sell << endl;
        }

        return sum;
    }
};
// @lc code=end

