/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, bool> visited;
    int n;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        n = isConnected.size();
        for(int i = 0; i < n; i ++) {
            if(!visited[i]) {
                visited[i] = true;
                travel(isConnected, i);
                res ++;
            }
        }

        return res;
    }

    void travel(vector<vector<int>>& isConnected, int i) {
        for(int j = 0; j < n; j ++) {
            if(isConnected[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                travel(isConnected, j);
            }
        }
    }
};
// @lc code=end

