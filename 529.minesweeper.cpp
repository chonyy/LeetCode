/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int rows = board.size();
        if(rows == 0)
            return board;
        int cols = board[0].size();

        queue<pair<int, int>> q;
        q.push({click[0], click[1]});
        vector<vector<int>> dirs = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(board[row][col] == 'M')
                board[row][col] = 'X';
            else {
                // calculate mines
                int mines = 0;
                for(auto dir : dirs) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols)
                        continue;
                    if(board[newRow][newCol] == 'M' || board[newRow][newCol] == 'X')
                        mines ++;
                }
                if(mines > 0)
                    board[row][col] = mines + '0';
                else {
                    // reveal the adjacent
                    board[row][col] = 'B';
                    for(auto dir : dirs) {
                        int newRow = row + dir[0];
                        int newCol = col + dir[1];
                        if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols)
                            continue;
                        if(board[newRow][newCol] == 'E') {
                            q.push({newRow, newCol});
                            board[newRow][newCol] = 'B';
                        }
                    }
                }
            }
        }

        return board;
    }
};
// @lc code=end

