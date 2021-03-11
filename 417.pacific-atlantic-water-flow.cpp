/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        rows = matrix.size();
        if(rows == 0)
            return res;

        cols = matrix[0].size();

        vector<vector<int>> pacificTouch(rows, vector<int>(cols, 0));
        vector<vector<int>> atlanticTouch(rows, vector<int>(cols, 0));

        queue<vector<int>> pq;
        queue<vector<int>> aq;

        // Pushing the border
        for(int i = 0; i < rows; i ++) {
            pq.push({i, 0});
            aq.push({i, cols-1});
            pacificTouch[i][0] = 1;
            atlanticTouch[i][cols-1] = 1;
        }
        for(int j = 0; j < cols; j ++) {
            pq.push({0, j});
            aq.push({rows-1, j});
            pacificTouch[0][j] = 1;
            atlanticTouch[rows-1][j] = 1;
        }

        bfs(matrix, pacificTouch, pq);
        bfs(matrix, atlanticTouch, aq);

        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(pacificTouch[i][j] && atlanticTouch[i][j])
                    res.push_back({i, j});
            }   
        }
        return res;
    }

    void bfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, queue<vector<int>>& q) {
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(auto dir : dirs) {
                int x = cur[0] + dir[0];
                int y = cur[1] + dir[1];
                if(x < 0 || x >= rows || y < 0 || y >= cols) {
                    continue;
                }
                if(visited[x][y] || matrix[x][y] < matrix[cur[0]][cur[1]]) {
                    continue;
                }

                visited[x][y] = 1;
                q.push({x, y});
            }
        }
    }
};
// @lc code=end

