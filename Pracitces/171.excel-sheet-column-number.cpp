/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;

        for(char c: s) {
            int num = c - 'A' + 1;

            sum = sum * 26 + num;
        }
        return sum;
    }
};
// @lc code=end

