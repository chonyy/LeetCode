/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
private:
    int row;
    int col;

public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(check(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

    bool check(vector<vector<char>> &board, int i, int j, string word, int idx) {
        if(idx >= word.size()) {
            return true;
        }
        if(i < 0 || i > row-1 || j < 0 || j > col-1 || board[i][j] == '#')
            return false;
        if(board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool ans = check(board, i-1, j, word, idx+1) ||
        check(board, i+1, j, word, idx+1) ||
        check(board, i, j+1, word, idx+1) ||
        check(board, i, j-1, word, idx+1);
        board[i][j] = temp;

        return ans;
    }
};
// @lc code=end

