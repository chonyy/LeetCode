/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> curRow(n, 1);

        for(int i = 1; i < m; i ++) {
            for(int j = 1; j < n; j ++) {
                curRow[j] += curRow[j-1];
            }
        }

        return curRow[n-1];
    }
};
// @lc code=end

