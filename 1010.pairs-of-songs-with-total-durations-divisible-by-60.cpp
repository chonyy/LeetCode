/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */

// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> m;
        int res = 0;

        for(int t : time) {
            if(t % 60 == 0)
                res += m[0];
            else {
                res += m[60 - (t % 60)];
            }
            m[t%60] ++;
        }

        return res;
    }
};
// @lc code=end

