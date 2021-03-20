/*
 * @lc app=leetcode id=256 lang=cpp
 *
 * [256] Paint House
 */

// @lc code=start
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int r = 0, b = 0, g = 0;

        for(int i = 0; i < costs.size(); i ++) {
            int rr= r, bb = b, gg = g;
            r = costs[i][0] + min(bb, gg);
            b = costs[i][1] + min(rr, gg);
            g = costs[i][2] + min(rr, bb);
        }

        return min(r, min(g, b));
    }
};
// @lc code=end

