/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 */

// @lc code=start
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end());

        pq.push(intervals[0][1]);
        int n = intervals.size();

        for(int i = 1; i < n; i ++) {
            int earliest = pq.top();
            auto cur = intervals[i];

            // no overlap
            if(cur[0] >= earliest) {
                pq.pop();
                pq.push(cur[1]);
            }
            else {
                pq.push(cur[1]);
            }
        }

        return pq.size();
    }
};
// @lc code=end

