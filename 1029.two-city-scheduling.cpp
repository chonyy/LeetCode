/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

// @lc code=start
class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] - v1[1] < v2[0] - v2[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        sort(costs.begin(), costs.end(), compare);

        int sum = 0;
        for(int i = 0; i < n; i ++) {
            sum += costs[i][0] + (costs[i+n][1]);
        }
        return sum;
    }
};
// @lc code=end

