/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
private:
    int m;
    int n;
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                bool alive = board[i][j] & 1;
                int lives = countLives(board, i, j);
                if(alive && lives >= 2 && lives <= 3) {
                    board[i][j] += 2;
                }
                if(!alive && lives == 3) {
                    board[i][j] += 2;
                }
            }
        }

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                board[i][j] >>= 1;
            }
        }
    }

    int countLives(vector<vector<int>>& board, int row, int col) {
        int count = 0;
        for(int i = max(0, row-1); i <= min(m-1, row+1); i ++) {
            for(int j = max(0, col-1); j <= min(n-1, col+1); j ++) {
                if(board[i][j] & 1) {
                    count ++;
                }
            }
        }
        cout << row << col << count << endl;
        return count - (board[row][col] & 1);
    }
};
// @lc code=end

