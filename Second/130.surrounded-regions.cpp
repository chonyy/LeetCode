/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    int row;
    int col;
    void solve(vector<vector<char>>& board) {
        row = board.size();
        if(row == 0)
            return;
        col = board[0].size();


        for(int i = 0 ; i < row; i ++) {
            dfs(board, i, 0);
            dfs(board, i, col-1);
        }

        for(int i = 0; i < col; i ++) {
            dfs(board, 0, i);
            dfs(board, row-1, i);
        }

        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i < 0 || i >= row || j < 0 || j >= col || board[i][j] != 'O')
            return;

        if(board[i][j] == 'O')
            board[i][j] = '1';

        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
};
// @lc code=end

