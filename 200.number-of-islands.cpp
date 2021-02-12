/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int row;
    int col;
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int count = 0;

        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(grid[i][j] == '1') {
                    walk(grid, i, j);
                    count ++;
                }
            }
        }
        return count;
    }

    void walk(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= row || j < 0 || j >= col)
            return;
        if(grid[i][j] == '0' || grid[i][j] == 'x')
            return;

        grid[i][j] = 'x';

        walk(grid, i+1, j);
        walk(grid, i-1, j);
        walk(grid, i, j+1);
        walk(grid, i, j-1);
    }
};
// @lc code=end

