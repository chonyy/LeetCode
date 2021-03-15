/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int> stk;
        vector<int> res(n, 0);

        for(int i = 0; i < n; i ++) {
            while(!stk.empty() && T[i] > T[stk.top()]) {
                int idx = stk.top();
                stk.pop();
                res[idx] = i - idx;
            }
            stk.push(i);
        }

        return res;
    }
};
// @lc code=end

