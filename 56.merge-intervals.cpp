/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        for(int i = 1; i < n; i ++) {
            if(intervals[i][0] > intervals[i-1][1]) {
                res.push_back(intervals[i-1]);
            }
            else {
                intervals[i][0] = intervals[i-1][0];
                intervals[i][1] = max(intervals[i][1], intervals[i-1][1]);
            }
        }

        res.push_back(intervals[n-1]);

        return res;
    }
};
// @lc code=end

