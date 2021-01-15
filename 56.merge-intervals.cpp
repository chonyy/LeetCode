/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    static bool compareInterval(vector<int> &i1, vector<int> &i2) {
        return(i1[0] < i2[0]);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), compareInterval);

        res.push_back(intervals[0]);

        for(int i = 1; i < n; i ++) {
            if(intervals[i][0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
// @lc code=end

