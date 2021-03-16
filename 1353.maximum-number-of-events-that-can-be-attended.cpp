/*
 * @lc app=leetcode id=1353 lang=cpp
 *
 * [1353] Maximum Number of Events That Can Be Attended
 */

// @lc code=start
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<>> pq;
        sort(events.begin(), events.end());

        int n = events.size();
        int i = 0;
        int res = 0;

        for(int d = 1; d < 100001; d ++) {
            // Jump to the meeting
            if(pq.empty() && i < n) {
                d = events[i][0];
            }

            // Remove the meetings that ended
            while(!pq.empty() && pq.top() < d) {
                pq.pop();
            }

            // Add the newly available meetings
            while(i < n && events[i][0] == d) {
                pq.push(events[i++][1]);
            }

            // attend the meeting
            if(!pq.empty()) {
                res ++;
                pq.pop();
            }
        }
        return res;
    }
};
// @lc code=end

