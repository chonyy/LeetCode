/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Deletion Cost to Avoid Repeating Letters
 */

// @lc code=start
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size();
        int res = 0;
        int repeatTotal = 0;
        int repeatMax = 0;
        for(int i = 0; i < n; i ++) {
            if(i > 0 && s[i] != s[i-1]) {
                res += repeatTotal - repeatMax;
                repeatTotal = 0;
                repeatMax = 0;
            }
            repeatTotal += cost[i];
            repeatMax = max(repeatMax, cost[i]);
        }
        res += repeatTotal - repeatMax;

        return res;
    }
};
// @lc code=end

