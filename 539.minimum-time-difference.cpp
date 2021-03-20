/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 */

// @lc code=start
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> time(1440, false);
        for(string point : timePoints) {
            int minutee = minute(point);
            if(time[minutee])
                return 0;
            time[minutee] = true;
        }

        int curMin = INT_MAX;
        int prev = 0;
        int last = 0;
        int first = INT_MAX;
        // find the min
        for(int i = 0; i < 1440; i ++) {
            if(time[i]) {
                if(first == INT_MAX) {
                    prev = i;
                    first = i;
                    continue;
                }
                curMin = min(curMin, i - prev);
                prev = i;
                last = i;
            }
        }

        return min(curMin, 1440 - last + first);
    }

    int minute(string time) {
        int hh = stoi(time.substr(0, 2));
        int mm = stoi(time.substr(3, 2));

        return hh * 60 + mm;
    }
};
// @lc code=end

