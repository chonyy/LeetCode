/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);

        int n = intervals.size();

        for(int i = 1; i < n; i ++) {
            int prevEnd = res.back()[1];
            int newStart = intervals[i][0];
            int newEnd = intervals[i][1];
            if(prevEnd >= newStart) {
                if(newEnd > prevEnd)
                    res.back()[1] = intervals[i][1];
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end

