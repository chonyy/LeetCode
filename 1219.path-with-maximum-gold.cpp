/*
 * @lc app=leetcode id=1219 lang=cpp
 *
 * [1219] Path with Maximum Gold
 */

// @lc code=start
class Solution {
public:
    int row;
    int col;
    int getMaximumGold(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int curMax = 0;

        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(grid[i][j]) {
                    curMax = max(curMax, solve(grid, i, j));
                }
            }
        }

        return curMax;
    }

    int solve(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i == row || j < 0 || j == col) {
            return 0;
        }
        if(grid[i][j] == 0)
            return 0;

        int origin = grid[i][j];
        grid[i][j] = 0;

        int curMax = 0;
        curMax = max(curMax, solve(grid, i+1, j));
        curMax = max(curMax, solve(grid, i-1, j));
        curMax = max(curMax, solve(grid, i, j+1));
        curMax = max(curMax, solve(grid, i, j-1));

        grid[i][j] = origin;

        return curMax + origin;
    }
};
// @lc code=end

