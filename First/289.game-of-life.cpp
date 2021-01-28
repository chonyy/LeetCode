/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
public:
    int m;
    int n;

    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                int cur = board[i][j];
                int neighbors = live(board, i , j);
                if(cur == 1 && neighbors >= 2 && neighbors <= 3) {
                    board[i][j] = 3;
                }
                if(cur == 0 && neighbors == 3)
                    board[i][j] = 2;
            }
        }

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                board[i][j] >>= 1;
            }
        }
    }

    int live(vector<vector<int>> &board, int row, int col) {
        int count = 0;

        for(int i = max(0, row-1); i <= min(m-1, row+1); i ++) {
            for(int j = max(0, col-1); j <= min(n-1, col+1); j ++) {
                count += board[i][j] & 1;
            }
        }

        count -= board[row][col];
        return count;
    }
};
// @lc code=end

