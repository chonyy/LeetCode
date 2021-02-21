/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
    int row;
    int col;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(grid[i][j]) {
                    cout << i << j << endl; 
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= row || j < 0 || j >= col)
            return 0;

        if(grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;

        return 1 + 
        dfs(grid, i+1, j)+
        dfs(grid, i-1, j)+
        dfs(grid, i, j+1)+
        dfs(grid, i, j-1);
    }
};
// @lc code=end

