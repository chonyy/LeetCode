/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;

        while(n >= 5) {
            int temp = n / 5;
            count += temp;
            n = temp;
        }

        return count;
    }
};
// @lc code=end

