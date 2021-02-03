/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> count(n+1);
        int res = 0;

        for(int i = 2; i < n; i ++) {
            if(!count[i]) {
                res ++;
                for(int j = 1; j * i < n; j ++) {
                    count[j*i] = true;
                }
            }
        }

        return res;
    }
};
// @lc code=end

