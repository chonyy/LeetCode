/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int idx = 0;

        // add the non-overlaps
        while(idx < n && intervals[idx][1] < newInterval[0]) {
            res.push_back(intervals[idx]);
            idx ++;
        }

        // merge the intervals
        while(idx < n && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);

            idx ++;
        }
        
        res.push_back(newInterval);
        // merge the non-overlaps after the interval
        while(idx < n) {
            res.push_back(intervals[idx]);
            idx ++;
        }

        return res;
    }
};
// @lc code=end

