/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int row = 0;
    int col = 0;
    int fresh = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int time = -1;

        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1)
                    fresh ++;
            }
        }

        if(fresh == 0)
            return 0;

        while(!q.empty()) {
            time ++;
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto rotten = q.front();
                q.pop();
                for(auto dir : dirs) {
                    int x = rotten.first + dir[0];
                    int y = rotten.second + dir[1];
                    rot(grid, x, y);
                }
            }
        }

        return fresh > 0 ? -1 : time;
    }

    void rot(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= row || j < 0 || j >= col)
            return;
        if(grid[i][j] == 0 || grid[i][j] == 2)
            return;

        cout << i << j << endl;

        // Rot it!
        fresh --;
        grid[i][j] = 2;

        // Add to rotten
        q.push({i, j});
    }
};
// @lc code=end

