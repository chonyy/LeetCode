/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
class Solution {
public:
    int row;
    int col;
    int closedIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int res = 0;

        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(i == 0 || j == 0 || i == row-1 || j == col-1)
                    fill(grid, i, j);
            }
        }

        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(grid[i][j] == 0) {
                    res ++;
                    fill(grid, i, j);
                }
            }
        }

        return res;
    }

    void fill(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= row || j < 0 || j >= col)
            return;
        if(grid[i][j])
            return;

        grid[i][j] = 1;

        fill(grid, i+1, j);
        fill(grid, i-1, j);
        fill(grid, i, j+1);
        fill(grid, i, j-1);
    }
};
// @lc code=end

