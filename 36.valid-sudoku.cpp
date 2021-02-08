/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    int m;
    int n;
    bool usedRow[9][9] = {0};
    bool usedCol[9][9] = {0};
    bool usedBox[9][9] = {0};
    bool isValidSudoku(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(board[i][j] != '.') {
                    if(!check(board, i, j))
                        return false;
                }
            }
        }
        return true;
    }

    bool check(vector<vector<char>>& board, int row, int col) {
        int num = board[row][col] - '0' - 1;
        if(usedRow[row][num])
            return false;
        if(usedCol[col][num])
            return false;

        cout << row << endl;
        cout << col << endl << endl;
        if(usedBox[(row/3*3)+(col/3)][num])
            return false;

        usedRow[row][num] = true;
        usedCol[col][num] = true;
        usedBox[(row/3*3)+(col/3)][num] = true;

        return true;
    }
};
// @lc code=end

