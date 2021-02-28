/*
 * @lc app=leetcode id=286 lang=cpp
 *
 * [286] Walls and Gates
 */

// @lc code=start
class Solution {
public:
    int row;
    int col;
    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size();
        int col = rooms[0].size();

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        queue<pair<int, int>> q;
        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(auto dir : directions) {
                int curRow = cur.first + dir[0];
                int curCol = cur.second + dir[1];
                if(curRow < 0 || curRow >= row || curCol < 0 || curCol >= col)
                    continue;
                if(rooms[curRow][curCol] != INT_MAX)
                    continue;
                rooms[curRow][curCol] = rooms[cur.first][cur.second] + 1;
                q.push({curRow, curCol});
            }
        }
    }
};
// @lc code=end

