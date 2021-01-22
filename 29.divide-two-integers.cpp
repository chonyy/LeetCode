/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) 
            return INT_MAX;
        if(dividend == INT_MIN) {
            if(divisor == -1) 
                return INT_MAX;
            else if(divisor == 1)
                return INT_MIN;
        }

        long divd = (long)dividend;
        long divs = (long)divisor;

        int sign = 1;

        if(divd < 0) {
            divd = -divd;
            sign = -sign;
        }
        if(divs < 0) {
            divs = -divs;
            sign = -sign;
        }

        int res = 0;

        while(divd >= divs) {
            int shift = 0;
            while(divd >= divs << shift) {
                shift ++;
            }
            res += (1<<(shift-1));
            divd -= (divs << (shift-1));
        }

        return sign * res;
    }
};
// @lc code=end

