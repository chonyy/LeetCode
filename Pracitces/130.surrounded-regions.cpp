/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    int m, n;

    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m == 0) return;
        n = board[0].size();


        for(int i = 0; i < m; i ++) {
            dfs(board, i, n-1);
            dfs(board, i, 0);
        }

        for(int j = 0; j < n; j ++) {
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>> &board, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;

        if(board[i][j] == 'O')
            board[i][j] = '1';

        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
};
// @lc code=end

