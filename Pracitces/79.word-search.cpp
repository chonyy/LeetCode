/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    int m;
    int n;

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, string word, int wordIdx, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n || word[wordIdx] != board[i][j]) return false;
        if(wordIdx == word.length() - 1) return true;

        char cur = board[i][j];
        board[i][j] = '*';
        bool searchNext = dfs(board, word, wordIdx+1, i+1, j) || 
        dfs(board, word, wordIdx+1, i, j+1) ||
        dfs(board, word, wordIdx+1, i-1, j) ||
        dfs(board, word, wordIdx+1, i, j-1);
        board[i][j] = cur;

        return searchNext;
    }
};
// @lc code=end

