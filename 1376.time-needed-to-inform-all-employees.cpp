/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> children;
    int dfs(int headId, vector<int>& informTime) {
        int time = 0;
        for(int child : children[headId]) {
            time = max(time, dfs(child, informTime));
        }
        return informTime[headId] + time;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        children.resize(n);

        for(int i = 0; i < n; i ++) {
            if(manager[i] != -1)
                children[manager[i]].push_back(i);
        }

        return dfs(headID, informTime);
    }
};
// @lc code=end

