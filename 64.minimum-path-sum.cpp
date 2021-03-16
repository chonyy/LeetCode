/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int cols = grid[0].size();

        vector<int> cur(cols, grid[0][0]);
        for(int i = 1; i < cols; i ++) {
            cur[i] = cur[i-1] + grid[0][i];
        }

        for(int i = 1; i < rows; i ++) {
            cur[0] += grid[i][0];
            for(int j = 1; j < cols; j ++) {
                cur[j] = min(cur[j-1], cur[j]) + grid[i][j];
            }
        }

        return cur[cols-1];
    }
};
// @lc code=end

